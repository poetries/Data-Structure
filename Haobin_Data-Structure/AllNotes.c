
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
														课程大纲		
1.从12课开始正式讲解数据结构，前面课程是学该门课程的必备基础
2.★14课正式讲解——链表
3.第27课——如何学习算法自己的一些感想     很不错！！ 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

					
模块一：线性结构
		
		连续存储[数组]
		1.	数组：元素类型相同，大小相等
		2.	数组优缺点：（相对于链表）
		
		
		离散存储[链表]
		1.定义：
				头结点数据类型和首节点数据类型一样。
				
				n个节点离散分配
				彼此通过指针相连
				每个节点只有一个前驱节点和后续节点
				首节点没有前驱节点，尾节点没有后续节点
				
				首节点：第一个有效节点（注意区别于头结点）。
				尾节点：最后一个有效节点。
				头结点：为了方便对链表的操作而指向链表首节点的指针。只是为了方便操作，无其它意义，并不包含链表有效节点个数等信息。
				头指针：指向头结点的指针变量（注意区别首指针）
				尾指针：	指向尾节点的指针变量
				
		2.分类：
		
			单链表
			双链表：每个节点有两个指针域；
		
			循环链表：能通过任何一个节点找到其他所有节点。
			非循环链表
			
			
		3.算法：
			遍历
			清空
			查找
			销毁
			求长度
			排序
			删除节点
			插入节点
			
			算法：
				狭义的算法是与数据的存储方式密切相关
				广义的算法与数据的存储无关
				
			泛型：
				利用某种技术达到的效果：不同的存储方式，达到的效果是一样的。
			
		
		线性结构的两种常见应用：栈和队列
		
		专题：递归
			定义：函数自己调用自己（直接或间接）
			1.1+2+3+4+...+100
			2.求阶乘
			3.汉诺塔
			4.走迷宫
			
			
模块二：非线性结构

		树
		
		图
		
		
		
模块三：
		查找和排序
		
			折半查找
			
		排序：
			冒泡
			插入
			选择
			快速排序
			归并排序
		
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<		


***************************************************************************************************************************
												1.ST概述/衡量算法的标准
***************************************************************************************************************************
数据结构定义
			把现实中大量复杂的问题以特定的数据类型和特定的存储结构保存的主存储器（内存）中，以及在此基础上为实现某个
			功能（如查找、删除元素，对元素排序）而执行的相应操作。这个相应的操作也叫算法
			
		数据结构 = 个体存储 + 个体关系
		
		算法=对存储数据的操作
		
			衡量算法的标准：
							1.时间复杂度 即程序大概执行次数，而非执行时间长短
							2.空间复杂度 算法执行过程中，大概所占用的内存
							3.难易程度
							4.健壮性	
	
数据结构中没有“堆”的概念，“堆栈”就是指“栈”;

	
***************************************************************************************************************************
												3.数据结构的特点	2012.3.20
***************************************************************************************************************************
堆内存：以堆排列的方式分配内存
栈内存：以压栈出栈的方式分配的内存    
两者分配内存的算法不一样。	

字段：反应的是事物的——属性
记录：一个整体的事物
表	：同一事物的集合		
							
							
							
							
							
***************************************************************************************************************************
												4.预备知识	2012.3.20
***************************************************************************************************************************
1.指针
2.结构体
3.动态内存的分配和释放							
							
							
1.指针：
		指针就是地址，地址就是指针				注意：指针和指针变量是两回事
		指针变量是存放内存地址的变量 				int *p：系统分配内存表将p变量标记为——已分配
												p+i的值是p+i*(p所指向的变量所占字节数)
		
		指针本质是操作受限的非负整数
		
		地址：内存单元的编号 从0开始的非负整数 范围：0-FFFFFFFF【0-4G-1】
		
	指针分类：
			1.基本类型的指针
			
			2.指针和数组的关系
			int a[5]={1,2,3,4,5}   				数组名a  是一个 指针常量，存放数组首元素地址即a[0]地址  它是指针，不可更改的指针
												下标与指针关系:	a[i]<=>*(a+1)<=>i[a]
												
												%p表示输出地址


***************************************************************************************************************************
												6.指针补充   2012.3.20
***************************************************************************************************************************

指针变量统一只占4个字节。



***************************************************************************************************************************
												7.通过函数修改实参的值   2012.3.20
***************************************************************************************************************************

#include "stdio.h"

void f(int *p);
void main()
{
	int i=10;
	f(&i);
}
void f(int *p)
{
	*p=99;
}

若不考函数的返回值，只能靠指针来改变实参的值




***************************************************************************************************************************
												8.结构体的使用  2012.3.20
***************************************************************************************************************************
结构体：结构体是用户根据实际需要自己及定义的数据类型

相对于C++的类而言，结构体里只能有属性，没有方法，就是说里面没函数。而类里可以有类函数。
和类不同结构体适用于算法。

#include "stdio.h"
#include "string.h"

struct	Student
{
	int sid;
	char name[20];
	int age;
};							//末尾分号不能省略。。。。。。。。。

void main()
{
	struct Student	st={303930,"lose",12};					//第一种方式
	printf("%d  %s     %d\n",st.sid,st.name,st.age);

	st.sid=123456;
	//st.name="lose all";                    error!!
	strcpy(st.name,"loseall");
	st.age=34;
	printf("%d  %s  %d\n",st.sid,st.name,st.age);
	
	struct Student *pst;
	pst=&st
	(*pst).sid=999999;
	pst->name="nisi";
}


两种方式，假如有结构体：
			struct Student
			{
				int sid;
				char name[20];
				int age;
			}
		struct Student st={1111111,"2222222",3333333}
		struct Student *pst=&st;
		
	则有：
		st.sid=100
		pst->sid=100    两种方式效果相同
		
************************************************************
//			比较两种方式的不同
#include "stdio.h"
#include "string.h"

struct Student
{
	int sid;
	char name[20];
	int age;
};

void f(struct Student *pst);		
void g1(struct Student st);
void g2(struct Student *st);


