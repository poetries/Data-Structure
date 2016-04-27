
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
