/**
  流程控制（学习C语言的转折点）
1、什么是流程控制
    程序代码的执行顺序
2、流程控制的分类
    顺序执行：
    选择执行：
        定义：某些代码可能执行 也可能不执行 有选择的执行某些代码
        分类：
            if 
                1、if最简单的用法 
                    格式：if（表达式）
                            语句
    ·				功能：如果表达式为真执行语句，为假语句不执行
                2、if的范围问题
                        if(表达式)
                        {
                            语句A;
                            语句B;
                        }
                        if只能控制语句A的执行，无法控制语句B的执行，如何if想控制多个与局部的执行用中括号括起来
                            
                3、if...else用法
                4、if...else if..else用法
                5、C语言对真假的处理
                        非零是真
                        零是假
                6、if常见问题解析
                        空语句的问题
                        if(表达式1)
                            A;
                        else if(表达式2)
                            B;
                        else
                            C;
                        即便表达式1和2都成立，也只执行A
    循环执行：
                定义：某些代码会被重复执行
                分类：
                        for
                             多个for循环的嵌套使用执行顺序问题【重点】
                                for(1;2;3)          //执行顺序1 -->2-->4-->5-->A-->6-->5(不成立)-->3--2(不成立)-->B
                                    for(4;5;6)
                                        A;
                                        B;
                        while
                            
                              1、执行的顺序
                                            
                                            格式：
                                                    while（表达式）
                                                            语句；
                              2、与for的相互比较
                                                for(1;2;3)
                                                     	A;   
                                                        
                                                等价于
                                                1
                                                while(2)
                                                {
                                                    A;
                                                    3;
                                                 }
                                FOR和while可以相互转换，但for逻辑性更强，推荐使用for
                              3、什么时候使用while，什么时候使用for：用多了自然就知道了
                                            
                        do..while：
                                    格式：
                                    do
                                        {
                                            .....
                                        } while(表达式)
                                    
                                    主要是用于人机交互，do..while：并不等价于for和while
                        switch：
                                格式：switch(表达式)
                                            {
                                                case 常量表达式1：语句1；
                                                    break;
                                                case 常量表达式2：语句2；
                                                    break;
                                                default：语句3；
                                                    break;
                                              }
                break和continue
                break:
                        break如果用于循环是用来终止循环
                        break如果用于switch，用于终止
                        break不能直接用于if，除非if属于循内部的一个语句
                        例子1：
                        for(i = 0;i<3;++i)
                        {
                            if(3>2)
                                break;  //break虽然是if内部的语句，但break终止的却是外部的for循环
                            printf("嘿嘿!\n");  //永远不会输出
                        }
                        举例2：
                            for(i = 0;i<3;++i)
                                {
                                    for(j = 1;j<4;++j)
                                        break;   //break只能终止距离它最近的循环
                                    
                                    printf("同志们好!\n");
                                }
                            在多层switch嵌套中，break只能终止距离它最近的switch
                continue：（针对的是循环 if不是循环）
                            用于跳过本次循环余下的语句，转去判断是否需要执行下次循环
                            for(1;2;3)
                            {
                                A;
                                B;
                                continue;//如果执行该语句，则执行完该语句后，会执行语句3，C和D不会被执行
                                C;
                                D;
                            }
                            while(表达式)
                            {
                                A;
                                B;
                                continue;//如果执行该语句，则执行完该语句后，会执行表达式，C和D不会被执行
                                C;
                                D;
                                
                            }
                        while(flag)
                        {
                            flag = 0;
                              for（j= 0；j<n-1;++j）
                            {
                                temp=a[j];
                                a[j]=a[j+1];
                                continue;//会跳去执行++j
                                a[j+1] = temp;
                                flag = 1;
                                break;   //会跳出for循环，转去执行下面的break
                            }
                        }
                        break；
                        do
                        {
                            if(i%2)
                        {
                            i++;
                            continue;//会跳到下面执行while(i<5)
                        }
                            i++;
                            s+=i;
                        }while(i<5);
            
  强制类型转换：
  
            格式： （数据类型）（表达式）
            
            功能：把表达式强制转换给前面转换的类型
                //  sum = sum + 1/(float)i  --->ok
                //  sum = sum + (float)(1/i) --->不对的
                //  sum = sum + 1.0/i  更简洁
  浮点数的存贮所带来的问题:
                 float double 都不能保证可以精确地存储一个小数
                    举例：
                        有一个浮点型变量X 如何判断x是零
                        if(|x-0.000001|<0.00001)   //  如何x和一个非常小的值相减
                            是零：
                        else
                            不是零；
                        为什么循环中更新的变量不能定义成浮点型
                    
  
//if最简单的程序
#include<stdio.h>
void main()
{
    if (1)
        printf("aaaa\n");//会输出
    if (0)
        printf("bbbb\n");//不会输出
    if (0 == 0)
        printf("cccc\n");//会输出
}
//if的范围问题
#include<stdio.h>
void main()
{
    if(1>2)
        printf("AAAA\n");
        printf("BBBB\n");
}
//if..else的用法
#include<stdio.h>
void main()
{
    int i,j;
    
    printf("请输入i，j的任意值：");
    scanf("%d %d",&i,&j);
    if(i>j)
        printf("i大于j\n");
    else
        printf("i小于j\n");
}
//分数的等级程序
#include<stdio.h>
void main()
{
    float score;
    printf("请输入您的考试成绩：");
    scanf("%f",&score);
    if (score>100)
        printf("这就是做梦!\n");
    else if (score >=90 && score<=100)//不能写成90<=score<=100
        printf("优秀\n");
    else if(score>=80 && score<=90)
        printf("良好\n");
    else if (score>=60 && score<80)
        printf("及格\n");
    else if(score>0 && score<=60)
        printf("不及格，请继续努力\n");
    else
        printf("您输入的分数过低，请重新输入\n");
}
 
//if举例 互换两个数
#include<stdio.h>
void main()
{
    int i = 10;
    int j = 40;
    int t;
//	i = j;//无法完成i和j的互换
//	j = i;
    t = i;
    i = j;
    j = t;
    printf("i = %d,j = %d\n",i,j);
}
 
//对任意三个数进行赋值
#include<stdio.h>
void main()
{
    int a,b,c,t;
    printf("请输入三个整数：");
    scanf("%d %d %d",&a,&b,&c);
    //编写代码完成a是最大值 b是中间值 c是最小值
    if (a <b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (a<c)
    {
        t = a;
        a = c;
        c = t;
    }
    if (b <c)
    {
        t = b;
        b = c;
        c = t;
    }
        printf("%d %d %d\n",a,b,c);
}
//为什么需要for循环
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    for (i = 1;i<=100;++i)
        sum = sum + i;
    printf("sum = %d\n",sum);
    
}
   
 
//求1-100之间所有的能被3整除的数之和
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    for (i = 3;i<=10; ++i)
    {
        if(i%3 == 0)
          sum = sum + i;
        printf("sum = %d\n",sum);
    }
        
}
  
  
//1到100奇数之和
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
        sum += i;
    }
    printf("sum = %d\n",sum);
}
 
//1到100奇数个数
#include<stdio.h>
void main()
{
    int i;
    int cnt = 0;//个数cnt
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
            ++cnt;
    }
    printf("cnt = %d\n",cnt);
}
   
//1到100奇数平均值
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    int cnt = 0;
    float avg;
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
        {
            sum += i;
            ++cnt;
        }
    }
    avg = 1.0*sum / cnt;  //1.0默认double
    printf("sum = %d\n",sum);
    printf("cnt = %d\n",cnt);
    printf("avg = %f\n",avg);
}
 
//循环的举例  1到100奇数之和 1-100偶数之和
#include<stdio.h>
void main()
{
    int i;
    int sum1 = 0; //奇数和
    int sum2 = 0; //偶数和
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
            sum1 = sum1 + i;
        
        else
            sum2 = sum2 + i;
    }
    printf("sum1 = %d\n",sum1);
    printf("sum2 = %d\n",sum2);
}
//求1+1/2+1/3+...+1/100之和
#include<stdio.h>
void main()
{
    int i;
    float sum = 0;
    for(i = 1;i<101; ++i)
    {
        sum = sum + 1.0/i; //强制类型转换  格式 （数据类型）（表达式）功能：把表达式强制转换给前面转换的类型
                                //  sum = sum + 1/(float)i  --->ok
                                //  sum = sum + (float)(1/i) --->不对的
                                //  sum = sum + 1.0/i  更简洁
    }
    printf("sum = %f\n",sum);
}
//浮点数的存贮所带来的问题
#include<stdio.h>
void main()
{
    float i;
    float sum = 0;
    for(i = 1;i<101; ++i)
    {
        sum = sum + 1.0/i; 
    }
    printf("sum = %f\n",sum);
}
//多个for循环嵌套使用实例1
#include<stdio.h>
void main()
{
    int i,j;
    for(i = 0; i < 3;++i)
        for(j = 2;j < 5;++j)
            printf("哈哈\n");
        printf("嘻嘻\n");
}
  
  
//多个for循环嵌套使用实例2
#include<stdio.h>
void main()
{
    int i,j;
    for(i = 0;i < 3;++i)
    {
        printf("1111!\n");
        for(j = 2;j < 5;++j)
        {
            printf("222!\n");
            printf("3333!\n");
        
        }
        printf("444!\n");
        
    }
}
//1+2+....+100两种写法
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
 //for循环写法
//	for(i = 1;i<101;++i)
//		sum = sum + i;
//while写法
    i = 1;
    while(i < 101)
    {
        sum = sum + i;
        ++i;
    }
    printf("sum = %d\n",sum);
}
    
//从键盘输入一个数字，如果该数字是回文数返回yes  否则返回no  回文数：正着写和倒着写都一样  比如：123 12321都是回文数
#include<stdio.h>
void main()
{
    int val;//存放待判断的数字
    int m;
    int sum = 0;
    printf("请输入您需要判断的数字：");
    scanf("%d",&val);
    m = val;
    while(m)
    {
        sum = sum * 10 +m%10;
        m /=10;
    }
    //采用试数法解决程序看不懂：
    //1、m=1234 成立
    //	 sum=0*10+1234%10=4
    //	  m=m/10=123;
     //2、m=123 成立
    //	 sum=4*10+123%10=43
    //	  m=m/10=12;
    //3、m=12 成立
    //	 sum=43*10+12%10=432
    //	  m=m/10=1;
    
    //4、m=1 成立
    //	 sum=432*10+1%10=4321
    //	  m=m/10=0;
    //5、m=0  不成立
        
    //	 最终sum = 4321
    if(sum == val)
        printf("yes\n");
    else
        printf("no\n");
}
//斐波拉契序列 1 2 3 5 8 13 21 34 
#include<stdio.h>
void main()
{
    int n;
    int f1,f2,f3;
    int i;
    f1 = 1;
    f2 = 2;
    printf("请输入您需要求的项的序列：");
    scanf("%d",&n);
    if(1==n)
    {
        f3 = 1;
    }
    else if(2 ==n)
    {
        f3 = 2;
    }
    else
    {
        for(i = 3;i<=n;++i)
        {
            f3 = f1 +f2;
            f1 = f2;
            f2 = f3;
            //试数：
                //	1> i=3 3<=6 成立
                //	f3=1+2=3   f1=f2=2  f2=f3=3  ++i  i=4
                //	2> i=4 4<=6 成立
                //	f3=2+3=5   f1=f2=3  f2=f3=5  ++i  i=5
                //	3> i=5 5<=6 成立
                //	f3=3+5=8   f1=f2=5  f2=f3=8  ++i  i=6
                //	4> i=6 6<=6 成立
                //	f3=5+8=13   f1=f2=8  f2=f3=13  ++i  i=7
                //	5> i=7  7<=6 不成立
    
        }
    }
    printf("%d\n",f3);
}
   
//switch的用法
#include<stdio.h>
void main()
{
    int val;
    printf("请输入您要进入的楼层：");
    scanf("%d",&val);
    switch(val)
    {
       case 1:
           printf("1层开!\n");
           break;
       case 2:
           printf("2层开!\n");
           break;
       case 3:
           printf("3层开!\n");
           break;
      
       default:
           printf("没有这一层!\n");
           break;
    }
}
//break用法
#include<stdio.h>
void main()
{
    int i;
    switch(2)
    {
        case 2:
            printf("哈哈哈!\n");
            break;
    }
    for(i = 0;i<3;++i)
    {
        if(3>2)
            break;  //break虽然是if内部的语句，但break终止的却是外部的for循环
        printf("嘿嘿!\n");
    }
}
//break用于多个for循环
#include<stdio.h>
void main()
{
    int i,j;
    
    for(i = 0;i<3;++i)
    {
        for(j = 1;j<4;++j)
            break;   //break只能终止距离它最近的循环
        
        printf("同志们好!\n");
    
    }
}
    **/
   #include <stdio.h>
   main()
    {  int  k, j, s;
         
       for( k=2; k<6; k++,k++ )
       {  
           
        
             s=1;
          for (j=k; j<6; j++ ) 
              s+=j;
       }
       printf("%d\n" , s );
    }
