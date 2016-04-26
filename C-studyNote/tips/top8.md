从这一章起，就迈向了高级技术了，我们应该了解它，主要知识点：

- 系统调用：system(),exec()函数的使用
- 进程复制：fork()函数



# 一.系统调用


系统调用就是**操作系统内核函数**， 通过`stdlib.h`库，为C提供很多接口。

## 1.1 system()函数

	system("dir D:"); // windows:打印D盘内容
	system("gedit");	// *unix：启动编辑器
	system("say 'you are SB'");	//mac: 朗读文本

`system()`函数在操作系统上，当调用它时操作系统必须解释**命令字符串**，然后决定运行哪些程序和怎么运行，但存在很大安全问题， 如删除一些东西，注入恶意代码，更改环境变量等， 要解决这个问题就必须消除歧义，明确告诉操作系统运行什么程序，而不是由操作系统瞎解释。在C中用`exec()`函数来告知。

## 1.2 exec()函数替换当前进程
**进程是存储器中运行的程序**，如输入`ps -ef`则看到一堆输出，操作系统用一个数字来标识进程，叫**进程标识符(process identifier, 简称PID)**

exec()装入并运行其它程序的函数,把进程交接给了新程序.

## 1.3 exec()函数有很多
版本众多，分**列表函数**和**数组函数**

### 1.3.1 列表函数:execl()、execlp()、execle()

**列表函数以参数列表的形式接收命令行参数:**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_1.png)

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_2.png)

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_3.png)

### 1.3.2 数组函数：execv(), execvp(), execve()

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_4.png)

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_5.png)

### 1.3.3 实例：

**`execl()`**:

	/*
	 函数说明：execl()用来执行参数path 字符串所代表的文件路径, 接下来的参数代表执行该文件时传递过去的argv(0), argv[1], ..., 
	 最后一个参数必须用空指针(NULL)作结束.
	 */

	#include <stdio.h>
	#include <unistd.h>

	int main(int argc, char *argv[]) {
	    execl("/bin/ls", "ls", "-al", "/etc/passwd", NULL);
	    return 0;
	}


**`execlp()`**:

	/*
	 同execlp,第一个参数不是路径而是通过环境变量的命令
	 */

	#include <stdio.h>
	#include <unistd.h>

	int main(int argc, char *argv[]) {
	    execlp("ls", "ls", "-al", ".",  NULL);      // command: ls
	    return 0;
	}


**`execv()`**:

	/*
	 execv: 接收两个参数， path 和 字符串数组指针
	 */


	#include <stdio.h>
	#include <unistd.h>

	int main() {
	    char *args[] = {"ls", "-al", "/etc/passwd", NULL};
	    execv("/bin/ls", args);
	    return 0;
	}

**`execve()`**:

	/*
	 函数说明：execve()用来执行参数filename 字符串所代表的文件路径, 
	 第二个参数系利用数组指针来传递给执行文件, 
	 最后一个参数则为传递给执行文件的新环境变量数组.
	*/

	#include <stdio.h>
	#include <unistd.h>

	int main(){
	    char *argv[] = {"ls", "-al", "/etc/passwd", NULL};
	    char *env[] = {"PATH=/bin", 0};
	    execve("/bin/ls", argv, env);
	    return 0;
	}

**`execvp()`**:

	/*
	 *函数说明：execvp()会从PATH 环境变量所指的目录中查找符合参数file 的文件名, 找到后便执行该文件, 
	 然后将第二个参数argv 传给该欲执行的文件。
	 */

	#include <stdio.h>
	#include <unistd.h>

	int main(int argc, char *argv[]){
	    char *args[] = {"ls", "-al", "/etc/passwd", 0};
	    execvp("ls", args);
	    return 0;
	}


