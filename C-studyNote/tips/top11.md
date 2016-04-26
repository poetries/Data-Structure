# 一.串行，并行，并发的概念

- 串行(Sequential): 指的是多个程序在同一个处理器上被执行，只有当当前的程序执行结束后，下一个程序才可以开始。
- 并行(Parallel): 多个任务可以在同一时刻执行，比较大的任务可以被分割成小任务，这些小任务可以被分配到不同的处理器上同时执行。
- 并发(Concurrent): 多个任务在同一时间段内从开始执行到执行结束，在这段时间内，每一个时刻都只有一个程序执行，并且所有的任务都是在同一个处理器上执行。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/bing_or_chuan.jpg)


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/bf.png)

# 二.多线程
之前写过[理解线程与进程(Python)](http://beginman.cn/python/2015/04/09/Python-learn9/), 我贴上比较重要的知识点:

- 进程是计算机中已运行程序的实体，是程序的基本执行实体，是线程的容器。它有两种运行方式：同步（循序）和异步（平行）。
- 线程是操作系统能够进行运算调度的最小单位。它被包含在进程之中，是进程中的实际运作单位。一条线程指的是进程中一个单一顺序的控制流，一个进程中可以并发多个线程，每条线程并行执行不同的任务。

线程是程序中一个单一的顺序控制流程.在单个程序中同时运行多个线程完成不同的工作,称为**多线程**。

为什么要引入多线程呢？有以下几个优点：

- 改进性能和并发(improved performance and concurrency),对于某些应用程序,可以提高性能和并发性通过使用多线程。
- 减少了所需的服务器数量。

缺点如下：

- 调试困难 . 
- 并发难以管理，如果有大量的线程,会影响性能,因为操作系统需要在它们之间切换且更多的线程需要更多的内存空间。


## 2.1 创建线程
使用POSIX线程库:`pthread`, 在编译的适合需要用到 `-lpthread` 选项表示链接pthread库。

如创建两个线程运行两个函数的实例：


	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <pthread.h>

	void error(char *msg)
	{
		fprintf(stderr, "%s, %s", msg, strerror(errno));
		exit(1);
	}

	void* does_not(void *a)		//线程函数的返回类型为void*	
	{
		int i = 0;
		for(i=0; i < 5; i++) {
			sleep(1);
			puts("Does not!");
		}
		return NULL;			//返回NULL
	}

	void* does_too(void *a)		//线程函数的返回类型为void*	
	{
		int i = 0;
		for(i=0; i<5;i++) {
			sleep(1);
			puts("Does too");
		}
		return NULL;
	}

	int main(int argc, char *argv[])
	{
		pthread_t t0;		//创建线程并保存在pthread_t的数据结构中
		pthread_t t1;
		//注意每次都要检查错误
		if(pthread_create(&t0, NULL, does_not, NULL) == -1) // &0保存线程信息的数据结构地址
			error("无法创建线程t0");
		if(pthread_create(&t1, NULL, does_too, NULL) == -1)
			error("无法创建线程t1");

		//以上代码将以独立的线程运行这两个函数，如果主函数运行完成则线程随之灭亡，因此必须等待线程结束
		void* result; //函数返回的void指针会保存在这里
		if(pthread_join(t0, &result) == -1) // pthread_join()会等待线程结束
			error("无法收回线程t0");
		if(pthread_join(t1, &result) == -1)
			error("无法收回线程t1");
	}

注意两点：

- void指针可以指向存储器中任何类型的数据,**线程函数的返回类型必须是`void*`**。
- `pthread_join()`会接收线程函数的返回值,并把它保存在一个void指针变量中。一旦两个线程都结束了,程序就可以顺利退出了。
- 把`sleep()`去掉后程序会先显示一个函数的输出然后再显示另一个函数的输出，这是因为大多数计算机会很快执行完代码，第一个函数将在第二个函数开始运行前就结束了

然后运行如下：

	➜  intoC git:(master) ✗ gcc thread1.c -lpthread -o thread1
	➜  intoC git:(master) ✗ ./thread1 
	Does too
	Does not!
	Does not!
	Does too
	Does not!
	Does too
	Does not!
	Does too
	Does not!
	Does too


## 2.2 非线程安全

下面的示例代码来倒计啤酒数：

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <pthread.h>

	void error(char *msg)
	{
		fprintf(stderr, "%s. %s", msg, strerror(errno));
		exit(1);
	}

	int beers = 2000000;
	void* drink_lots(void *a)
	{
		int i;
		for(i=0; i< 100000; i++){
			beers = beers - 1;
		}
		return NULL;
	}

	int main(int argc, char *argv[])
	{
		pthread_t threads[20];
		int t;
		printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
		for(t=0; t<20;t++){
			//创建20个线程
			if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1){
				error("无法创建线程");
			}
		}
		//函数返回的void指针会保持在这里
		void* result;
		for(t=0;t<20;t++){
			if(pthread_join(threads[t], &result) == -1){
				error("无法收回线程");
			}
		}
		printf("There are now %i bottles of beer on the wall\n", beers);
		return 0;
	}

