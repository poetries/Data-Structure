
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
