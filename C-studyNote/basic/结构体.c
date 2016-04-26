/*
【结构体】
为什么需要结构体：
    为了表示一些复杂的事物，而普通的基本类型无法满足实际要求
什么叫结构体：
    把一些基本类型数据组合在一起形成的一个新的复合数据类型
如何定义一个结构体：
    3中方式：推荐使用第一种
//第一种方式  这只是定义了一个新的数据类型 并没有定义变量
struct Student
{
    int age;
    float score;
    char sex;
};
//第二种方式
struct Student2
{
    int age;
    float score;
    char sex;
}st2;
//第三种方式
struct 
{
    int age;
    float score;
    char sex;
}st3;
怎么去使用结构体变量：
    赋值和初始化	
        定义的同时可以赋初值
        如果定义完成后，则只能单个的赋初值
    如何取出结构体变量中的每一个成员【重点】
        1.>结构体变量名.成员名
        2>指针变量->成员名（第二种更常用）
        指针变量->成员名 在计算机内部会被转化成（*指针变量名）.成员的方式来执行
        例子：
        struct student st={80,66.6,'F'};//初始化 定义同时赋初值
        struct student *pst = &st;// &st不能写成st
        pst->age;//第二方式
        st.age;//第一种方式
        
        pst->age在计算机内部会被转化成（*pst）.age这就是->的含义，这是一种硬性规定
        pst->age 等价于（*pst）.age  也等价 st.age
        pst->age的含义：pst所指向的那个结构体变量中的age这个成员
        
    结构体变量和结构体变量指针作为函数参数传递的问题
    结构体变量的运算
    
    举例：动态构造存放学生信息的结构体数组
    链表：
    
        
    
#include<stdio.h>
struct Student
{
    int age;
    float score;
    char sex;
};
void main()
{
    struct Student st = {80,66.6,'F'};//初始化  定义的同时赋初值
    str2.age = 10;
    str2.score = 88;
    str2.sex = 'F';
    
    printf("%d %f %c\n",st.age,st.score,st.sex);
    printf("%d %f %c\n",str2.age,str2.score,str2,sex);	
}
 
//如何取出结构体中的每个成员
#include<stdio.h>
struct student 
{
    int age;
    float score;
    char sex;
};
void main()
{
    struct student st={80,66.6,'F'};//初始化 定义同时赋初值
    struct student *pst = &st;// &st不能写成st
    pst->age;//第二方式
    st.score = 66.6F;//第一种方式  66.6在C语言中默认是double类型，如果希望一个实数是float类型，则必须在末尾加f或F66.6是double 66.6f是float类型
                                    //浮点数不能准确存储
    printf("%d %f\n",st.age ,pst->score);
}
//结构体变量和结构体变量指针作为函数参数传递的问题  通过函数完成对结构体变量的输入和输出
#include<stdio.h>
#include<string.h>
struct student 
{
    int age;
    char sex;
    char name[100];
};//分号不能省
//本函数无法修改st的值，是错误的
//void Inputstudent1(struct student stu)
//{
//	stu.age = 10;
//	strcpy(stu.age,"张三");//不能写成stu.name = "张三" 
//	stu.sex = 'F';	
//}
void Inputstudent(struct student *pstu)  //*pstu只占四个字节
{
    (*pstu).age =10;
    strcpy(pstu->name,"张三");
    pstu->sex = 'F'; 		
}
//这个函数发送内容 不发送地址 不太好
//void Outputstudent(struct student st)
//{
//	printf("%d %c %s\n",st.age,st.sex,st.name);	
//}
//这个函数最好
void Outputstudent(struct student *pst)
{
    printf("%d %c %s\n",pst->age,pst->name,pst->sex);	
}
void main()
{
    struct student st;
    
    //Inputstudent1();//对结构体变量的输入  必须发送st的地址
    Inputstudent(&st);
//	printf("%d %c %s\n",st.age,st.sex,st.name);
    Outputstudent(&st);//对结构体变量的输出  可以发送st的地址 也可以直接发送st的内容  但为了减少内存的耗费 也为了提高执行速度 推荐发送地址
}
  
//冒泡排序
#include<stdio.h>
void sort(int *a,int len)
{
    int i,j,t;
    
    for( i = 0;i<len-1;++i)
    {
        for(j = 0;j<len-1-i;++j)
        {
            if(a[j] >a[j+1])
            {
                t  = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
        
}
void main()
{
    int a[6] = {10,2,8,-8,11,0};
    int i = 0;
    sort(a,6);
    
    for(i = 0; i<6;++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
   */
//动态构造存放学生信息的结构体数组(学生管理系统)
#include<stdio.h>
#include<malloc.h>
struct student
{
    int age;
    float score;
    char name[100];
};
void main()
{
    int len;
    struct student *app;
    int i,j;
    struct student t;
    
    printf("请输入学生的个数：\n");
    printf("len = ");
    scanf("%d",&len);
    //动态构造一维数组
    app = (struct student  *)malloc(len * sizeof(struct student));
    
    for(i =0;i<len;++i)
    {
        printf("第%d个学生的信息是:\n",i+1);
        printf("age = ");
        scanf("%d",&app[i].age);
        printf("name =");
        scanf("%s",app[i].name);//不加&  因为name是数组名 本身就已经是数组首元素的地址 
        
        printf("score = ");
        scanf("%f",&app[i].score);
    }
    //按学生的成绩升序排序，冒泡算法
    for(i = 0;i<len-1;++i)//>是升序 <是降序
    {
        for(j = 0;j<len-1-i;++j)
        {
            if(app[j].score>app[j+1].score)
            {
                t = app[j];
                app[j] = app[j+1];
                app[j+1] = t;
            }
        }
    }
    printf("\n\n学生的信息是:\n");
    //输出
    for(i = 0;i<len;++i)
    {
        printf("第%d个学生的信息是：\n",i+1);
        printf("age = %d\n",app[i].age);
        printf("name = %s\n",app[i].name);
        printf("score = %f\n",app[i].score);
        
        printf("\n");
    }
    
}
