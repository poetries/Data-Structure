这章主要将存储器和指针，能忽悠到什么呢？？

- 什么是指针？
- 理解字符串
- 存储器小窥
- 指针使用三部曲
- 数组与指针
- 指针类型
- scanf函数，fgets函数
- 字符串字面值的更新
- 常量与变量
- 常量修饰符:const
- 看看我推荐的文章吧


# 一.指针是啥玩意？
![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer.jpg)

指针：**就是存储器中某条数据的`地址`**

## 1.C指针存在的意义

很多人包括我也难掌握指针的方方面面，既然它那么复杂，那么为什么会存在这个东东呢？我从本书中和知乎上总结了下：

- 函数调用时只传地址（一个指针），而不用传整份数据
- 避免副本和共享数据，不用每次都创建副本

在[为什么说指针是 C 语言的精髓？](http://www.zhihu.com/question/20125963)问题上，我比较赞同[pansz](http://www.zhihu.com/people/pansz)的答案：

>C语言只有值的传递，无法直接传递引用，要想传递引用必须通过指针间接实现。

>如果 C 语言没有指针，一切都通过值传递，参数将永远只有输入参数，所有的结构体只要参与运算都具有极高的开销，因为每传递进函数参数一次就必须全体复制一次。

>另外一点：C语言无法在参数中传递数组，一切数组在函数参数传递时退化为指针，因此如果没有指针，数组将无法通过函数参数传递。

>还有一点，在C语言中函数是一个指针，如果没有指针，就无法定义C语言函数，无法使用和调用C语言函数，更无法将函数作为一个变量传递。——换句话说，没有指针，C语言将没有函数，一个没有函数的语言会是什么概念？

>实际上指针这概念在绝大多数高级语言中都普遍运用了，只是人家不叫指针，通常叫做引用而已。例如 Java 的所有对象变量从 C 语言的角度都实际上保存的是一个指针而不是对象本身。

>完全的舍弃指针，C程序将变得低效难懂，因为你无法让在任何子函数中修改一个结构体的内容。这种程序类似于无状态程序。

## 2.如何理解指针
先看一个例子


	int y = 1;      //全局变量y位于全局量段，存储器地址10000，值为1
	int main() {
	    int x = 4;  //局部变量x位于栈中，存储器地址40000，值为4
	    printf("address:%p", &x);// address:0x7fff5fbff838
	    return 0;
	}

在存储器中表示如下丑图：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/img_0139.png)

我们发现指针就是指向变量的内存地址。
## 3.指针使用三部曲
### 3.1 `&`运算符得到变量的地址
一旦得到变量的地址就要保存起来，需要指针变量，指针变量是一个用来保存存储器地址的变量。当 声明指针变量时,需要说明指针所指向的地址中保存的数据的类型:
	
	int x=4;
	printf("x lives at %p\n", &x);
	int *address_of_x = &x;

这是一个􏱔􏱕变量,它􏳡􏲹的保存的是一个􏷼地址􏹀,这个􏷼􏹀地址中􏳡􏲹保存的是一个int􏳶变量。

### 3.2 `*`运算符读取地址中的内容

	int value_stored = *address_of_x;

### 3.3改变地址中的内容
如果你有一个指针变量,并想修改这个变量所指向地址中的数据,可以再次使用`*`运算符,只不过这次需要把指针变量放在赋值运算符的左边􏴏：

	*address_of_x = 99;


## 4.`&`与`*`
- `&`取地址符
- `*`读取地址中的内容
- `*`设置地址中的内容

# 二.数组与指针
**当创建一个数组后，数组变量就可以当做指针使用，它指向数组在存储器中的首地址。**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer1.png)

	printf("%p", quote);

## 2.1 字符串函数传递

**函数中传递字符串，就是传入了一个指向字符串的指针。也就是说如果把函数参数声明为数组，它会被当做指针处理**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer2.png)

**这里`sizeof`是一个运算符而不是函数， 不要搞错了~**

>在32位操作系统中，存储器地址以32位数字的形式保存，所以叫32位操作系统，32位=4字节(byte)(4*8bit), 所以64位操作系统要8个字节来保存地址。

