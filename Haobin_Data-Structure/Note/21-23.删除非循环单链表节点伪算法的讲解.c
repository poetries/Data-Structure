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
