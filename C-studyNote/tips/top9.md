
# 一.数据流，重定向

## 1.1 数据流
**数据流**:就是流动的数据，数据从一个进程流出，流入另一个进程，除了标准输出，标准输入，标准错误外还有**其他形式的数据流**，如文件连接，网络连接。

进程含有：

- 正在运行的程序
- 堆和栈数据空间
- 记录数据流的方向

## 1.2 文件描述符

进程用**文件描述符表示数据流**， 是一个数字，代表一条数据流。把文件描述符和对应的数据流保存到描述符表中。这张表长这个样：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_1.png)

前三项一直不变：

- `0`: 标准输入
- `1`: 标准输出
- `2`: 标准错误

其他项要么空，要么是进程打开的数据流。

## 1.3 重定向
**重定向：替换数据流**， 标准输入/输出/错误在描述符表中的位置是固定的,但它们指向的数据流可以改变。也就是说,如果想重定向标准输出,只需要修改表 中1号描述符对应的数据流就行了。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_2.png)

>所有向标准输出发送数据的函数会先查看描述符表, 看1号描述符指向哪条数据流,然后再把数据写到这 条数据流中,printf()便是如此。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_3.png)

## 1.4 对文件描述符的操作

有如下相关函数：

- `fileno()`: 返回描述符号
- `dup2()`: 复制数据流

### 1.4.1 fileno()

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_4.png)

### 1.4.2 dup2()

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_5.png)

### 1.4.3 实例：rss源检索输出到文件中

还是上一章节的例子，只有一个rss源：

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <unistd.h>
	#include <stdlib.h>

	//定义一个通用的错误处理方法
	void error(char *msg){
	    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	    exit(1);        // exit(1)会立刻终止程序并把`退出状态`设为1
	}

	int main(int argc, char *argv[]) {
	    char *phrase = argv[1];
	    char *vars[] = {"RSS_FEED=http://rss.news.sohu.com/rss/guoji.xml", NULL};
	    //打开文件
	    FILE *f = fopen("output.txt", "w");
	    //判断打开文件是否成功
	    //如果不能以写的方式打开，则`f=0`
	    if (!f) {
	        error("文件output.txt打开失败");
	    }
	    
	    //fork进程
	    pid_t cf = fork();
	    //判断fork是否成功
	    if (cf == -1) {
	        error("fork进程失败");
	    }
	    
	    //这段代码会修改子进程，因为pid为0
	    if (!cf) {
	        //重定向,让1号描述符指向output.txt文件
	        if (dup2(fileno(f), 1) == -1) {
	            error("重定向失败");
	        }
	        //执行系统调用
	        int pid = execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars);
	        if (pid == -1) {
	            error("系统调用失败");
	        }
	    }
	    return 0;
	}


我们运行下代码：

	./rss sohu 
	cat output.txt

如果*幸运的话*，里面会看到内容，这里我故意放慢rssgossip.py运行， 加上了`time.sleep(3)`, 让它3s后才开始处理. 你会看到output.txt文件里面为空，等到3s过去后才会有值。

	➜  intoC git:(master) ✗ ./rss sohu    
	➜  intoC git:(master) ✗ cat output.txt
	➜  intoC git:(master) ✗ cat output.txt
	➜  intoC git:(master) ✗ cat output.txt
	➜  intoC git:(master) ✗ cat output.txt
	www.sohu.com

也就是说**rss程序启动独立进程运行rssgossip.py,而子进程一创建就会父进程没关系了，rssgossip.py还没有完成任务，rss就结束了，所以output.txt为空，也 就是说,操作系统必须提供一种方式,让你等待子进程完成任务。**


## 1.5 waitpid()函数
针对上面的问题，`waitpid()`函数会让子进程运行结束后才返回。我们在程序的最后面加上下面的代码：

	int pid_status;
	if (waitpid(cf, &pid_status, 0) == -1) {
        error("等待子进程时发生错误");
    }
    return 0;

然后在运行程序：

	➜  intoC git:(master) ✗ gcc rss.c -o rss
	➜  intoC git:(master) ✗ ./rss sohu         
	➜  intoC git:(master) ✗ cat output.txt 
	www.sohu.com

rss程序不是立即就退出的，而是等一会，等待rssgossip.py完成后再退出。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_6.png)

# 二.管道连接进程实现进程通信
书上的例子是**实时**读取生成的数据，还是上面的例子，rssgroup.py脚本加上-u，可以显示找到的url，如：

	export RSS_FEED=http://rss.news.sohu.com/rss/guoji.xml
	python rssgossip.py -u sohu  
	www.sohu.com
		http://www.sohu.com

在第三章[创建小工具:做一件事并把它做好](https://github.com/BeginMan/BookNotes/blob/master/C/Top3:创建小工具:做一件事并把它做好.md#2管道符), 学习了管道符，但是没有讲管道具体的原理是什么，很幸运，这一节涉及到了。

## 2.1 管道两侧的命令是父子关系

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_7.png)