上面代码创建了20个线程，每个线程处理10w个啤酒瓶子，总共200w的瓶酒瓶子应该很快被处理完，这里我们运行下代码：

	➜  intoC git:(master) ✗ ./thread2
	2000000 bottles of beer on the wall
	2000000 bottles of beer
	There are now 641569 bottles of beer on the wall
	➜  intoC git:(master) ✗ ./thread2
	2000000 bottles of beer on the wall
	2000000 bottles of beer
	There are now 185316 bottles of beer on the wall


运行了好几次发现并不是自己想象中的那样，why?

当两个线程访问同一变量，如都想把beers值减1,却没有成功。两个线程只把 beers值减去了1,而不是2,这就是为什么beers变量没有减到0,因为线程之间会相互影响。为什么结果是不可预测的呢?因为线程每次运行这行代码的顺序都不一样。线程有时不撞􏴋车,有时则撞得车毁人亡􏲙。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top12_1.png)


## 2.3 互斥锁
如果想防止两个或多个线程访问共享数据资源,可以像增设红绿灯一样，即**互斥锁**（有时也叫锁）。这样两个线程就不能同时读取相同数据,并把它写回。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top12_2.png)

### 2.3.1 创建互斥锁：

	pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;

>互斥锁必须对所有可能发生冲突的线程可见,也就是说它是一个全局变量。PTHREAD_MUTEX_INITIALIZER实际上是一个宏,当编译器看到它,就会插入创建互斥锁的代码。

	pthread_mutex_lock(&a_lock);		//一次只有一个线程可以通过这里
	/* 含有共享数据的代码从这里开始 */
	/* ...代码结束了 */ 
	pthread_mutex_unlock(&a_lock);

### 2.3.2 把long值传给线程函数
线程函数可以接收一个void指针作为参数,并返回一个void指针值。通常你希望把某个整型值传给线程,并让它返回某个整型值, 一种方法是用long,因为它的大小和void指针相同,可以把它保
存在void指针变量中。

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <pthread.h>

	void* do_stuff(void *param) //线程函数可以接收一个void指针类型的参数
	{
		long thread_no = (long)param;	//转换为long
		printf("Thread number:%ld\n", thread_no);
		return (void*)(thread_no+1);  //返回是将其转换为void指针
	}

	int main()
	{
		pthread_t threads[3];
		long t;
		for(t=0;t<3;t++){
			pthread_create(&threads[t], NULL, do_stuff, (void*)t);  //将long类型变量转换为void指针
		}
		void* result;
		for(t=0;t<3;t++){
			pthread_join(threads[t], &result);
			printf("Thread %ld return %ld\n", t, (long)result);	// 在使用前先把它转换long
		}
		return 0;
	}


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top12_3.png)

### 2.3.3 完善性实例

	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <pthread.h>

	void error(char *msg)
	{
		fprintf(stderr, "%s. %s", msg, strerror(errno));
		exit(1);
	}

	int beers = 2000000;
	//创建线程锁
	pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
	void* drink_lots(void *a)
	{
		int i;
		pthread_mutex_lock(&beers_lock);
		for(i=0; i< 100000; i++){
			beers = beers - 1;
		}
		pthread_mutex_unlock(&beers_lock);
		printf("beers = %i\n", beers);
		return NULL;
	}

	int main(int argc, char *argv[])
	{
		pthread_t threads[20];
		int t;
		printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
		for(t=0; t<20;t++){
			//创建20个线程
			if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1){
				error("无法创建线程");
			}
		}
		//函数返回的void指针会保持在这里
		void* result;
		for(t=0;t<20;t++){
			if(pthread_join(threads[t], &result) == -1){
				error("无法收回线程");
			}
		}
		printf("There are now %i bottles of beer on the wall\n", beers);
		return 0;
	}


然后运行下看看吧：

	➜  intoC git:(master) ✗ gcc thread2.c -lpthread -o thread2
	➜  intoC git:(master) ✗ ./thread2 
	2000000 bottles of beer on the wall
	2000000 bottles of beer
	beers = 1900000
	beers = 1800000
	beers = 1700000
	beers = 1600000
	beers = 1500000
	beers = 1400000
	beers = 1300000
	beers = 1200000
	beers = 1100000
	beers = 1000000
	beers = 900000
	beers = 800000
	beers = 700000
	beers = 600000
	beers = 500000
	beers = 400000
	beers = 300000
	beers = 200000
	beers = 100000
	beers = 0
	There are now 0 bottles of beer on the wall

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top12_4.png)


