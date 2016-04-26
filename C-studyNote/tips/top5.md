这节主要涵盖C高级数据结构，在用python的时候，这门语言的灵活性令人咂舌，如：

	# python
	lis = ["string", 1, 3.98, False, {"name":"beginman", "age":24}, None]

在python列表里面可以自由设置任何类型的值，如果换到C/c++中则要写一大堆东西，正所谓“人生苦短，我用python”啊， 为了更深入的理解C,这份苦吃着也罢. 本节涉及知识点：

- 结构
- 联合
- 枚举
- 位操作


# 一.结构
我们需要把一批数据打包，如鱼的名称，种类，牙齿，年龄，如果要打印它，在之前的章节中可以这样：

	void showFish(const char *name, const char *species, int teeth, int age) {
	    // const char *:表示将传递字符串字面值
	    printf("%s is a %s with %i teeth.He is %i\n", name, species, teeth, age);
	}

	int main(int argc, char *argv[]) {
	    showFish("Snappy", "Piranha", 69, 4);
	    return 0;
	}


如果使用结构可以把不同的类型写在一起，封装成一个新的大数据类型：

	struct fish {
        const char *name;
        const char *species;
        int teeth;
        int age;
    };  // 不要忘了分号结尾
    

定义`struch fish`新结构后，开始创建数据：

    struct fish snappy = {"Snappy", "Piranha", 69, 4};

那么上面的例子可以用结构体改写成：

	struct fish {
	    const char *name;
	    const char *species;
	    int teeth;
	    int age;
	};  // 不要忘了分号结尾

	void showPrettyFish(struct fish f) {
	    printf("%s is a %s with %i teeth.He is %i\n", f.name, f.species, f.teeth, f.age);
	}

	int main(int argc, char *argv[]) {
	    struct fish snappy = {"Snappy", "Piranha", 69, 4};
	    showPrettyFish(snappy);
	    return 0;
	}

## 1.定义与声明

结构体的定义如下所示，struct为结构体关键字，tag为结构体的标志，member-list为结构体成员列表，其必须列出其所有成员；variable-list为此结构体声明的变量。

	 struct tag { member-list } variable-list ; 

在一般情况下，tag、member-list、variable-list这3部分至少要出现2个。以下为示例：

	//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
	//同时又声明了结构体变量s1
	//这个结构体并没有标明其标签
	struct 
	{
	    int a;
	    char b;
	    double c;
	} s1;

	//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
	//结构体的标签被命名为SIMPLE,没有声明变量
	struct SIMPLE
	{
	    int a;
	    char b;
	    double c;
	};
	//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
	struct SIMPLE t1, t2[20], *t3;

	//也可以用typedef创建新类型
	typedef struct
	{
	    int a;
	    char b;
	    double c; 
	} Simple2;
	//现在可以用Simple2作为类型声明新的结构体变量
	Simple2 u1, u2[20], *u3;

**可以使用指定初始化器来设置结构字段的初值：**

	typedef struct { 
		const char *color; 
		int gears;
		int height;
	} bike;
	
	bike b = {.height=17, .gears=21};


## 2.结构体成员访问
结构体成员依据结构体变量类型的不同，一般有2种访问方式，一种为直接访问，一种为间接访问

	struct SIMPLE
	{
	    int a;
	    char b;
	};

	//声明结构体变量s1和指向结构体变量的指针s2
	struct SIMPLE s1, *s2;

	//给变量s1和s2的成员赋值,注意s1.a和s2->a并不是同一成员
	//直接访问
	s1.a = 5;
	s1.b = 6;

	//间接访问
	s2->a = 3;
	s2->b = 4;

## 3.结构与存储器
**定义结构时，存储器并没有创建任何东西，只是给了计算机一个模板，当定义新变量时，存储器为结构创建一块足够大的空间。那么当把一个结构变量赋给另一个结构变量时会发生什么?计算 机会创建一个􏲕新的结构副本,也就是说,计算机需要再分配一 块存储器空间,大小和原来相同,然后把每个字段都复制过去。**


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/struct1.png)

## 4.嵌套定义结构

定义嵌套结构是为了应付更加复杂的情况，如下：(注意嵌套结构的顺序)



	//定义一个爱好规则结构
	typedef struct {
	    const char *species;        // 种类
	    const char *rules;          // 规则
	} Rules;

	//定义一个爱好结构
	typedef struct {
	    const char *what;   //爱好什么
	    Rules rl;    //规则
	} Like;


	//定义一个人的结构
	typedef struct {
	    const char *name;   // 名字
	    int age;            // 年龄
	    Like lk;     // 爱好
	} Person;


	int main(int argc, char *argv[]) {
	    Person beginman  = {"beginman", 24, {"游泳", {"有氧运动", "规则如下：蛙泳一个来回，水下憋气10分钟.."}}};
	    printf("%s is %i years old, he like %s(%s: %s)", beginman.name, beginman.age, beginman.lk.what, beginman.lk.rl.species, beginman.lk.rl.rules);
	    return 0;
	}

## 5.更新结构
如下实例：

	typedef struct {
	    const char *name;
	    int age;
	}turtle;


	void happy_birthday(turtle t) {
	    t.age=100;
	    printf("%i\n", t.age);
	}


	int main(int argc, char *argv[]) {
	    turtle xx = {"龟龟", 99};
	    //更改年龄
	    happy_birthday(xx);
	    printf("%i\n", xx.age);
	    return 0;
	}

试图更改乌龟的年龄：输出结果：

	100
	99