## 2.2 数组变量与指针不同点
虽然数组变量可用作指针但两者又有区别

	char s[] = "How big is it?";
	char *t = s;

**(1). sizeof取得大小不同**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer3.png)

**(2). 数组的地址还是数组地址，指针变量地址则不是**

- 指针变量：保存存储在存储器地址的变量
- 数组变量：使用`&`运算符取得的还是数组变量本身

	&s == s;
	&t != t;

**(3). 数组变量不能指向其他地方**

>当创建指针变量时,计算机会为它分配4或8字节的存储空间。但如果创建的是数组呢?计算机会为数组分配存储空间,但不会为数组变量分配任何空间, 编译器仅在出现它的地方把它替换成数组的起始地址。

**由于计算机没有为数组变量分配空间,也就不能把它指向其他地方**

	s = t; // 报错

## 2.3 指针退化

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer4.png)

## 2.4 数组与指针的交互
- 数组变量可看做指针，`*`运算符取数组首地址，所以以下语句成立：

	msg[0] == *msg

- 内存地址是一串16进制的数字表示，可以进行算术运行，如果找数组中下一个元素可以通过加地址(也就是**增加指针的值**)既可以用方括
号加上索引值2来读取元素,也可以对第一个元素的地址加2:

	msg[2] == *(msg + 2)

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer5.png)

如下代码：从第6个字符开始打印

	
	void skip(char *msg) {
	    // msg指针+6,将从第7个字符开始打印
	    puts(msg+6);    // call me
	}
	int main() {
	    char *msg = "Don't call me";
	    skip(msg);
	    return 0;
	}

# 三.指针类型
既然指针只是地址，为嘛有类型呢？其实还是为了**偏移量**

char指针+1，指针会转向存储器中下一个地址，因为char就占1个字节；如果对int指针+1，那么就会对存储器地址+4（num+1 与num相差4个字节），因为int占4个字节，所以就没法统一加一个数字来偏移，于是就有了指针类型

# 四.用指针输入数据：scanf和fgets函数
两个都是输入函数， 都有好的一面不好的一面

## 1.scanf

语法：

    scanf(“格式控制字符串”, 地址表列);

其中，格式控制字符串的作用与printf函数相同，但不能显示非格式字符串，也就是不能显示提示字符串。

地址表列中给出各变量的地址。地址是由地址运算符“&”后跟变量名组成的。

使用scanf函数还必须注意以下几点：

- scanf函数中有长度（宽度）控制但没有精度控制，如：`scanf("%5.2f",&a);`是非法的。不能企图用此语句输入小数为2位的实数。
- scanf中要求给出变量地址，如给出变量名则会出错。如 `scanf("%d",a);`是非法的，应改为`scnaf("%d",&a);`才是合法的。
- 在输入多个数值数据时，若格式控制串中没有非格式字符作输入数据之间的间隔则可用空格，TAB或回车作间隔。C编译在碰到空格，TAB，回车或非法数据(如对“%d”输入“12A”时，A即为非法数据)时即认为该数据结束。
- scanf()会导致缓冲区溢出，所以要注意限制长度

参考：[C语言格式输入函数scanf()详解](http://c.biancheng.net/cpp/html/34.html)

## 2.fgets

原型:

	char *  fgets(char * s, int n,FILE *stream);

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer6.png)

我觉得有必要看看这篇文章:[ C语言文件操作之fgets（）](http://blog.csdn.net/daiyutage/article/details/8540932)

# 五.字符串字面值的更新
高能，这里有个大坑~
## 1.字符串之指针变量与数组
**指向字符串字面值的指针变量不能用来修改字符串的内容：**

	char *cards="JQK";	// 不能用这个变量修改这个字符串

**用字符串字面值的数组可以修改：**
	
	char cards[] = "JQK"; // ok

具体原因如下图：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer7.png)

**如果要修改字符串就要复制它：**在非只读区复制一份副本就行操作，如下：

	char cards[] = "JQK";

>如果你声明一个字符数组，然后把它设置为字符串字面值，该数组就成了一个全新的副本，cards不再只是一个指向字符串字面值的指针，而是一个􏳃新的数组,里面保存了字符串字面值的最新􏽇本。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer8.png)

