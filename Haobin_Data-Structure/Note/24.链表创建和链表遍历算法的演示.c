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