why？**在C中，参数按值传递给函数,当调用函数时，传入函数的值会赋值给形参**，

	void happy_birthday(turtle t) {
		... 
	}
	//myrtle结构会复制给形参
	happy_birthday(myrtle);

	//等效于：
	turtle t = myrtle;

**在C语言中,当为结构赋值时,计算机会复制结构的值。**，如果想把结构传给函数并在函数中更新值，则需要**结构指针**

**因为只有把变量在存储器中的位置告诉函数, 函数才能更新保存在那里的数据,才能更新变量**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/struct2.png)

所以上面的代码可以这样写：

	void happy_birthday(turtle *t) {
	    (*t).age=100;		//要把*放在变量􏶇􏺘前，因为你想得到指针所指向的值，这里括号很重要

	    //指针结构表示法
	    //t->age = t->age + 1
	    printf("%i\n", (*t).age);
	}

	....
	happy_birthday(&xx);

**注意：`(*t).age`不等于`*t.age`, `t->age`表示“由t指向的结构中的age字段”**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/struct3.png)

# 二.联合
当多个数据需要共享内存或者多个数据每次只取其一时，可以利用联合体(union),与结构不同，当定义联合时，计算机只为其中一个字段分配空间

在C Programming Language 一书中对于联合体是这么描述的：

- 联合体是一个结构；
- 它的所有成员相对于基地址的偏移量都为0；
- 此结构空间要大到足够容纳最"宽"的成员；
- 其对齐方式要适合其中所有的成员；

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/union.png)

	union U {
        char s[9];  // 占9个字节
        int n;      // 占4个字节
        double f;   // 占8个字节
    };
    printf("sizeof:%i", sizeof(union U));   // 16

这里定义了一个联合U,最大占9个字符，所以该联合最宽应该是9，但为啥是16呢，这里存在**字节对齐**的问题，9既不能被4整除，也不能被8整除。因此补充字节到16，这样就符合所有成员的自身对齐了。从这里可以看出**联合体所占的空间不仅取决于最宽成员，还跟所有成员有关系，即其大小必须满足两个条件：1)大小足够容纳最宽的成员；2)大小能被其包含的所有基本数据类型的大小所整除。**

参考:[浅谈C语言中的联合体](http://www.cnblogs.com/dolphin0520/archive/2011/10/03/2198493.html)

## 1.使用联合

**(1):保存第一个字段的值：**

	quantity q = {4};

**(2):指定初始化器:按名设置联合字段的值**

	quantity q = {.weight=1.5};	//

**(3).点表示法**

	quantity q;			// 创建联合变量
	q.volume = 4.3;		// 设置字段的值

对于结构的初始化，注意第三种情况：

	// 成功
	sms m = {2.0, 1.0, {0.7}}; 

	//失败
	sms m;
	m = {2.0, 1.0, {0.7}};

因为**`{}`符号结构要和结构声明写在一行，编译器才知道是结构，否则表示数组**

# 三.枚举
**可以在联合中保存各种可能的值，但是保存以后就无法知道它的类型，如果需要记录联合中保存的值类型，则需要枚举**

	// 枚举所有可能的颜色
	enum colors {RED, GREEN, PUCE};		// 值以逗号分隔

用`enum colors` 定义的变量只能设为列表中的几个关键字：

	enum colors myColor = RED;

如下水果订单实例：

	// 设置单位，枚举类型
	typedef enum {
	    COUNT,      // 个数
	    POUNDS,     // 磅
	    PINGS       // 品脱
	} unit_of_measure;

	// 数量
	typedef union {
	    short count;
	    float weight;
	    float volume;
	} quantity;

	// 水果订单
	typedef struct {
	    const char *name;
	    const char *country;
	    quantity amount;                // 总计
	    unit_of_measure units;          // 单位
	} fruit_order;

	void display(fruit_order order) {
	    if( order.units== PINGS) {
	        printf("%2.2f pings of %s\n", order.amount.volume, order.name);
	    } else if (order.units == POUNDS) {
	        printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
	    } else {
	        printf("%i %s\n", order.amount.count, order.name);
	    }
	}

	int main(int argc, char *argv[]) {
	    fruit_order apples = {"apples", "China", .amount.count = 144, COUNT};
	    fruit_order strawberries = {"strawberries", "USA", .amount.weight=17.6, POUNDS};
	    fruit_order oj = {"orange", "China", .amount.volume=10.5, PINGS};
	    
	    display(apples);
	    display(strawberries);
	    display(oj);
	    return 0;
	}

*NiMa*, 枚举这么NB的东西讲的也太少了把。。。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/hehe.jpg)

[**C语言详解 - 枚举类型**](http://www.cnblogs.com/jcsu/articles/1299051.html), 这篇文章讲得不错：

	enum DAY
	{
	      MON=1, TUE, WED, THU, FRI, SAT, SUN
	};

- 枚举型是一个集合，集合中的元素(枚举成员)是一些命名的整型常量，元素之间用逗号,隔开。
- DAY是一个标识符，可以看成这个集合的名字，是一个可选项，即是可有可无的项。
- 第一个枚举成员的默认值为整型的0，后续枚举成员的值在前一个成员上加1。
- 可以人为设定枚举成员的值，从而自定义某个范围内的整数。
- 枚举型是预处理指令#define的替代。
- 类型定义以分号;结束。


# 四.位操作

有时候只想保存一位，如1或0, 如果用`short`或`int`代替则就会多占用空间，于是**位字段(bitfield)**就出现了。

注意：**C不支持二进制字面值，支持16进制**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/note1.png)




