/**
    指针【重点难点】（C语言的灵魂）
指针：
    【指针的重要性】：
    表示一些复杂的数据结构
    快速的传递数组
    使函数返回一个以上的值 
    能直访问硬件
    能方便处理字符串
    是理解面向对象语言中应用的基础
    总结：指针是C语言的灵魂
指针的定义：
    地址
    
        内存单元的编号
        从零开始的非负数
        范围：4G【0--4G-1】
    指针
    
        指针就是地址  地址就是指针
        指针变量就是存放内存单元编号的变量，或者说指针变量就是存放地址的变量
        指针的本质就是一个操作受限的非负数
    
指针是地址 地址是内存单元的编号
指针变量就是存放地址的变量
 
 
指针就是地址 地址就是指针
地址就是内存单元的编号（指针就是内存单元的编号）
指针变量是存放地址的变量
附注：
*号的含义：
    1>乘法
    2>定义指针变量
        int *p  定义了一个名字叫p的变量，int* 表示p只能存放int变量的地址
    3>指针运算符
        该运算符放在已经定义好的指针变量的前面
        如果p是一个已经定义好的指针变量
        则* p表示以p的内容为地址的变量
【指针】：
    【指针的重要性】：
    表示一些复杂的数据结构
    快速的传递数据，减少了内存的耗用【重点】
    使函数返回一个以上的值【重点】 
    能直访问硬件
    能方便处理字符串
    是理解面向对象语言中应用的基础
    总结：指针是C语言的灵魂
指针的定义：
    地址	
        内存单元的编号
        从零开始的非负数
        范围：4G【0--4G-1】
    指针	指针就是地址  地址就是指针
        指针变量就是存放内存单元编号的变量，或者说指针变量就是存放地址的变量
        指针的本质就是一个操作受限的非负数
        
指针的分类：
1、基本类型指针
如果通过被调函数修改主调函数普通变量的值
1>实参必须为该普通变量的地址
2>形参必须为指针变量
3>在被调函数中，通过(*形参 = ..)的方式就可修改主调函数相关变量的值
    
2、指针和数组
指针和一维数组：
    一维数组名是个指针常量，它存放的是一维数组第一个元素的地址
    下标和指针的关系
        如果p是指针变量，则
                p[i]永远等价于*(p+i)
    
确定一个一维数组需要几个参数【如果一个函数要处理一个一维数组，则需要接受该数组的那些信息】
 需要两个参数：
    数组第一个元素的地址
    数组的长度
    指针变量的运算:
        指针变量不能相加，不能相乘，也不能相除
        如果两个指针变量指向的是同一块连续空间中的不同存储单元，则这两个指针变量才可以相减
    一个指针变量到底占多少个字节：
            预备知识：
            sizeof（数据类型）
            功能：返回值就是该数据类型所占的字节
            例子：sizeof（int） = 4 sizeof（char） = 1
                     sizeof（double）= 8 
            
                sizeof(变量名)
                功能：返回值是该变量所占的字节数
                
        假设p指向char类型（1个字节）
        假设q指向char类型（4个字节）
        假设r指向double类型（8个字节）
        p q r本身所占的字节是否一样？
            答：p q r本身所占的字节数是一样的
        总结：
            一个指针变量，无论它指向的变量占几个字节，该指针变量本身只占四个字节
            
            一个变量的地址是使用该变量字节的地址来表示
指针和二维数组（暂时不看）：
    
3、指针和函数
4、指针和结构体
5、多级指针
专题：
    动态内存分配【重点难点】
           传统数组的缺点：
        1>数组长度必须事先制定，且只能是常整数，不能是变量
            例子：int a[2]//ok
                  int len = 5;int a[len]  //error
        2>传统形式定义的数组，该数组的内存程序员无法手动释放它，它只能在本函数运行完毕时由系统自动释放
         数组一旦定义，系统就会为该数组分配的存储空间就会一直存在，除非数组所在的函数运行结束
        3>数组的长度不能在函数运行过程中动态的扩充
        4>A函数定义的数组在A函数运行期间可以被其他函数使用，但A函数运行完毕后，A函数的数组将无法再被其他函数使用
        传统方式定义的数组不能跨函数使用
            
            
           为什么需要动态分配内存
                    动态数组很好的解决了传统数组的缺陷，传统数组也可叫静态数组
          动态内存分配举例__动态数组的构造
    
          静态内存和动态内存的比较【重点】
                    静态内存是由系统自动分配，由系统自动释放
                    静态内存是在栈中分配的
          跨函数使用内存的问题
#include<stdio.h>
 void main()
{
    int  *p;
 //p是变量名字，int*表示变量存放的是int类型变量的地址
//int *p不表示定义了一个名字叫做*p的变量
//int *p这样理解：p是变量名，p变量的数据类型是int类型
//所谓int * 类型就是存放int变量地址的类型
    int  i = 3;
    int j = 3;
    p = &i;  //OK
//1> p保存了i的地址，因此p指向i
//2> p不是i，i也不是p，修改p的值不影响i的值，反之一样
//3> 如果一个指针变量指向某个普通变量，则*指针变量就全完等同于普通变量：例子： 如果p是一个指针变量，并且p存放了普通变量i的地址，则p指向了指针变量i
//*p就完全等同于i
//或者说：在所有出现*p的地方都可以替换成i
//	在所有出现i的地方都可以替换成*p
//*p就是以p的内容为地址的变量
//	p = i;  //error ，因为类型不一致，p只能存放int类型变量的地址，不能存放int类型
    j = *p;
    printf("i = %d,j = %d\n",i,j);
}
//指针常见错误1
 #include<stdio.h>
void main()
{
    int *p;
    int i = 5;
    
    *p = i;  //不能这样写 但不报错 因为*p是int类型  i也是int类型
    printf("%d\n",*p);
}
//指针常见错误2
#include<stdio.h>
void main()
{
    int i = 5;
    int *p;
    int *q;
    p = &i;
//	*q = p;    //不能这样写语法编译出错 类型不一致 因为*q是int类型 而p是int *类型
//	*q = *p;  //error
//	p = q;   //q是垃圾值，q赋给p，p也变成垃圾值，q的空间是属于本程序的，所以本程序可以读写q的内容，但如果q内部是垃圾值，则本程序不能读写*p的内容
         	//因为此时 *q所代表的内存单元的控制权限并没有分配给本程序
    printf("%d\n",*q);
}
  
//经典指针案例互换两个数字
#include<stdio.h>
//可以完成互换
void huhuan_3(int * p, int * q)
{
    int t; //如果要互换*p和*q的值，则p必须定义成int，不能定义成int*,否则语法出错
    
    t = *p;  // p是int*类型，*p是int类型
    *p = *q;
    *q = t;
}
//不能完成互换功能
void huhuan_2(int * p, int * q)
{
    int *t; //如果要互换p和q的值，t必须是int * 不能是int t 否则出错
    
    t = p;
    p = q;
    q = t;
}
//不能完成互换功能
void huhuan_1(int a,int b)
{
    int t;
    t = a;
    a = b;
    b = t;
        
}
void main()
{
    int a = 3;
    int b = 5;
    
    huhuan_3(&a,&b);
//	huhuan_2(&a,&b); //huhuan_2(*p,*q);是错误的，huhuan_2(a,b)也是错误的
//	huhuan_1(a,b);
//	t = a;
//	a = b;
//	b = t;
    printf("a = %d,b = %d\n",a,b);
}
//知识回顾
#include<stdio.h>
void main()
{
    int * p;//等价于int *p,也等价与int* p
    int i = 5;
    char ch = 'A';
    
    p = &i; //*p以p的内容为地址的变量
    * p = 99;
    
    printf("i = %d,*p = %d\n",i,*p);
    //p = &ch;//error
    //p = ch;//error
    //p = 5;//error
}
#include<stdio.h>
void g(int *p,int *q)
{
    *p = 1;
    *q = 2;
}
void main()
{
    int a = 3,b = 3;
    g(&a,&b);
    
    printf("%d %d\n",a,b);
    
}
  
//确定一个一维数组需要几个参数
#include<stdio.h>
//f函数可以输出任何一个一维数组的内容  确定一个数组需要两个参数(首地址和长度)
void f(int *app,int len)
{
    int i;
    
    for(i = 0;i<len;++i)
      printf("%d ",*(app+i)); //*app  *(app+1) *(app+2)   *（app+i）等价于app[i]  也等价于b[i]也等价于 *（b+i）
     printf("%d\n");
    
}
void main()
{
    int a[5] = {1,2,3,4,5};
    int b[6] = {-1,-2,-3,-4,-5,-6};
    int c[100] = {1,99,22,33};
    f(a,5);//a是 int *
    f(b,6);
    f(c,100);
    
        
}
#include<stdio.h>
void f(int *app ,int len)
{
    app[3] = 88;
}
void main()
{
    int a[5] ={1,2,3,4,5};
    
    printf("%d\n",a[3]);//4
    f(a,6);
    printf("%d\n",a[3]);//a[3]等价于*（a+3）等价于*(app+3)
}
//**输出结果**********4  88  Press any key to continue  *****
//复习1
#include<stdio.h>
void f(int *p)
{
    *p = 10;//i = 10
}
void main()
{
    int i = 5;
    f(&i);
    printf("i = %d\n",i);
}
   
//复习2
#include<stdio.h>
void outapp(int *app,int len)
{
    app[2] = 10;//app[2]== *(app+2)==*(a+2)==a[2]
}
void main()
{
    int a[5] = {1,2,3,4,5};
    printf("%d\n",a[2]);
    outapp(a,5);
    printf("%d\n",a[2]);
}
//******* 3   10   Press any key to continue  ******
//指针的相减    如果两个指针变量指向的是同一块连续空间中的不同存储单元，则这两个指针变量才可以相减
#include<stdio.h>
void main()
{
    int i  = 5;
    int j = 10;
    int *p = &i;
    int *q = &j;
    int a[5];
    p = &a[1];
    q = &a[4];
    printf("p和q所指向的单元相隔%d个单元\n",q-p);
    
}
   
//一个指针变量到底占多少个字节
#include<stdio.h>
void main()
{
    char ch = 'A';
    int i = 99;
    double x = 66.6;
    char *p = &ch;
    int *q = &i;
    double *r = &x;
    printf("%d %d %d\n",sizeof(p),sizeof(q),sizeof(r));
     
    
}
//动态内存分配举例__动态数组的构造   malloc函数的简单使用，malloc是memory（内存） allocate（分配）
#include<stdio.h>
#include<malloc.h>
void main()
{
    int i= 5;//分配了四个字节 静态分配
    int * p = (int *) malloc(4);
    //要使用malloc函数，要加malloc头文件
    //malloc函数只有一个形参，并且形参是整数类型
    //4表示请求系统为本程序分配4个字节
    //malloc函数只能返回第一个字节的地址
    //p本身所占的内存是静态分配的，p所指向的内存是动态分配的
    * p = 5;//*p所代表的就是一个int变量，只不过*p这个整形变量的内存分配方式和上面的i变量分配方式不同
    free(p); //表示把p所指向的内存释放掉 p本身的内存是静态的 不能由程序员手动释放，p本身的内存只能在p变量所在的函数运行终止时由系统释放
    printf("同志们好!\n");
    
}
  
//malloc用法
#include<stdio.h>
#include<malloc.h>
void f(int *q)
{	
    //*p = 200;//error
    //q = 200;//error	
    *q = 200;//ok
    //free(q);//error  把q所指向的内存释放  本语句必须注释 否则会导致下面的printf("%d\n",*p);出错
}
void main()
{
    int *p = (int *)malloc(sizeof(int));//sizeof（int）返回值是int所占的字节数
    *p = 10;
    printf("%d\n",*p);
    f(p);//p是int*类型
    printf("%d\n",*p);
}
//动态构造一维数组实例
#include<stdio.h>
#include<malloc.h>
void main()
{
    int a[5];//如int占用4个字节的话，则本数组共有20个字节，每4个字节被当成了一个int来使用
    
    int len;
    int *app;
    int i;
    
    //动态构造一维数组
    printf("请输入您要存放的元素个数：");
    scanf("%d",&len);
    app = (int * )malloc(4 * len);// 本行动态构造了一个一维数组 该一维数组名是app 数组长度是len 该数组的每个元素类型是int类型 其功能类似静态int app[len]
    //对一维数组进行操作  如：对动态一维数组进行赋值
    for( i = 0;i<len;++i)
        scanf("%d",&app[i]);
    //对动态数组进行输出
    printf("一维数组的内容是：");
    for(i = 0;i<len;++i)
        printf("%d\n",app[i]);
    free(app);//释放掉动态分配的数组
}
  
     
//多级指针
#include<stdio.h>
void main()
{
    int i = 10;
    int * p = &i;
    int ** q = &p;
    int *** r = &q;
    
    //r = &p;//因为r是int***类型 所以r只能存放int**类型变量的地址
    printf("%d\n",***r);
}
//跨函数使用内存
#include<stdio.h>
void f(int **q)//q是个指针变量，无论q是什么类型的指针变量，都只占4个字节
{
    int i= 100;
    //*q等价于p   q和**q不等价于p
    //*q = i;//error 因为 *q = i 等价于 p = i;
    *q = &i;//p =&i 
}
void main()
{
    int *p;
    f(&p);
    printf("%d\n",*p);
}
   */
//动态内存可以跨函数使用
#include<stdio.h>
#include<malloc.h>
void f(int **q)
{
    *q = (int * )malloc(sizeof(int));//sizeof(数据类型) 返回值是该数据类型所占的字节数	
     	//等价于 p = (int*)malloc(sizeof(int))
    //q = 5;//error
    //*q = 5;//error p = 5;
    **q = 5;//*p = 5
}
void main()
{
    int *p;
    f(&p);
    printf("%d\n",*p);
}