void main()
{
	struct Student	st;								
	f(&st);
	//方法一输出,特点是耗内存，耗时间
	g1(st);
	//方法二输出:
	g2(&st);
	
}

void f(struct Student *pst)
{
	pst->sid=1111111;
	strcpy(pst->name,"pst_name");
	pst->age=200;
}

void g1(struct Student st)
{
	printf("%d  %s  %d  方法1   特点是耗内存，耗时间\n",st.sid,st.name,st.age);
}

void g2(struct Student *st)
{
	printf("%d  %s  %d  方法2\n",st->sid,st->name,st->age);
}




***************************************************************************************************************************
												9.malloc动态分配内存  2012.3.20
***************************************************************************************************************************
不管变量多大,malloc()函数只返回该变量的第一个地址,这是个无意义的地址,因为只知道这个地址却不知变量长度，这个地址又称作“干地址”,
所以通常在malloc()函数前面进行强制类型转换

#include "stdio.h"
#include "malloc.h"
void main()
{
	int a[5];
	
	int len;
	printf("请输入要分配的的数组的长度：");
	scanf("%d",&len);
	
	int *pArr=(int *)malloc(sizeof(int)*len);
//	*pArr=999;
//	pArr[2]=4;
//	printf("*pArr=%d , pArr[2]=%d\n",*pArr,pArr[2]);

//	当普通内存来使用;
	for(int i=0;i<len;++i)
	{
		scanf("%d",&pArr[i]);
	}
	for(i=0;i<len;++i)
	{
		printf("%d\n",*(pArr+i));
	}
	
	free(pArr);    //把pArr代表的动态分配的内存释放掉s
}




***************************************************************************************************************************
												★（重要）10.跨函数使用内存讲解及演示  2012.3.21
***************************************************************************************************************************

#include "stdio.h"

int f();
void main()
{
	int i=10;
	i=f();
	printf("i=%d\n",i);
}
int f()
{
	int j=20;
	return j;
}
//问题：f调用完后。。j的值还是否可用    因为函数调用完后就被释放了，所以不能。


下程序中，能够调用fun()函数，使main（）函数中的指针变量p指向一个合法的整型变量的是：

B.
	#include "stdlib.h"
	
	int fun(int **p);
	void main()
	{
		int *p;
		fun(&p);
	}
	int fun(int **p)
	{
		int s;
		*p=&s
	}
									//在fun()执行过程中，p指向一个合法的整形变量，但fun()执行完后，就从内存被释放，所以p又不知指向哪个角落去了
	
C.
	#include "stdio.h"
	
	int fun(int **p);
	
	void main()
	{
		int *p;
		f(&p);
	}
	
	int fun(int **p)
	{
		*p=(int*)malloc(4);
	}
									//通过malloc动态分配的内存，必须手动释放掉。free();
									
	
动态分配内存：
C++:
	A aa=new A();
	delete  aa;
	
C  :
	A *aa=(A *)malloc(sizeof(A));
	free(aa);


★★★★★   跨函数使用内存，只能通过动态实现

#include "stdio.h"
#include "malloc.h"

struct Student
{
	int sid;
	char name[20];
	int age;
};