如上的命令，可以解析如下图：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_8.png)

在C中有`pipe()`设置管道

## 2.2 pipe()函数建立管道
用`pipe()`连接子进程的标准输出和父进程的标准输入。**pipe()建立两条数据流(fd[0], fd[1])写入表中， 通过返回的文件描述符就可以在两端操作了.**,pipe()在描述符中创建这两项时,会把它们的文件描述符**保存在一个包含两个元素的数组中**:

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_9.png)

pipe()函数创建了管道,并返回了两个描述符: 

- fd[1] 用来向管道**写**数据
- fd[0] 用来从管道**读**数据

你将在 父、子进程中使用这两个描述符。

### 2.2.1 子进程
在这个项目中，子进程只需要*写*就ok了， 所以可以关闭管道的f[0]端, 然后修改其标准输出指向f[1]数据流.

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_10.png)

### 2.2.2 父进程
父进程只需要*读*就行了，所以需要关闭f[1]端，然后重定向父进程的标准输入,让它从描述符fd[0]对应的数据流中读取数据:

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_11.png)

### 2.2.3 实例：浏览器打开网页

我们尝试上面程序读取到的网址，调用系统函数打开浏览器浏览网页。

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <sys/wait.h>

	//定义一个通用的错误处理方法
	void error(char *msg){
	    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	    exit(1);        // exit(1)会立刻终止程序并把`退出状态`设为1
	}

	// 打开浏览器
	void open_url(char *url) {
	    char launch[255];
	//    sprintf(launch, "cmd /c start %s", url);
	//    system(launch);     // windows
	//    sprintf(launch, "x-www-browser '%s' &", url);
	//    system(launch);     // linux
	    
	    sprintf(launch, "open '%s'", url);
	    system(launch);     // mac
	}


	int main(int argc, char *argv[]) {
	    char *phrase = argv[1];
	    char *vars[] = {"RSS_FEED=http://rss.news.sohu.com/rss/guoji.xml", NULL};
	    int fd[2];  //这个数组保存管道的描述符
	    //创建管道
	    if (pipe(fd) == -1) {
	        error("创建管道失败");
	    }
	    
	    //fork进程
	    pid_t pid = fork();
	    //判断fork是否成功
	    if (pid == -1) {
	        error("fork进程失败");
	    }
	    
	    
	    //这段代码会修改子进程，因为pid为0
	    if (!pid) {
	        close(fd[0]);   // 0:read
	        dup2(fd[1], 1); // 标准写入重定向到fd[1],设为管道输入端
	        
	        //执行系统调用
	        int pid = execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py","-u", phrase, NULL, vars);
	        if (pid == -1) {
	            error("系统调用失败");
	        }
	    }
	    
	    //父进程
	    dup2(fd[0], 0);     //标准读取重定向到fd[0],设为管道输出端
	    close(fd[1]);       //1:write
	    
	    char line[255];
	    while (fgets(line, 255, stdin)) {   //将从标准输入读取数据，因为管道连入了标准输入，也可以是fd[0]
	        // 如果line以tab开头则是url, line+1是tab以后的字符串
	        if (line[0] == '\t') {
	            printf("%s\n", line+1);
	            open_url(line + 1);
	        }
	    }
	    return 0;
	}


运行后就能发现自动打开对应的网页了。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_12.png)

## 2.3 小结

- 父子进程可以用管道通信
- pipe()函数创建一个管道和两个描述符
- 一个描述符是管道的读取端，另一个是写入端
- 可以把标准输入和标准输出重定向到管道
- 父子进程各自使用管道的一端

# 三.信号量
操作系统用**信号量**控制程序，当`ctrl+z`向程序发送*中断信号*

>信号是一条短消息,即一个*整型值*。当信号到来时,进程必须停止手中一切工作去处理信号。进程会查看**信号映射表**,表中每个信号都对应一个*信号处理器函数*。中断信号的默认信号处理器会调用exit()
函数。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_13.png)


## 3.1 sigaction
`sigaction`是一个**函数包装器**,是一个结构体，有一个函数指针。sigaction 告诉操作系统进程收到某个信号时应该调用哪个函数。如果想 在某人向进程发送中断信号时让操作系统调用diediedie()函 数,就需要把diediedie()函数包装成sigaction。


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_14.png)

## 3.2 处理器必须接收信号量参数
信号是一个整型值,如果你创建了一个自定义处理器函数,就 需要接收一个整型参数,像这样:

	void diediedie(int sig)
	{
		puts("end");
		exit(1);
	}

## 3.3 用sigaction()函数注册sigaction
创建sigaction以后,需要用sigaction()函数来让操作系统知道它的存在:

	sigaction(signal_no, &new_action, &old_action);


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_15.png)

**如果sigaction()函数失败,会返回-1,并设置errno变量。**