### 1.3.4 传递环境变量
**每个进程都有一组环境变量**, 命令行中使用`set`或`env`查看它们的值。C用`getenv()`系统调用读取环境变量.如果想用命令行参数和环境变量运行程序，可以这样做：

	// diner_info.c

	#include <stdio.h>
	#include <stdlib.h>

	int main(int argc, char *argv[]){
	    printf("%s\n", argv[1]);
	    printf("%s\n", getenv("JUICE"));
	    return 0;
	}

	// main.c

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>

	int main(int argc, char *argv[]) {
	    char *my_env[] = {"JUICE=peach and apple", NULL};			// 字符串指针数组创建一组环境变量
	    execle("diner_info", "diner_info", "4", NULL, my_env);
	    return 0;
	}

main.c用来通过参数列表和环境变量字符数组来调用diner_info可执行文件：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_6.png)

execle()函数将设置命令行参数和环境变量,然后用diner_info替换当前进程。

	gcc diner_info.c -o diner_info
	gcc main.c -o main 
	./main
	4
	peach and apple

## 1.4 系统调用失败的处理法则

一旦系统调用如`exec()`失败则就不会继续往下走了，处理失败的黄金法则摘抄如下：

- 尽可能收拾残局
- 把errno变量设为错误码
- 返回-1

`errno`变量是定义在`errno.h`中的全􏴣变量,和它定义在 一起的还有很多标准错误码,如:

错误代码：

EACCES：

- 1. 欲执行的文件不具有用户可执行的权限.
- 2. 欲执行的文件所属的文件系统是以noexec 方式挂上.
- 3. 欲执行的文件或script 翻译器非一般文件.

EPERM：

- 1. 进程处于被追送模式, 执行者并不具备root 权限, 欲执行的文件具有SUID 或SGID 位.
- 2. 欲执行的文件所属的文件系统是以nosuid 方式挂上, 欲执行的文件具有SUID 或SGID 位元, 但执行者并不具有root 权限.

E2BIG 参数数组过大

ENOEXEC 无法判断欲执行文件的执行文件格式, 有可能是格式错误或无法在此平台执行.

EFAULT 参数filename 所指的字符串地址超出可存取空间范围.

ENAMETOOLONG 参数filename 所指的字符串太长.

ENOENT 参数filename 字符串所指定的文件不存在.

ENOMEM 核心内存不足

ENOTDIR 参数filename 字符串所包含的目录路径并非有效目录

EACCES 参数filename 字符串所包含的目录路径无法存取, 权限不足.

ELOOP 过多的符号连接

ETXTBUSY 欲执行的文件已被其他进程打开而且正把数据写入该文件中

EIO I/O 存取错误

ENFILE 已达到系统所允许的打开文件总数.

EMFILE 已达到系统所允许单一进程所能打开的文件总数.

EINVAL 欲执行文件的ELF 执行格式不只一个PT_INTERP 节区

EISDIR ELF 翻译器为一目录

ELIBBAD ELF 翻译器有问题.


这样你就可以拿errno和这些值比较,也可以用string.h中 的`strerror()`的函数查询标准错误消息:

	puts(strerror(errno));


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_7.png)