接近底层的东西就是晦涩，总而言之：**字符串字面值数组可以在栈中复制一份字面值副本，放心大胆的修改；字符串指针变量引用的是常量区只读信息，只能读！**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/fun1.jpg)

## 2.如何避免修改字符串错误
从上面的解析我们可以这样避免：

- 􏲡􏷽􏲨不再将char指针设置为字符串字面值
- 如果设置了，就要加上`const`关键字进行提醒

	const char *cards = "JQK"; // 这样编译器会判断你是否试图修改字符串

## 3.`char cards[]` vs `char *cards`

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/pointer9.png)


# 六.C语言常量与变量
![](http://edutech.xmu.edu.cn/hongen/pc/oa/ac2k/img/ac2k1604.gif)

## 1.常量
在程序执行过程中，其值不发生改变的量称为常量

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/changliang.jpg)

说明：符号常量在使用之前必须先定义，其一般形式为：

	#define 标识符 常量

**习惯：符号常量的标识符用大写字母，变量标识符用小写字母**

	#include <stdio.h>
	#define PIRCE 30

	int main(){
		int num, total;
		num=10;
		total = num * PIRCE;
		printf("total is:%d\n", total);
		return 0;
	}

## 2.变量
![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/bianliang.gif)

变量定义：

	类型说明符  变量名, 变量名, ...;
	类型说明符 变量1= 值1, 变量2= 值2, ……;	// 赋初值

如：

	int b,c=5;
	float x=3.2,y=3.0,z=0.75;
	char ch1='K',ch2='P';

# 七.常量修饰符:const

`const`:常量修饰符，意即其所修饰的对象为常量(immutable)。

## 1、函数体内修饰局部变量

	int main() {
	    const int a=100;
	    a=3000;		// 报错
	    return 0;
	}

const作为一个类型限定词，和int有相同的地位。

	const int a;
	int const a;

两者等价

**要明白：const修饰的对象是谁，这里是a 和 int没关系， const 要求他所修饰的对象为常量，不可被改变，不可被赋值，不可作为左值（l-value)。**

这样的写法也是错误的。

	const int a;
	a=0;

这是一个很常见的使用方式：

	const double pi=3.14;

在程序的后面如果企图对pi再次赋值或者修改就会出错。

## 2.配合指针的使用

	const int* p;

还是先去掉const 修饰符号。注意，下面两个是等价的。

	int* p;
	int *p;

其实我们想要说的是，*p是int类型。那么显然，p就是指向int的指针,其实等价于:

	const int (*p);
	int const (*p);

即，*p是常量。也就是说，p指向的数据是常量。

于是

	p+=8; //合法
	*p=3; //非法，p指向的数据是常量。

那么如何声明一个自身是常量指针呢？方法是让const尽可能的靠近p;

	int* const p;

const右面只有p,显然，它修饰的是p,说明p不可被更改。然后把const去掉，可以看出p是一个指向 int形式变量的指针。

于是

	p+=8; //非法
	*p=3; //合法

**const 还有一个作用就是用于修饰常量静态字符串。**

例如：

	const char* name=David;

如果没有const,我们可能会在后面有意无意的写name[4]='x'这样的语句，这样会导致对只读内存区域的赋值，然后程序会立刻异常终止。有了 const,这个错误就能在程序被编译的时候就立即检查出来，这就是const的好处。让逻辑错误在编译期被发现。

**const 还可以用来修饰数组**

	const char s[]=David;

与上面有类似的作用。



# 八.推荐阅读这些文章

- [C语言指针和数组基础](http://blog.jobbole.com/44863/)
- [C语言内存地址基础](http://blog.jobbole.com/44845/)
- [C语言关于数组的常见操作汇总~看完这个数组问题基本都解决了](http://www.nowamagic.net/librarys/veda/detail/424)
- [C语言杂谈：指针与数组 (上)](http://blog.jobbole.com/86400/)
- [C语言杂谈：指针与数组 (下)](http://blog.jobbole.com/86412/)
- [话说C语言的const](http://www.cyuyan.com.cn/article-122-1.html)



