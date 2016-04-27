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