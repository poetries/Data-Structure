/*
        函数【C语言的第二个重点】
  1、为什么需要函数：
                        避免了重复性操作
                        有利于程序的模块化
  2、什么叫做函数
                        逻辑上：能够完成特定功能的独立代码块
                        物理上：能够接收数据 也可以不接收数据  能够对接收的数据处理  能够将数据处理的结果返回【也可以不返回任何值】
                        总结：函数是个工具，他是为了解决大量类似问题设计的，函数可以当做黑匣子
  3、如何定义函数
                    函数的返回值   函数的名字（函数的形参列表）
                    {
                        函数的执行体
                    
                    }
                函数定义本质是详细描述函数之所以能够实现特定功能实现的方法
                return  表达式的含义：
                                    1> 终止被调函数，向主调函数返回表达式的值 
                                    2> 如果表达式为空则只终止函数 不向被调函数返回任何值
                                    break是用来终止循环和switch  而return是用来终止函数的 
                          举例：
                          void f()  //前面是void  return后面不能加任何返回值
                          {
                            return;//用来终止函数 不向被调函返回值
                          }
                          int f()
                          {
                            return 10;//第一：终止函数  第二：向主调函数返回10
                          }
                函数返回值的类型也称为函数的类型 如果函数名前面的返回值类型和函数执行体中的return表达式的类型不同的话  
                最终函数返回值的类型以函数名前的类型为准
  4、函数的分类
                有参函数  无参函数
                有返回值函数  无返回值函数
                库函数   用户自定义函数
                值传递函数  地址传递函数
                普通函数  主函数（main函数）
                一个程序必须有且只能有一个主函数  主函数可以调用普通函数  普通函数不能调用主函数
                普通函数可以相互调用
                主函数是程序的入口，也是程序的出口
  5、注意的问题
                函数调用和定义的顺序：
                            如果函数调用写在了函数定义的前面 必须加函数前置声明  
                            
                              函数前置声明的作用：1> 第一个告诉编译器即将可能出现的若干个字母代表的是一个函数
                                                  2> 告诉编译器即将可能出现的若干字母所代表的函数的形参和返回值的具体情况
                                                  3> 函数声明是一个语句，末尾加分号
                                                  4> 对库函数的声明是通过#include来实现的
                形参和实参：
                            个数相同  位置一一对应 数据类型必须相互兼容
    
                如何在软件开发中合理地设计函数来解决实际问题：
                                                                一个函数的功能尽量独立单一  多学习 多模仿牛人的做法
                函数是C语言的基本单位 类是c# Java c++的基本单位
  6、常用的系统函数
                    double sqrt(double x) x的平方根
                    int abs(int x)  x的绝对值
  7、专题
            递归：（理解栈-->先进后出）
  变量的作用域和存储方式：
            
                            按作用域分：全局变量:在所有函数外部定义的变量
                                                 全局变量使用范围-->从定义位置到整个程序结束
                                        局部变量:在一个函数内部定义的变量或者是形参
                                                局部变量使用范围-->只能在本函数内部使用
                                                    void f(int i)
                                                    {
                                                        int j;
                                                    }
                            全局变量和局部变量命名冲突问题：
                                                            在一个函数内部如果定义的局部变量的名字和全局变量的名一样时，局部变量会屏蔽全局变量
                            按变量的存储方式：静态变量
                                              自动变量
                                              寄存器变量
//函数的例子
#include<stdio.h>
void max1(int i,int j)//max1函数功能找最大值  并且对最大值进行处理
{
    if(i>j)
        printf("%d\n",i);
    else
        printf("%d\n",j);
}
int max2(int i,int j)//max2功能 寻找最大值  处理方式交给main函数处理
{
    if(i>j)
        return i;
    else
        return j;
}
void main()
{
    int a,b,c,d,e,f;
    a = 1,b= 2 ,c = 3, d = -5, e = 10, f = 100;
//	max(a,b);
//	max(c,d);
//	max(e,f);
    printf("%d\n",max2(a,b));
    printf("%d\n",max2(c,d));
    printf("%d\n",max2(e,f));
}
#include<stdio.h>
int f(void)  //void表示该函数不能接受数据 int表示该函数返回值类型是int类型
{
    return 10;  //向主调函数返回10
}
void g(void)  //函数名前面表示该函数没有返回值
{
//	return 10;//error 与前面的void相矛盾
}
void main()
{
    int j = 88;
    j = f();
    printf("%d\n",j);
}
//到底什么是函数的类型
#include<stdio.h>
int f()
{
    return 10.5;//因为函数返回值类型是int 最终函数返回值是10而不是10.5
}
void main()
{
    int i = 99;
    double x = 6.6;
    x = f();
    printf("%lf\n",x);
}
//return和break的区别
#include<stdio.h>
void f(void)
{
  int i;
  for(i = 0;i<5;i++)
  {
     printf("大家辛苦了\n");
     return;//终止整个函数
    //break;//终止循环
  }
  printf("同志们好!\n");
}
void main()
{
    f();
}
//判断一个数字是否为素数(只能被1和本身整除)
#include<stdio.h>
bool Isprime(int val)//素数  bool布尔类型
{
    int i;
    for(i = 2;i<val;++i)
    {
        if(val%i == 0)
            break;
    }
    if(i == val)
        return true;
    else
        return false;
}
void  main()
{
    int m;
    
    printf("请输入一个数：");
    scanf("%d",&m);
    if(Isprime(m))   //Isprime(m)这个函数返回的是true  则输出yes
        printf("Yes!\n");
    else
        printf("No!\n");
    
    
}
  
//如何合理设计函数   求1到某个数字之间的所有素数并将其输出  用main函数有局限性  代码重用性不高
#include<stdio.h>
bool Isprime(int m);
void travel(int n)//函数功能 把1到n之间所有的素数在显示器上输出
{
    int i;
    for(i = 2;i<n;++i)
    {
        if(Isprime(i))
            printf("%d\n",i);
    }
    
}
bool Isprime(int m)//函数功能判断m是否是素数 是返回true
{
        int i;
        for(i = 2;i<m;++i)
        {
            if(m%i == 0)
                break;
        }
        if(i == m)
            return true;
        else
            return false;
}
void main()
{
    int val;
    int i,j;
    printf("请输入一个数字：");
    scanf("%d",&val);
    
    travel(val);
    
}
    */
//全局变量和局部变量
#include<stdio.h>
void main()
{
    int i;
}