### 1.4.1: 实例：实现rss订阅搜索
方案就是：通过C设置系统变量，调用一个rss检索的[python脚本](https://github.com/dogriffiths/rssgossip/blob/master/rssgossip.py)， 如：

	export RSS_FEED=http://rss.news.sohu.com/rss/focus.xml  
	python rssgossip.py 'sohu'
	www.sohu.com

这里环境变量RSS_FEED由C控制，订阅多个rss源，并传递查询字符串，如下代码：

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <unistd.h>

	int main(int argc, char *argv[]) {
	    char *feeds[] = {
	        "http://rss.news.sohu.com/rss/guoji.xml",
	        "http://rss.news.sohu.com/rss/shehui.xml",
	        "http://rss.news.sohu.com/rss/focus.xml"
	    };
	    int times = 3;
	    char *phrase = argv[1]; // 把搜索关键字作为参数传递
	    int i;
	    for (i=0; i<times; i++) {
	        //构建环境变量字符串
	        char var[255];
	        sprintf(var, "RSS_FEED=%s", feeds[i]);
	        char *vars[] = {var, NULL};
	        
	        //系统调用
	        //用参数列表和环境变量，所以用execle函数
	        //./rssgossip.py 脚本位置
	        //phrase：搜索关键字，以命令行参数传递
	        //vars:以参数传递环境变量
	        if (execle("/usr/bin/python", "/usr/bin/python",  "./rssgossip.py", phrase, NULL, vars) == -1) {
	            fprintf(stderr, "Can't run scrpit:%s\n", strerror(errno));
	            return 1;
	        }
	    }
	    return 0;
	}


然后运行：

	./rss sohu
	www.sohu.com

只显示一条，我们原本想循环3个订阅源，显示三条信息的，很明显只显示了第一个订阅源，后面的终止了，这是为什么呢？

## 1.5 fork

上面的例子的问题就是**`exec()`函数通过运行新程序来替换当前程序, 那原来的程序去哪儿了?它终止了,而且是立刻终止,这就是为什么程序只为第一条RSS源运行了rssgossip.py脚本。程序在第一次调用 execle()以后rss程序就终止了。**

如果你想在启动另一个进程的同时让原进程􏹕 续运行下去,就应该使用**`fork()`克隆进程**

>`fork()`会克隆当前进程。新建副本将从同一行（要知道`exec()`是最后一行，因为执行后会退出）开始运行相同程序,变量和变量中的值完全一样,只有进程标识符(PID)和原进程不同。
**原进程叫父进程,而新建􏷯本叫子进程。**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_10.png)


注意：**windows不支持fork**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_8.png)

解决上面问题的方案就是：**用fork()+exec()运行子进程，这样父进程就能保持运行了**, 步骤如下：

- 第一步：fork()复制当前进程，进程需要以某种方式区分自己是父进程还是子进程,为此fork()函数向**子进程返回0,向父进程返回非零值**。
- 第二步：子进程调用exec()

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_9.png)

我们修改下：

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <unistd.h>

	int main(int argc, char *argv[]) {
	    char *feeds[] = {
	        "http://rss.news.sohu.com/rss/guoji.xml",
	        "http://rss.news.sohu.com/rss/shehui.xml",
	        "http://rss.news.sohu.com/rss/focus.xml"
	    };
	    int times = 3;
	    char *phrase = argv[1]; // 把搜索关键字作为参数传递
	    int i;
	    for (i=0; i<times; i++) {
	        //构建环境变量字符串
	        char var[255];
	        sprintf(var, "RSS_FEED=%s", feeds[i]);
	        char *vars[] = {var, NULL};
	        
	        //系统调用
	        //用参数列表和环境变量，所以用execle函数
	        //./rssgossip.py 脚本位置
	        //phrase：搜索关键字，以命令行参数传递
	        //vars:以参数传递环境变量
	        pid_t pid = fork();
	        if (pid == -1) {        // 如果pid为-1则克隆出了问题
	            fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
	            return 1;
	        }
	        if (pid == 0) {     // 或 !pid,  运行在子进程
	            if (execle("/usr/bin/python", "/usr/bin/python",  "./rssgossip.py", phrase, NULL, vars) == -1) {
	                fprintf(stderr, "Can't run scrpit:%s\n", strerror(errno));
	                return 1;
	            }
	        }
	        
	    }
	    return 0;
	}


那么运行的时候这三个进程**同时运行**

	./rss sohu      
	www.sohu.com
	www.sohu.com
	www.sohu.com


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top9_11.png)


一些重要的知识：

- 为了让fork更快，操作系统不会真的复制父进程的数据，而是**共享数据**
- 如果操作系统发现子进程要修改存储器，则为为它赋值一份数据(**写时复制** copy_on_write)
- pid_t不一定是int，要取决平台，肯能是short,long,但一定是整型
- 系统调用时内核中的函数
- exec()比system()提供了更多控制权
- exec()**替换**当前进程
- fork()**复制**当前进程
- 系统调用失败通常返回-1

推荐阅读：

- [linux网络编程系列](http://mickole.blog.51cto.com/7547481/d-2)