void main()
{
	struct Student *CreateStudent();
	void ShowStudent(struct Student *pst);
	
	struct Student *st=CreateStudent();
	ShowStudent(st);
	
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//创建一个动态链表，并对结构体赋值
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
struct Student *CreateStudent()
{
	struct Student *p=(struct Student *)malloc(sizeof(struct Student));
	p->age =91;
	p->sid =303930;
	return p;
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//输出链表中元素的值
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void ShowStudent(struct Student *pst)
{
	printf("age=%d,sid=%d\n",pst->age,pst->sid);
}





***************************************************************************************************************************
												12.连续存储数组的算法演示1  2012.3.21
												13.连续存储数组的算法演示2	2012.3.21
***************************************************************************************************************************
模块一：线性结构
		
		连续存储[数组]
		1.	数组：元素类型相同，大小相等
		2.	数组优缺点：（相对于链表）

		
★★★★★   结构体变量不能+-*/,但能相互赋值

int a[10]
int *a=(int *)malloc(sizeof(int))	//java 内部就是这样实现数组的。

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//							数组的模拟
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"      //exit();
struct Arr
{
	int *pbase;			//存储数组的第一个元素的地址。
	int len;			//数组容纳的最大元素个数;
	int cnt;			//当前数组有效元素的个数
};

void init_arr(struct Arr *pArr,int length);				//初始化数组
bool append_arr(struct Arr *pArr,int val);				//追加元素
bool insert_arr(struct Arr *pArr,int pos,int val);		//插入元素      ★★★★★要掌握
bool delete_arr(struct Arr *pArr,int pos);				//删除元素
int	 get(struct Arr *parr,int pos);						//获取数组元素
bool is_empty();										//感觉这函数多余了
bool is_full();											//同上
void sort_arr(struct Arr *parr);						//数组排序      以冒泡法升序为例
void show_arr(struct Arr *starr);						//显示信息
void inversion_arr(struct Arr *pArr);					//数组倒置

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//				主函数
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void main()
{
	struct Arr a;
	init_arr(&a,6);
	append_arr(&a,1);
	append_arr(&a,666);
	append_arr(&a,8);
	append_arr(&a,4);
	append_arr(&a,58);
//	append_arr(&a,6);
//	insert_arr(&a,2,8888);
//	delete_arr(&a,2);
	show_arr(&a);
//	inversion_arr(&a);
	sort_arr(&a);
	show_arr(&a);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//				数组初始化
//			跨函数使用内存实例 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void init_arr(struct Arr *pArr,int length)
{
	pArr->pbase=(int *)malloc(sizeof(int)*length);
	if(NULL==pArr->pbase)
	{
		printf("分配内存失败！！\n");
		exit(-1);
	}
	else
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return ;
//	pArr->len=99;	
//	(*pArr).len=88;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组显示  
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void show_arr(struct Arr *starr)
{
	if(0==starr->cnt)
	{
		printf("数组为空！！\n");
	}
	else
	{
	//	printf("pbase=%p,len=%d,cnt=%d\n\n",starr->pbase,starr->len,starr->cnt);
		for (int i=0;i<starr->cnt;i++)
		{
			printf("%d",starr->pbase[i]);
			printf(" ");
		}
		printf("\n");
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组追加  
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool append_arr(struct Arr *pArr,int val)
{
	if (pArr->len==pArr->cnt)
	{
		printf("数组已满，追加失败！！\n");
		return false;
	}
	else
	{
		pArr->pbase[pArr->cnt]=val;
		pArr->cnt++;
		return true;
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组插入数值 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	if (pArr->len==pArr->cnt)
	{
		printf("数组已满,无法插入新的数值!!\n");
		return 0;
	}
	else
	{
		register int cnt2=pArr->cnt;
		for (int i=0;i<=(cnt2-pos+1);i++)
		{
			pArr->pbase[pArr->cnt+1]=pArr->pbase[pArr->cnt];
			pArr->cnt--;
		}
		pArr->cnt=cnt2+1;
		pArr->pbase[pos-1]=val;
		return 1;
	}
	
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			删除数组数值 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool delete_arr(struct Arr *pArr,int pos)
{
	if (pos>pArr->cnt||pos<1)
	{
		printf("该元素不存在!!!\n");
		return false;
	} 
	else
	{
		int pos1=pos,deleteval=pArr->pbase[pos-1];
		for (int i=0;i<pArr->cnt;i++)
		{
			pArr->pbase[pos-1]=pArr->pbase[pos];
			pos++;
		}
		pArr->cnt--;
		printf("您删除的是第%d个元素(值为：%d)\n",pos1,deleteval);
		return true;
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组倒置 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void inversion_arr(struct Arr *pArr)
{
	int *p1,*p3;
	int temp;
	p1=&pArr->pbase[0];						//p1指向  数组第一个元素
	p3=&pArr->pbase[pArr->cnt-1];			//p3指向  数组最后一个元素
	for (int i=0;i<pArr->cnt/2;i++)
	{					
		temp=*p1;			
		*p1=*p3;
		*p3=temp;
		p1=&pArr->pbase[i+1];				
		p3--;		
	}
//	show_arr(pArr);
	printf("\n");
}



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			冒泡排序（升序）
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void sort_arr(struct Arr *parr)
{
	int i,j,t;
	for (i=0;i<parr->cnt;i++)
	{
		for (j=i+1;j<parr->cnt;j++)
		{
			if (parr->pbase[i]>parr->pbase[j])
			{
				t=parr->pbase[i];
				parr->pbase[i]=parr->pbase[j];
				parr->pbase[j]=t;
			}
		}
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			获取数组元素
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int get(struct Arr *parr,int pos)
{
	if (pos<1 || pos>parr->cnt)
	{
		printf("该数组元素为无效值\n");
		return 0;
	} 
	else
	{
		printf("您想获取的是第%d个元素，其值为：%d\n",pos,parr->pbase[pos-1]);
		return parr->pbase[pos-1];
	}
}



***************************************************************************************************************************
												14.链表的重要性 2012.3.22
												15.typedef用法  2012.3.22
***************************************************************************************************************************
typedef 用法

1.
	typedef int	lose; //这样定义以后"lose"变成一个关键字，完全等价于int 例如: lose num=88;<=>int num=88; 完全等价;
2.	
//从以下代码可以看出，typedef类似于宏替换#define
#include "stdio.h"
#include "string.h"

typedef struct Student
{
	int age;
	int sid;
	char name[20];
} ST,* PST;

void main()
{
	ST student;
	student.age=17;
	student.sid=55555;
	strcpy(student.name,"lose");
	printf("name:%s  age=%d  sid=%d\n",student.name,student.age,student.sid);
	PST pst=&student;
	strcpy(pst->name,"xtr");
	pst->age=19;
	pst->sid=18181;
	printf("name:%s   age=%d  sid=%d\n",student.name,student.age,student.sid);
	printf("%c%c%c%c\n",student.name[0],student.name[1],student.name[2],student.name[3]);
}



***************************************************************************************************************************
						16.链表的定义
						17.如果希望通过一个函数来对链表进行处理，我们至少需要接受链表的哪些参数 2012.3.22
***************************************************************************************************************************

离散存储[链表]
		1.定义：
				头结点数据类型和首节点数据类型一样。
				
				n个节点离散分配
				彼此通过指针相连
				每个节点只有一个前驱节点和后续节点
				首节点没有前驱节点，尾节点没有后续节点
				
				首节点：第一个有效节点（注意区别于头结点）。
				尾节点：最后一个有效节点。
				头结点：为了方便对链表的操作而指向链表首节点的指针。只是为了方便操作，无其它意义，并不包含链表有效节点个数等信息。
				头指针：指向头结点的指针变量（注意区别首指针）
				尾指针：	指向尾节点的指针变量
				
		2.如果希望通过一个函数来对链表进行处理，我们至少需要接受链表的哪些参数？
				只需一个头指针。
				
				
***************************************************************************************************************************
									18.每一个链表节点的数据类型该如何表示的问题 2012.3.22
***************************************************************************************************************************
一个节点的创建：
typedef struct Student
{
	int data;
	struct Student * next;//struct Student * next
	
} ST,* PST;

***************************************************************************************************************************
									19.链表的分类 2012.3.22
***************************************************************************************************************************
链表分类：
		
		单链表
		双链表：每个节点有两个指针域；
	
		循环链表：能通过任何一个节点找到其他所有节点。
		非循环链表



***************************************************************************************************************************
									20.非循环单链表插入节点伪算法讲解 2012.3.22
***************************************************************************************************************************
//一个简单的静态链表实例。
#include "stdio.h"
#include "string.h"

typedef	struct Student
{
	char name[20];
	int age;
	struct Student *next;	
} *PST,ST;

void main()
{
	ST st1,st2,st4;
	PST pst,head;
	head=&st1;
	pst=head;

	st1.age=11;
	strcpy(st1.name,"name1");
	st1.next=&st2;

	st2.age=22;
	strcpy(st2.name,"name2");
	st2.next=&st4;

	st4.age=44;
	strcpy(st4.name,"name3");
	st4.next=NULL;
	
	do 
	{
		printf("name:%s,age=%d\n",pst->name,pst->age);
		pst=pst->next;
	} while (pst!=NULL);
}  
//假如有如下定义：ST st3,要往以上链表的“st2”和“st4”中插入一个节点"st3",st3.name=name3,st3.age=33,并只输出3个节点数据，请先思考;
#include "stdio.h"
#include "string.h"

typedef	struct Student
{
	char name[20];
	int age;
	struct Student *next;	
} *PST,ST;

void main()
{
	ST st1,st2,st4;
	PST pst,head;
	head=&st1;
	pst=head;

	st1.age=11;
	strcpy(st1.name,"name1");
	st1.next=&st2;

	st2.age=22;
	strcpy(st2.name,"name2");
	st2.next=&st4;

	st4.age=44;
	strcpy(st4.name,"name4");
	st4.next=NULL;
	
	//*********************
	//	增加的代码如下
	//*********************
	ST st3;
	st3.age=33;
	strcpy(st3.name,"name3");
	PST p2=&st2,p4=&st4,p3=&st3;
	
	
	//   方法2：
	p2->next=p3;
	p3->next=p4;
	
	
	do 
	{
		printf("name:%s,age=%d\n",pst->name,pst->age);
		pst=pst->next;
	} while (pst->!=NULL);
}  


***************************************************************************************************************************
									21.删除非循环单链表节点伪算法的讲解 2012.3.22
									22.学习数据结构要达到的目的和要求   2012.3.22
									23.复习								2012.3.22
***************************************************************************************************************************

#include "stdio.h"
#include "string.h"
#include "malloc.h"

typedef	struct Student
{
	char name[20];
	int age;
	struct Student *next;	
} *PST,ST;

void main()
{
	ST st1,st2,st4;
	PST pst,head;
	head=&st1;
	pst=head;

	st1.age=11;
	strcpy(st1.name,"name1");
	st1.next=&st2;

	st2.age=22;
	strcpy(st2.name,"name2");
	st2.next=&st4;

	st4.age=44;
	strcpy(st4.name,"name4");
	st4.next=NULL;
	//**************************
	//	插入节点st3
	//*************************
	ST st3;
	st3.age=33;
	strcpy(st3.name,"name3");
	PST p2=&st2,p4=&st4,p3=&st3;
	//   方法一：
	p2->next=p3;
	p3->next=p4;

	//****************************
	//	删除节点2
	//****************************
	ST *s,* pst1=&st1;
	s=pst1->next;
	pst1->next=s->next;
	//free(s);                     //为什么加上free(s)时会报错？？！！？

	
	do 
	{
		printf("name:%s,age=%d\n",pst->name,pst->age);
		pst=pst->next;
	} while (pst!=NULL);
}  




***************************************************************************************************************************
									24.链表创建和链表遍历算法的演示  2012.3.25
***************************************************************************************************************************
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

//****************************************
//			链表定义
//****************************************
typedef struct Node
{
	int data;
	struct Node * pNext;
} NODE,* PNODE;

//***************************************
//				函数声明
//***************************************
PNODE CreateList();						 //创建链表
void TraverseList(PNODE pHead);			 //遍历链表

//***************************************
//				函数入口
//***************************************
void main()
{
	PNODE phead=NULL;
	phead=CreateList();
	TraverseList(phead);
}

//***************************************
//				函数实现
//***************************************

PNODE CreateList()
{
	int len;
	int val;
	
	PNODE phead=(PNODE)malloc(sizeof(NODE));	/*注意这里是sizeof(NODE),不是sizeof(PNODE)*/
	PNODE pTail=phead;
	pTail->pNext=NULL;
	
	printf("请输入链表长度：");
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个节点值：",i+1);
		scanf("%d",&val);
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
		
	}
	
	
	if(NULL==phead)
	printf("分配内存出错，请检查内存是否足够！/n");
	return phead;
}


void TraverseList(PNODE pHead)
{
	PNODE p=pHead->pNext;
	while(NULL != p)
	{
		printf("%d  ",p->data);
		p=p->pNext;
	}
	printf("\n");
}

***************************************************************************************************************************
									25.判断链表是否为空和求链表长度算法的演示  			2012.3.26
									26.通过链表排序算法的演示再次详细讨论到底什么是算法以及到底什么是泛型【重点】
***************************************************************************************************************************
算法：
				狭义的算法是与数据的存储方式密切相关
				广义的算法与数据的存储无关
				
			泛型：
				利用某种技术达到的效果：不同的存储方式，达到的效果是一样的。

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

//****************************************
//			链表定义
//****************************************
typedef struct Node
{
	int data;
	struct Node * pNext;
} NODE,* PNODE;

//***************************************
//				函数声明
//***************************************
PNODE	CreateList();						 //创建链表
void 	TraverseList(PNODE pHead);			 //遍历链表
bool 	is_empty(PNODE pHead);				 //链表为空否
int		length(PNODE pHead);				 //链表长度
void	sort_list(PNODE pHead);				 //链表排序
//***************************************
//				函数入口
//***************************************
void main()
{
	PNODE phead=NULL;
	phead=CreateList();
	TraverseList(phead);
//	length(phead);
	sort_list(phead);
	TraverseList(phead);
}

//***************************************
//				函数实现
//***************************************

PNODE CreateList()
{
	int len;
	int val;
	
	PNODE phead=(PNODE)malloc(sizeof(NODE));	/*注意这里是sizeof(NODE),不是sizeof(PNODE)*/
	PNODE pTail=phead;
	pTail->pNext=NULL;
	
	printf("请输入链表长度：");
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个节点值：",i+1);
		scanf("%d",&val);
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
		
	}
	
	if(NULL==phead)
	printf("分配内存出错，请检查内存是否足够！/n");
	return phead;
}


void TraverseList(PNODE pHead)
{
	PNODE p=pHead->pNext;
	while(NULL != p)
	{
		printf("%d  ",p->data);
		p=p->pNext;
	}
	printf("\n");
}


bool is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
	{
		printf("链表为空!!\n");
		return true;
	}
	else
	{
		return false;
	}
}


int length(PNODE pHead)
{
	PNODE p=pHead->pNext;
	int len=0;								//这里记得要初始化。
	if(1==is_empty(pHead))					//这段代码有 disassembly 的价值
	{
		printf("length()提示——链表为空\n");
	}
	else
	{
		while(NULL != p)
		{
			p=p->pNext;
			len++;
		}
		printf("链表长度为：%d\n",len);
	}
	return len;
}


void sort_list(PNODE pHead)
{
	int i,j,t;
	PNODE p1,p2;
	int len=length(pHead);
	
	for(i=0,p1=pHead->pNext;i<len;i++,p1=p1->pNext)
		for(j=i+1,p2=p1->pNext;j<len;j++,p2=p2->pNext)
		{
			if(p1->data>p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
		}
		
}


***************************************************************************************************************************
										27.如何学习算法自己的一些感想 2012.3.27
										28.链表的插入和删除算法的演示 2012.3.27
***************************************************************************************************************************

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

//****************************************
//			链表定义
//****************************************
typedef struct Node
{
	int data;
	struct Node * pNext;
} NODE,* PNODE;

//***************************************
//				函数声明
//***************************************
PNODE	CreateList();						 //创建链表
int 	TraverseList(PNODE pHead);			 //遍历链表
bool 	is_empty(PNODE pHead);				 //链表为空否
int		length(PNODE pHead);				 //链表长度
void	sort_list(PNODE pHead);				 //链表排序
bool	insert(PNODE pHead,int n,int val);  //插入链表
bool	delete_list(PNODE pHead,int n);		//删除链表节点

//***************************************
//				函数入口
//***************************************
void main()
{
	PNODE phead=NULL;
	phead=CreateList();
	TraverseList(phead);
//	length(phead);
//	sort_list(phead);
	insert(phead,2,99999);
	TraverseList(phead);
	delete_list(phead,1);
	TraverseList(phead);

}

//***************************************
//				函数实现
//***************************************

PNODE CreateList()
{
	int len;
	int val;
	
	PNODE phead=(PNODE)malloc(sizeof(NODE));	/*注意这里是sizeof(NODE),不是sizeof(PNODE)*/
	PNODE pTail=phead;
	pTail->pNext=NULL;
	
	printf("请输入链表长度：");
	scanf("%d",&len);
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个节点值：",i+1);
		scanf("%d",&val);
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
		
	}
	
	if(NULL==phead)
	printf("分配内存出错，请检查内存是否足够！/n");
	return phead;
}


int TraverseList(PNODE pHead)
{
	PNODE p=pHead->pNext;
	int sum=0;
	while(NULL != p)
	{
		printf("%d  ",p->data);
		p=p->pNext;
		sum++;
	}
	printf("\n");
	return sum;
}


bool is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
	{
		printf("链表为空!!\n");
		return true;
	}
	else
	{
		return false;
	}
}


int length(PNODE pHead)
{
	PNODE p=pHead->pNext;
	int len=0;								//这里记得要初始化。
	if(1==is_empty(pHead))					//这段代码有 disassembly 的价值
	{
		printf("length()提示——链表为空\n");
	}
	else
	{
		while(NULL != p)
		{
			p=p->pNext;
			len++;
		}
		printf("链表长度为：%d\n",len);
	}
	return len;
}


void sort_list(PNODE pHead)
{
	int i,j,t;
	PNODE p1,p2;
	int len=length(pHead);
	
	for(i=0,p1=pHead->pNext;i<len;i++,p1=p1->pNext)
		for(j=i+1,p2=p1->pNext;j<len;j++,p2=p2->pNext)
		{
			if(p1->data>p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
		}
		
}


bool insert(PNODE pHead,int n,int val)
{
	PNODE p=pHead;
	int i=0;
	PNODE q=(PNODE)malloc(sizeof(NODE));
	int sum=TraverseList(pHead);
	if(0==sum)
	{
		printf("该链表为空!\n");
		return 0;
	}

	if(n>sum ||n<=0)
	{
		printf("请输入有效数据\n");
		return 0;
	}
	else
	{
		for (;i<n-1;i++)
		{
			p=p->pNext;
		}
		PNODE r=p->pNext;
		p->pNext=q;
		q->pNext=r;
		q->data=val;
		
		return 1;
	}

}


bool delete_list(PNODE pHead,int n)
{
	PNODE p=pHead;
	int sum=length(pHead);
	if (sum==0)
	{
		printf("该链表为空!!\n");
		return 0;
	}
	if (n>sum ||n<0)
	{
		printf("您输入的数据不合法！\n");
		return 0;
	} 
	else
	{
		for (int i=0;i<n-1;i++)
		{
			p=p->pNext;
		}
		PNODE tmp=p->pNext->pNext;
		p->pNext=tmp;
//		free(tmp);

		return 1;
	}
}


***************************************************************************************************************************
												29.复习 2012.3.27								
***************************************************************************************************************************
数据结构：
		狭义：
			专门研究数据的存储
			数据的存储包含两方面：个体的存储+个体关系的存储
		广义：
			包含数据的 存储和操作
			对存储数据的操作就是  算法
			
算法：
		狭义：
			和数据的存储方式密切相关
		广义：
			和数据的存储方式无关   这也就是  泛型  的思想


数据的存储结构：
		线性：
			连续存储  【数组】
				优点：
					存取速度快，空间有限制
				缺点：
					插入删除元素速度慢
			离散存储  【链表】
				优点：
					空间无限制，插入删除元素速度快
				缺点：
					数据存储慢
	  非线性：
			树和图


***************************************************************************************************************************
												30.栈的定义 			2012.3.27
												31.栈的分类 			2012.3.27
												32.栈可以执行哪些操作 	2012.3.27
												33.栈程序演示 			2012.3.27
												34.栈的日常具体应用 	2012.3.27
***************************************************************************************************************************

内存分为 静态内存和动态内存   静态内存分配在栈里，动态内存分配在堆里

栈 由操作系统维护，堆由程序员维护  LIFO原则（last in first out）


分类：
	 静态栈：数组为内核
	 
	 动态栈：链表为内核
	

算法：
	出栈
	压栈
	
	
应用：
	函数调用
	中断
	表达式求值    计算器（两个栈实现）
	内存分配
	缓冲处理
	迷宫        
	
	★★★★★算法的练习  计算器  迷宫



#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

//***************************************
//			结构体定义
//***************************************
typedef struct node
{
	int		data;
	struct	node * pNext;
}NODE,* PNODE;

typedef struct nstack
{
	PNODE	pTop;
	PNODE	pButtom;
}STACK, * PSTACK;

//***************************************
//			函数声明
//***************************************
void	init(PSTACK s);						//初始化 栈指针
void	push(PSTACK s,int val);				//压栈 函数
int		traverse(PSTACK s);					//遍历 栈段 并输出
bool	pop(PSTACK s,int * val);			//出栈 函数
bool	emp(PSTACK s);						//检测栈段是否为空
void	clear(PSTACK s);					//清空栈

//***************************************
//			入口函数
//***************************************

void main()
{
	int val;
	STACK S;
	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);
	if (pop(&S,&val))
	{
		printf("出栈的元素是%d\n",val);
	}
	clear(&S);
	traverse(&S);
	return;

}


//***************************************
//			函数实现
//***************************************
void	 init(PSTACK s)
{
	s->pButtom=(PNODE)malloc(sizeof(NODE));
	s->pButtom->pNext=NULL;
	s->pTop=s->pButtom;
	
}

void	push(PSTACK s,int val)
{
	PNODE newnode=(PNODE)malloc(sizeof(NODE));
	PNODE temp=newnode;
	newnode->data=val;
	newnode->pNext=s->pTop;
	s->pTop=temp;
	return;
}

int	traverse(PSTACK s)
{
	int len=0;
	PNODE pt=s->pTop;
	while (NULL !=pt->pNext)
	{
		len++;
		printf("%d  ",pt->data);
		pt=pt->pNext;
	}
	printf("栈里有%d个元素\n",len);
	return len;
}


bool	pop(PSTACK s,int * val)
{
	if (emp(s))
	{
		printf("栈空！！无法pop!\n");
		return 0;
	} 
	else
	{
		*val=s->pTop->data;

//		PNODE temp=s->pTop->pNext;
//		s->pTop=temp;
//		free(temp);                               //这种情况下是不能用free()释放内存的。

		PNODE temp=s->pTop;
		s->pTop=temp->pNext;
		free(temp);

		temp=NULL;
		return 1;
	}
}

bool	emp(PSTACK s)
{

	PNODE pt=s->pTop;
	if (NULL==pt->pNext)
	{
		return 1;
	} 
	else
	{

		return 0;
	
	}

}



void clear(PSTACK s)
{
	if (emp(s))
	{
		return;
	} 
	else
	{
		PNODE p=s->pTop;
		PNODE q=NULL;
		while (p != s->pButtom)					//如果这里条件写成 while(NULL != p)  会出错!!
		{
			q=p->pNext;
			free(p);
			p=q;
		}
		s->pTop=s->pButtom;

	}
}




***************************************************************************************************************************
										35.什么是队列 								2012.3.28
										36.队列的分类和链式队列伪算法的讲解 		2012.3.28
										37.学习循环队列必须要弄清楚的7个问题概述 	2012.3.28
										38.静态队列为什么必须是循环队列 			2012.3.28
										39.循环队列需要几个参数来确定及其含义的讲解 2012.3.28
										40.循环队列各个参数的含义					2012.3.28
										41.循环队列入队伪算法讲解					2012.3.28
										42.循环队列出队伪算法讲解					2012.3.28
										43.如何判断循环队列是否为空					2012.3.28
										44.如何判断循环队列是否已满					2012.3.28
										45.求链表的长度
										46.复习上节课队列知识						
										47.循环队列程序演示							2012.3.28
										48.队列的具体应用							2012.3.28					
										49.可以不看
***************************************************************************************************************************
队列：
	 先进先出的存储结构

栈	：
	 先进后出的存储结构 (First In Last Out) (FILO) 
						(Last In First Out) (LIFO)

队列分类：
		链式队列：（顾名思义，以链表实现，所以是动态的。）
		静态队列：循环队列(用数组实现)
		


循环队列的讲解
		1.静态队列为什么必须是循环队列
			重复利用空间
		
		2.循环队列需要几个参数来确定   
			需要2个参数（指针）  front和rear 
		
		3.循环队列各个参数的含义
			1.队列初始化
				front=rear=0
			2.队列非空
				front指向队列第一个有效元素，rear指向最后一个有效元素的下一个元素
			3.队列为空
				front=rear  但二者的值不一定为0！！
				
		4.循环队列入队伪算法讲解
			两步完成
				1.将入队的值赋给r所指向的地址
				2.r=(r+1)%n    (n代表数组长度)
		
		5.循环队列出队伪算法讲解
			f=(f+1)%n
			
		6.如何判断循环队列是否为空
			front=rear 则队列一定为空
			
		7.如何判断循环队列是否已满
			front与rear相邻则栈满
			if((rear+1)%n==f)
			{
				栈满
			}
			else
			{
				不满
			}
		
循环的意义
			在于重复利用空间
		



#include "stdio.h"
#include "malloc.h"

//*****************************************
//			结构体定义
//*****************************************
typedef		struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE, * PQUEUE;

//*****************************************
//			函数声明
//*****************************************
void	init(PQUEUE pq);					//初始化队列
bool	en_queue(PQUEUE ,int);				//入队函数
bool	out_queue(PQUEUE,int *);			//出队函数
bool	emp(PQUEUE);						//判断队列是否为空
bool	full(PQUEUE);						//判断队列是否已满
void	traverse(PQUEUE);					//遍历队列并输出

//*****************************************
//			main函数
//*****************************************
void	main()
{
	QUEUE queue;
	init(&queue);
	en_queue(&queue,1);
	en_queue(&queue,2);
	en_queue(&queue,3);
	en_queue(&queue,4);
	en_queue(&queue,5);
	traverse(&queue);
	int v;
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
}

//*****************************************
//			函数实现
//*****************************************

void	init(PQUEUE pq)
{
	pq->pBase=(int *)malloc(sizeof(int)*6);
	pq->front=0;
	pq->rear=0;
}


bool	en_queue(PQUEUE pq,int val)
{
	if (full(pq))
	{
		printf("队列已满！\n");
		return 0;
	} 
	else
	{
		pq->pBase[pq->rear]=val;
		pq->rear=(pq->rear+1)%6;
		return 1;
	}
}


bool	out_queue(PQUEUE pq,int *val)
{
	if (emp(pq))
	{
		printf("栈空！！\n");
		return false;
	} 
	else
	{
		*val=pq->front;
		pq->front=(pq->front+1)%6;
		return true;
	}
}


bool	emp(PQUEUE pq)
{
	if (pq->front==pq->rear)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

bool	full(PQUEUE pq)
{
	if ((pq->rear+1)%6==pq->front)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void	traverse(PQUEUE pq)
{
	int n=pq->front;
	while (n != pq->rear)
	{
		printf("%d  ",pq->pBase[n]);
		n=(n+1)%6;
	}
	printf("\n");
}



队列的应用
			所有与时间相关的操作都与队列相关


***************************************************************************************************************************
									50.递归的定义和不同函数之间相互调程序举例	2012.3.29
									51.一个函数自己调自己程序举例				2012.3.29
									52.1+2+3+....+100之和用递归来实现			2012.3.29
									53.布置作业_汉诺塔							2012.3.29
									54.一个函数为什么可以自己调用自己			
									55.递归必须满足3个条件						2012.3.29
									56.递归和循环的比较							2012.3.29
									57.汉诺塔问题								2012.3.29
									58.递归的应用								2012.3.29
***************************************************************************************************************************
专题：递归（靠栈来实现）
	定义：函数自己调用自己（直接或间接）
	1.1+2+3+4+...+100
	2.求阶乘
	3.汉诺塔
	4.走迷宫
//************************
//----函数自己调自己----
#include 	"stdio.h"

void f(int n)
{
	if(n==1)
	printf("哈哈\n");
	else
	f(n-1);
}

void main()
{
	void f(3);
	return;
}
//***********************************

//***********************************
//------求阶乘 非递归法---
void main()
{
	int val,mult=1,i=1;
	printf("请输入需要求阶乘的值：");
	scanf("%d",&val);
	
	for (;i<val+1;i++)
	{
		mult=mult*i;
	}
	printf("%d的阶乘是%d\n",val,mult);
}
//***********************************	
							
							
//***********************************
//------求阶乘 递归法-------
#include "stdio.h"

long factorial(long n)
{
	if (1==n)
	{
		return 1;
	} 
	else
	{
		return factorial(n-1)*n;
	}
}

void main()
{
	printf("%d\n",factorial(5));
}												
//***********************************

//***********************************
//------求1+2+3...+100 递归法-------
#include "stdio.h"

long sum(int n)
{
	int i,j,k;
	if(1==n)
	{
		return 1;
	}
	else
	{
		return (sum(n-1)+n);
	}
}

void main()
{
	printf("%d\n",sum(100));
}
//***********************************

//*************************************************
//-----------------汉诺塔--------------------							
#include "stdio.h"

int move_count=0;

void	hanoi(int n,char x,char y,char z)
{
	void move(char a,char b,int n);
	if (1==n)
	{
		move(x,z,n);
//		return 1;
	}
	else
	{
		hanoi(n-1,x,z,y);
		move(x,z,n);
		hanoi(n-1,y,x,z);

	}
}

void	move(char a,char b,int n)
{
	if (1!=n)
	{
		move_count+=1;
	}
	printf("%c-->%c\n",a,b);
}	

void	main()
{
	int n;
	printf("请输入碟子数目：");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	printf("共需要%d个步骤!\n",move_count*2+1);
}
//*************************************************
							
递归必须满足的3个条件：
					1.必须有一个明确的终止条件；
					2.该函数所处理的数据规模必须递减；
					3.这个转化必须是可解的（郝斌自己加的）
							
递归和循环的优缺点：
				递归：
					易于理解
					速度慢
					存储空间大
						  
				循环：
					不易理解
					速度快
					存储空间小
							
							
递归的应用：
			1.树和森林是以递归定义的;
			2.树和图的很多算法是以递归实现的；
			3.很多数学公式就是以递归的方式定义的
							
							
***************************************************************************************************************************
											60.树的定义 			2012.2.29
											61.树的专业术语			2012.2.29
											62.树的分类				2012.2.29
											63.二叉树连续存【重点】	2012.2.29
											64.二叉树的链式存储		2012.2.29
											65.普通树的存储			2012.3.30
											66.森林的存储			2012.3.30	
***************************************************************************************************************************					
模块二：非线性结构
		
		树：
			专业定义：
					1.有且只有一个称为根的节点
					2.有若干个互不相干的子树，这些子树本身也是数
			通俗定义：
					1.由节点和边组成
					2.每个节点有一个父节点但可以有多个子节点
					3.仅有一个节点例外，该节点没有父节点，此节点称为根节点
					
					
			专业术语：
					节点	父节点	子节点	子孙	堂兄弟
					深度：
						从根节点到最底层节点之间的层数。根节点为第一层
				叶子节点：
						没有子节点的节点。就是最底层的节点
				非终端节点：
						非叶子节点
					度：子节点的个数
			
			分类：
				一般树
					任意一个节点的子节点的个数都不受限制
				二叉树
					任意一个节点的子节点的个数最多2个，且位置不可更改（比如左子树和右子树不能对换）
					
					分类：
						一般二叉树
						
						满二叉树：不增加深度的情况下，无法增加节点的二叉树。
						
						完全二叉树：就是把满二叉树叶子节点最右边去掉连续的若干个
					
				森林
					n个互不相交的树的集合
					
					
					
			树的存储：
				二叉树的存储
					1.连续存储[完全二叉树]
						优点：
							查找某个节点的父节点和子节点（也包括 判断有没有父节点和子节点）速度
						缺点：
							耗内存空间
					2.链式存储（N个节点，二叉树只浪费N+1个空间，属于线性浪费，即浪费得很少）
						优点：
							不耗内存
						缺点：
							无法还原二叉树顺序（注意：是顺序，不是结构，比如无法确定左孩子和右孩子）
						
				一般树的存储
					双亲表示法
							求父节点方便
					孩子表示法
							求子节点方便
					双亲孩子表示法
							求父、子节点都方便，但不好操作
					二叉树表示法
						设法保证 任意一个节点的
							左指针域指向第一个孩子
							右指针域指向他的下一个兄弟
						只要满足此条件就可以把一个普通树转换为二叉树
						一个普通树转化为二叉树一定没有右子树
				
				
				森林的存储
						先把森林的存储转换为二叉树，再存储二叉树
				
				
***************************************************************************************************************************					
											67.二叉树的先序遍历				2012.3.30
											68.二叉树的中序遍历				2012.3.30
											69.二叉树的后续遍历				2012.3.30
											71.已知先序和中序求后序			2012.3.30
											72.已知中序和后序求先序			2012.3.30
											73.树的应用知识简单介绍			2012.3.30
											75.链式二叉树遍历具体程序演示	2012.3.30											
***************************************************************************************************************************	
二叉树的先序遍历
	先访问     根节点
	再先序访问 左子树
	再先序访问 右子树
	
二叉树的中序遍历
	先中序遍历 左子树
	再中序访问 根节点
	再中序访问 右子树

二叉树的后续遍历
	中序遍历 左子树
	中序遍历 右子树
	访问     根节点
	
一直两种遍历序列，求原始二叉树
	通过研究发现，只有知道 先序和中序 或 中序和后序 才能还原原始二叉树，知道 先序和后序是不能推出的
	
	★★★★★★★★★已知先序和中序求后序★★★★★★★★★★
	1.	先序:ABCDEFGH
		中序:BDCEAFHG
		后序:
	2.	先序:QBDGHCEFI
		中序:GDHBAECIF
		后序:
	
	★★★★★★★★★已知后序和中序求先序★★★★★★★★★★
	    中序:BDCEAFHG
		后序:DECBHGFA
		先序:
	
	
	
	树的应用
	数据库中数据组织的一种重要形式
	操作系统子父进程的关系本身就是一棵树
	面向对象语言中类的继承关系
	赫夫曼树
	

	
	
	
	
#include "stdio.h"
#include "malloc.h"

//******************************************
//			结构体定义
//******************************************
typedef	struct Btree
{
	char	data;
	struct Btree * pLchild;
	struct Btree * pRchild;
}BTREE,* PBTREE;


//******************************************
//			函数声明
//******************************************
PBTREE	CreateBTree();							//创建二叉树;
void	PreTrave(PBTREE);						//先序遍历;
void	IntTrave(PBTREE);						//中序遍历;
//void	PosTrave(PBTREE);						//后续遍历;

//******************************************
//			程序入口
//******************************************
void	main()
{
	PBTREE	pBTree=CreateBTree();
	PreTrave(pBTree);
	printf("\n\n");
	IntTrave(pBTree);
	return;
}


//******************************************
//			函数实现
//******************************************
	//-------创建二叉树----------
PBTREE	CreateBTree()
{
	PBTREE	pA=(PBTREE)malloc(sizeof(BTREE));
	PBTREE	pB=(PBTREE)malloc(sizeof(BTREE));
	PBTREE	pC=(PBTREE)malloc(sizeof(BTREE));
	PBTREE	pD=(PBTREE)malloc(sizeof(BTREE));
	PBTREE	pE=(PBTREE)malloc(sizeof(BTREE));

	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';

	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;

	return	pA;
}

//---------先序遍历--------------
void	PreTrave(PBTREE pT)
{
	
	if (NULL != pT)
	{
		printf("%c \n",pT->data);

		if (NULL != pT->pLchild)
		{
			PreTrave(pT->pLchild);
		}
		if (NULL != pT->pRchild)
		{
			PreTrave(pT->pRchild);
		}
	}
	
	return;
}

//---------中序遍历--------------
void	IntTrave(PBTREE pT)
{
	if (NULL != pT)
	{
		IntTrave(pT->pLchild);
		if (NULL != pT->data)
		{
			printf("%c\n",pT->data);
		}
		if (NULL != pT->pRchild)
		{
			IntTrave(pT->pRchild);
		}
	}
	return;
}

	
	
	
	





***************************************************************************************************************************					
											76.5种常用排序概述和快速排序详细讲解	2012.4.2
											77.再次讨论什么是数据结构				2012.4.2
											78.再次讨论到底什么是泛型				2012.4.2
***************************************************************************************************************************
#include "stdio.h"

//************************************************************
//				函数声明
//************************************************************
void	fastsort(int *,int,int);										//快速排序;
int		findpos(int *,int,int);											//查找第一个元素插入的位置

//************************************************************
//				程序入口
//************************************************************
void main()
{
	int a[6]={2,1,0,5,4,3};
	fastsort(a,0,5);
	for (int i=0;i<6;i++)
	{
		printf("%d ",a[i]);
	}
	return;
}

//************************************************************
//				函数实现
//************************************************************
	//---------快速排序----------
void	fastsort(int *arr,int low,int high)
{
	if (low < high )
	{
		int pos=findpos(arr,low,high);
		fastsort(arr,low,pos-1);
		fastsort(arr,pos+1,high);
	}
	
	return;
}

	//--------查找位置-----------
int		findpos(int *a,int l,int h)
{
	int tmp=a[l];

	while (l < h)
	{
		while (l < h && a[h] >= tmp)
		{
			h--;
		}
		a[l]=a[h];
		while(l < h && a[l] <= tmp)
		{
			l++;
		}
		a[h]=a[l];
	}
	a[l]=tmp;
	return l;
}























					
							
							
							
