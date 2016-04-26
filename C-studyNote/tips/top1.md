第一章让我们能明白如下：

- 写一个简单的hello,world程序
- C咋运行的，咋工作的
- 理解第一个函数：main()函数
- 如何编译运行：弄清楚gcc命令
- 所有语言最最最常用的：C 字符串学习
- 涉及到简单的数组
- 怎么让它显示出来：printf函数打印你想要的
- 流程控制语句if和布尔表达式让你的程序多样选择
- switch语句多多多选择
- 循环:while,do-while,以及风骚的for
- 退出循环：break VS continue
- 小技巧：链式赋值


# 一.C工作方式
![](http://beginman.qiniudn.com/compile.jpg)

具体可我之前写的参考[《深入理解计算机系统》笔记1：计算机漫游](http://beginman.cn/读书笔记/2015/05/16/computer/)

# 二.main()函数
参考我之前写的[理解C main函数](http://beginman.cn/c/c++/2015/04/21/c-main/),这里总结几点：

- 返回值总为int(早期ANSI C标准,main()函数可以是void类型，但在C99中必须int类型)
- 返回值0表示successed, 其他值表示出了问题

# 三.gcc
gcc是GNU推出的基于C/C++的编译器,俺们来看看它的命令

一步到位的用法是：

	gcc hello.c -o hello

如上上图所示，C编译过程分为：预编译、编译、汇编、链接，接下来我们分别瞅瞅：

注意：`-o`是输出

**预编译：**

	gcc -E hello.c -o hello.i 或 gcc -E hello.c

**编译：**
	
	#将hello.i预编译文件编译成hello.s汇编文件
	gcc -S hello.i -o hello.s

**汇编：**
	
	#将汇编文件hello.s通过gas汇编成目标文件hello.o
	gcc -c hello.s -o hello.o

**链接：**
	
	#将目标文件hello.o
	gcc hello.o -o hello

如果编译多个文件可以这样：

	gcc test1.c test2.c -o test

了解了gcc了，可以跑我们的程序了
# 四.字符串
现在可以看看之前写的[c语言字符数组与字符串的使用详解](https://github.com/BeginMan/BookNotes/blob/master/C/CJewelry/c语言字符数组与字符串的使用详解.md)了。这里就总结几点：

- 字符串是字符数组
- `\0`字符在字符串末尾表示end
- 单引号表示单个字符，双引号表示字符串
- 相比数组定义字符串(最后一位加`\0`), 用双引号定义的字符串叫**字符串字面值**，比较方便易懂
- 字符字面值与字符数组的区别：字符字面值是一个常量，不可更改！！

# 五.printf函数
printf格式化输出，语法格式如下：

	[标志][输出最小宽度][.精度][长度]类型。

## 1 类型
![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/printf_1.png)

## 2.标志

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/printf_2.png)

## 3.输出最小宽度
十进制表示， 多则补空格或0， 少则实际输出

## 4.精度
精度格式符以`.`开头，后跟十进制整数。

- 如果输出数字，则表示小数的位数；
- 如果输出的是字符，则表示输出字符的个数；
- 若实际位数大于所定义的精度数，则截去超过的部分。

## 5.长度
长度格式符为h、l两种:

- h表示按短整型量输出
- l表示按长整型量输出。

如下实例：

	int main() {
	    int a=15;
	    float f=12.6893;
	    printf("a(%%d)=%d\n", a);   // (1):a(%d)=15
	    printf("a(%%5d)=%5d\n", a); // (2):a(%5d)=   15
	    printf("a(%%o)=%o\n", a);   // (3):a(%o)=17
	    printf("a(%%x)=%x\n", a);   // (4):a(%x)=f
	    
	    printf("f(%%f)=%f\n", f);   // (5):f(%f)=12.689300
	    printf("f(%%5f)=%5f\n", f); // (6):f(%5f)=12.689300
	    printf("f(%%5.3f)=%5.3f\n", f); // (7): f(%5.3f)=12.689
	    printf("f(%%e)=%e\n", f);    // (8):f(%e)=1.268930e+01
	    
	    return 0;
	}
# 六.流程控制
## 1.if

	if (条件语句) {
		....
	} else if (条件语句) {
		...
	}...
	else {
		....
	}

**可以省略花括号：用Tab**

	if ()
		....
	else if ()
		....
	else
		....

## 2.switch
语法如下：

	switch(表达式){ 
	    case 常量表达式1:  语句1;
	    case 常量表达式2:  语句2;
	    … 
	    case 常量表达式n:  语句n;
	    default:  语句n+1;
	}

注意：

- `break`要加上，用于跳出switch语句
- 在case后的各常量表达式的值不能相同，否则会出现错误
- 在case后，允许有多个语句，可以不用{}括起来。
- 各case和default子句的先后顺序可以变动，不会影响程序执行结果
- default子句可以省略
- **不能用switch检查字符串或任意形式的数组，只能检查值**

# 七.循环
## 1.while, do while

while语法：	

	while(循环条件) 语句

循环体如包括有一个以上的语句，则必须用{}括起来，组成复合语句；如果单个语句则可以省略花括号

	int main() {
	    int i=1,sum=0;
	    while (i<=100) {
	        sum+=i;
	        i++;
	    }
	    printf("sum=%d\n", sum);    //5050
	    return 0;
	}

do-while语法：

	do
        语句
    while(表达式);

**先执行循环中的语句，然后再判断表达式是否为真， 所以它至少执行一次**


	int i=1,sum=0;
    do {
        sum+=i;
        i++;
    }while (i<=100);

## 2.for

语法如下：

	for(表达式1; 表达式2; 表达式3)  语句
	或这样理解：
	for(循环变量赋初值; 循环条件; 循环变量增量)  语句


![](http://c.biancheng.net/cpp/uploads/allimg/120129/1-120129205416332.gif)

来运行这个看看：

	int main() {
	    for (; ; ) {
	        printf("我操你大爷！");
	    }
	    return 0;
	}

哈哈哈，看到效果了把。

**使用for语句应该注意：**

- for循环中的“表达式1（循环变量赋初值）”、“表达式2(循环条件)”和“表达式3（循环变量增量）”都是选择项，即可以缺省，但分号(;)不能缺省。
- 省略了“表达式1（循环变量赋初值）”，表示不对循环控制变量赋初值。
- 省略了“表达式2(循环条件)”，则不做其它处理时便成为死循环
- 省略了“表达式3(循环变量增量)”，则不对循环控制变量进行操作，但可在内部操作
- 3个表达式都可以省略相当于：`while(1)`
- 表达式1和表达式3可以是一个简单表达式也可以是逗号表达式, 如： `for( i=0,j=100; i<=100; i++,j-- )  k=i+j;`
- 表达式2一般是关系表达式或逻辑表达式，但也可是数值表达式或字符表达式，只要其值非零，就执行循环体。例如:`for( i=0; (c=getchar())!=’\n’; i+=c );`

# 八.退出循环：break VS continue

>当break语句用于do-while、for、while循环语句中时，可使程序**终止循环而执行循环后面的语句**，通常break语句总是与if语句联在一起，即满足条件时便跳出循环。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/break.jpg)

使用break注意事项：

- break语句对if-else的条件语句不起作用
- 在多层循环中，一个break语句只向外跳一层。

>continue语句的作用是**跳过循环体中剩余的语句而强行执行下一次循环**。continue语句只用在for、while、do-while等循环体中，常与if条件语句一起使用，用来加速循环。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/continue.jpg)


# 九.链式赋值
没法总结了，偷个懒截个图留个念装个B

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/lianshifuzhi.png)


