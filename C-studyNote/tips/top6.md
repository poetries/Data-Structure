如果再更加灵活的创建数据结构，那么就要使用链表了，它是动态的进行内存存储分配的一种结构，本节主要就是学习它；

- 链表的使用
- 动态存储

# 一.链表的使用
## 1.链表使用
假如一架飞机要飞向A,B,C,D,...岛屿，路线不定，每座岛屿有名称(name),开始营业时间（opens）和打烊时间（closes），一个函数展示它要飞行的路线信息，一个岛屿指向另一个岛屿，就有点链条的味道了，所以我们声明的结构需要有个字段指向自身（**递归结构**），如下实例：

	// 创建递归结构必须为此命名，typedef struct island 不可省略
	typedef struct island{
	    char *name;
	    char *opens;
	    char *closes;
	    struct island *next;    // 保存一个指向下一个的指针
	} island;

然后定义变量，一个个的连接它们，演示代码如下：

	#include <stdio.h>
	#include <stdlib.h>

	// 创建递归结构必须为此命名，typedef struct island 不可省略
	typedef struct island{
	    char *name;
	    char *opens;
	    char *closes;
	    struct island *next;    // 保存一个指向下一个的指针
	} island;

	void display(island *start) {
	    island *i = start;
	    for (; i != NULL; i=i->next) {
	        // i != NULL,表示需要一直循环下去直到当前island没有next值
	        // i = i->next. 表示循环结束后跳转到下一个island
	        printf("Name:%s\n open:%s-%s\n", i->name, i->opens, i->closes);
	    }
	}

	int main(int argc, char *argv[]) {
	    island A = {"A", "09:00", "21:00", NULL};       // NULL全部大写，实际值为0，专门用于将指针设为0
	    island B = {"B", "08:00", "21:00", NULL};
	    island C = {"C", "10:00", "21:00", NULL};
	    island D = {"D", "09:00", "22:00", NULL};
	    
	    // 连接
	    A.next = &B;
	    B.next = &C;
	    C.next = &D;
	    
	    // show
	    display(&A);
	    return 0;
	}

运行下，可以输出：

	Name:A
	 open:09:00-21:00
	Name:B
	 open:08:00-21:00
	Name:C
	 open:10:00-21:00
	Name:D
	 open:09:00-22:00

# 二.动态存储
到目前为止，写的所有程序都是**静态存储，也就是每当想保存一个东西，就需要在代码中声明一个变量，然后这些变量保存在栈中**， 以上面的例子，如果要创建更多island则需要write N islands。

## 1.用堆进行动态存储
堆是程序中长期保存的地方，不会自动清除,首先会用`malloc()`申请空间，`malloc()`函数会向操作系统要求分配空间，然后返回指向该空间的指针。但是这种申请也不是随意的，因为堆空间有限，用完之后要释放掉，调用`free()`释放存储器。虽然程序运行结束后所有的堆空间会自动释放，但是显式调用free更加合理。

malloc:memory allocation(存储器分配)，`malloc()`接收一个参数，表示申请的字节大小，往往我们不知道字节大小，所以配合`sizeof()`

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/malloc.png)

malloc返回通用指针，即`void*`类型的指针：

	island *p = malloc(sizeof(island));

`free()`需要调用`malloc()`创建的地址，释放方式如下：

	free(p);

那么接着上面的例子，动态创建岛屿：

	// 创建
	island* create(char *name) {
	    island *i = malloc(sizeof(island));
	    i->name = name;
	    i->opens = "09:00";
	    i->closes = "21:00";
	    i->next = NULL;
	    return i;   // 返回新结构的地址
	}

在main函数中动态创建island：

	int main(int argc, char *argv[]) {	    
	    island *A = create("A", "10:00", "22:00");
	    island *B = create("B", "09:00", "22:00");
	    A->next = B;
    	printf("current island:%s, the next island is:%s", A->name, A->next->name);
	    return 0;
	}

## 2.strdup()函数把字符串复制到堆上
如下实例：

	// 创建递归结构必须为此命名，typedef struct island 不可省略
	typedef struct island{
	    char *name;
	    char *opens;
	    char *closes;
	    struct island *next;    // 保存一个指向下一个的指针
	} island;

	// 循环展示
	void display(island *start) {
	    island *i = start;
	    for (; i != NULL; i=i->next) {
	        // i != NULL,表示需要一直循环下去直到当前island没有next值
	        // i = i->next. 表示循环结束后跳转到下一个island
	        printf("Name:%s\n open:%s-%s\n", i->name, i->opens, i->closes);
	    }
	}

	// 创建
	island* create(char *name) {
	    island *i = malloc(sizeof(island));
	    i->name = name;
	    i->opens = "10:00";
	    i->closes = "22:00";
	    i->next = NULL;
	    return i;   // 返回新结构的地址
	}

	int main(int argc, char *argv[]) {    
	    char name[80];
	    fgets(name, 80, stdin);
	    island *A = create(name);
	    
	    fgets(name, 80, stdin);
	    island *B = create(name);
	    A->next = B;
	    display(A);
	    return 0;
	}


当我们输入后却发现返回值一样：

	AAA
	BBB
	Name:BBB

	 open:10:00-22:00
	Name:BBB

	 open:10:00-22:00

这是因为fgets公用字符数组name, 所以A,B变量共用同一name地址，为了解决此类问题，除了更换名称外，还可以用`strdup()`函数，strdup()函数可以把字符串复制到堆上:

	char *copy = strdup(s);

strdup的原理：
- 计算字符串长度，然后调用`malloc()`在堆上分配相应的空间
- 把所有字符串复制到堆上的新空间

注意：在使用`strdup`后，一定要记得`free`释放空间。

我们把上面代码改成这样就ok了：

	i->name = strdup(name);

接下来，来一个创建与释放的例子：

	// 释放
	void release(island *start) {
	    island *i = start;
	    island *next = NULL;
	    for (; i != NULL; i=next) {
	        next = i->next;             // 把next设为指向下一个的指针
	        free(i->name);              // 先释放用strdup()创建的name字符串
	        free(i);                    // 只有先释放name才能释放island结构,否则就找不到name了
	    }
	}

	int main(int argc, char *argv[]) {	    
	    island *start = NULL;       // 开始结构
	    island *i = NULL;           // 当前结构
	    island *next = NULL;        // 下一个指向的结构
	    char name[80];
	    for (; fgets(name, 80, stdin) != NULL; i=next) {    // i=next:在每次循环的最后，将i设为下一个要创建的结构
	        next = create(name);        // 创建结构
	        if (start == NULL) {        // 第一次循环时，start值为NULL，因此将start设为第一座岛屿
	            start = next;
	        }
	        if (i != NULL) {            //当前结构不为NULL，就将当前结构的下一条指向next
	            i->next = next;
	        }
	    }
	    // 从开始结构开始循环展示
	    display(start);
	    // 用完了释放它
	    release(start)
	    return 0;
	}

## 3.valgrid检查存储器泄露
valgrid通过拦截malloc()与free()的调用工作，打印留在堆上的数据信息，使用方法：

	gcc -g main.c -o main
	valgrid --leak-check=full ./main

