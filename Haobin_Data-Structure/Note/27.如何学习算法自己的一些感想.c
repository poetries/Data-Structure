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