实例：Ctrl-C: 处理程序

	
	#include <stdio.h>
	#include <signal.h>             // 使用这个头文件
	#include <stdlib.h>

	//新的信号处理器
	void diediedie(int sig) {       // 操作系统把信号传给处理器
	    puts("goodbye!\n");
	    exit(1);
	    //处理器返回void
	}

	// 注册处理器函数
	int catch_signal(int sig, void (*handler)(int)) {
	    struct sigaction action;        // 创建动作
	    action.sa_handler = handler;    // 将动作处理器设置为我们传来的函数
	    sigemptyset(&action.sa_mask);   // 使用一个空的掩码
	    action.sa_flags = 0;
	    return sigaction(sig, &action, NULL);
	}

	int main() {
	    if (catch_signal(SIGINT, diediedie) == -1) {
	        // SIGINT:表示我们要捕获的信号量
	        // 将中断处理程序设为diediedie()
	        fprintf(stderr, "Can't map the handler");
	        exit(2);
	    }
	    char name[30];
	    printf("Enter your name:");
	    fgets(name, 30, stdin);
	    printf("Hello, %s\n", name);
	    return 0;
	}


程序要求用户输入名字,然后它会等待输入。如果用户没有输入名字而是按了Ctrl-C,操作系统会自动向进程发送中断信号(`SIGINT`), 然后用我们在`catch_signal()`函数中注册的`sigaction`来处理这
个信号。sigaction中有一个指向`diediedie()`函数的指针,程序会调用这个函数,显示消息并调用`exit()`。

## 3.4 发送信号
在类Unix操作系统中我们经常用`kill`命令，kill向进程发送一个信号(默认：`SIGTERM`)，也可以用它发送其他信号.在C中可以用`raise()`函数让进程向自己发送信号.

	raise(SIGTERM);

除了在发生错误时使用,*有时进程也需要产生自己的信号*,比如 􏽏􏽐信号SIGALRM。􏽏􏽐信号通常由进程的间隔定时器创建。间隔定时器就像一台􏽏􏽐:你可以定一个时间,其间程序就会去做 其他事情:

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_16.png)

注意：**不要同时使用`sleep()`和`alarm()`, 因为都使用了间隔计时器，同时使用会发生冲突**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top10_17.png)

## 3.5 实例：计时数学运算大比拼

下面程序测试用户的数学水平，要求用户输出a*b的值，涉及条件：

(1).控制用户的ctrl-c

(2).用户要是在5s后没有写上答案则程序结束并把退出状态设为0



	#include <stdio.h>
	#include <signal.h>
	#include <errno.h>
	#include <string.h>
	#include <unistd.h>
	#include <time.h>
	#include <stdlib.h>

	int score=0;

	//新的信号处理器
	void end_game(int sig){
	    printf("\nFinal score: %i\n", score);
	    exit(0);
	}

	//注册处理器函数
	int catch_signal(int sig, void (*handler)(int)) {
	    struct sigaction action;
	    action.sa_handler = handler;
	    sigemptyset(&action.sa_mask);
	    action.sa_flags = 0;
	    return sigaction(sig, &action, NULL);
	}

	void time_up(int sig) {
	    puts("\nTime's up!");
	    raise(SIGINT);      // 引发SIGINT信号，让程序调用end_game()显示最后得分
	}

	void error(char *msg){
	    fprintf(stderr, "%s, %s\n", msg, strerror(errno));
	    exit(1);
	}

	int main(){
	    catch_signal(SIGALRM, time_up);
	    catch_signal(SIGINT, end_game);
	    srandom(time(0));               // 保证每次得到不同的随机值
	    while (1) {
	        int a = random() % 11;      //a,b 是0-10随机数
	        int b = random() % 11;
	        char txt[4];
	        alarm(5);                   // 将闹钟信号设为5s后触发
	        // 只要能在5s内再次回到这个地方，定时器就会重置，闹钟信号也不会触发
	        printf("\nWhat is %i * %i? ", a, b);
	        fgets(txt, 4, stdin);
	        int answer = atoi(txt);
	        if (answer == a*b) {
	            score++;
	        } else
	            printf("\nWrong!Score:%i\n", score);
	    }
	    return 0;
	}

运行：

	➜  intoC git:(master) ✗ ./test_sig                
	What is 0 * 4? 4

	Wrong!Score:0

	What is 1 * 3? 3

	What is 9 * 10? 90

	What is 0 * 2? 
	Time's up!

	Final score: 2

	➜  intoC git:(master) ✗ ./test_sig

	What is 5 * 2? 10

	What is 8 * 7? ^C
	Final score: 1

## 3.6 小结

- system用信号控制进程
- 进程常用信号来结束
- 进程收到信号后会进行信号处理器
- 大部分错误信号的默认处理器会终止程序
- 可以用`signation()`函数替换处理器
- 可以用`raise()`向自己发送信号
- 间隔定时器发送SIGALRM信号
- alarm()函数设置间隔定时器
- 每个进程只能有一个定时器
- 不要同时使用sleep()和alarm()
- kill命令可以向进程发送信号
- kill -KILL <进程号> 一定能让你的程序上西天


