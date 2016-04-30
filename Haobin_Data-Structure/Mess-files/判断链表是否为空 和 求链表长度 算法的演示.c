#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>  //exit()

//把每个节点的数据类型模拟出来
typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//pNext指向和他本身数据类型一样的节点

}NODE,*PNODE;//NODE等价于struct Node,PNODE等价于struct Node*


//判断链表是否为空
bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
		return true;
	else
		return false;
}

//链表长度
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;//len用于求链表的长度

	//链表不为空 执行while

	while(NULL != p)
	{
		++len;
		p = p->pNext;
	}
	return len;
}


//在pHead所指向链表的第pos个节点的前面插入新的节点，该节点的值是val 并且pos的值是从1开始

bool insert_list(PNODE pHead,int pos,int val)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || NULL==p)
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;

}


//删除

bool delete_list(PNODE pHead,int pos,int *pVal)
{
	int i = 0;
	PNODE p = pHead;

	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || NULL==p->pNext)
		return false;

	

	PNODE q = p->pNext;
	*pVal = q->data;//删除节点前把数据保存pVal起来

	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
} 


//排序

void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);

	PNODE p,q;
	
	//i=0数组中第一个有效元素的下标  p=pHead->pNext是链表中第一个有效元素的地址
	for(i=0,p=pHead->pNext;i<len;++i,p=p->pNext)
	{
		//j是i元素的下一个下标  q是p下一个元素的地址
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(p->data > q->data) //和数组中一样:a[i]>a[j]
			{
				t = p->data;       //t = a[i];
				p->data = q->data; //a[i] = a[j];
				q->data = t;      //a[j] = t;
			}
		}
	}
	return;
}


//返回已经造好的链表的头节点的地址

PNODE create_list()
{
	int len;//存放有效节点个数
	int i;
	int val;//临时存放用户输入节点的值

	//分配一个存放有效数据的头节点

	PNODE pHead = (PNODE)malloc(sizeof(NODE));

	//检测是否分配失败
	if(NULL == pHead)
	{
			printf("分配失败，程序结束!");
			exit(-1);
	}

	PNODE pTail = pHead;//构造一个永远指向最后一个节点的指针  pTail和pHead开始指向了头节点
	pTail->pNext = NULL;//最后一个指针域位空

	printf("请输入您要生成链表节点的个数：len = ");
	scanf("%d",&len);

	//每循环一次用pNew造出一个新的节点 循环len次 每一次分配一个节点 用pNew表示这个节点
	for(i=0;i<len;++i)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);

		PNODE pNew =(PNODE)malloc(sizeof(NODE));
		if(NULL == pHead)
		{
			printf("分配失败，程序结束!");
			exit(-1);
		}

		pNew->data = val;//把用户输入的临时的数据存放在数据域
		pTail->pNext = pNew;//把新生成的节点pNew挂到pTail后面去
		pNew->pNext = NULL;//如果新生成的节点最后一个指针是空
		pTail = pNew;//新生成的节点最后一个指针是空付给pTail让pTail永远指向最后一个节点
	}
	return pHead;//返回头节点的地址
}

//遍历输出

void traverse_list(PNODE pHead)  //形参接受主函数发送过来的头节点的地址
{
	//定义一个指向第一个有效节点
	PNODE p = pHead->pNext;

	//先判断 如果链表为空 p的值可能为空 链表为空只有一个头节点  p不为空p指向一个有效节点 输出

	while(NULL!=p)
	{
		printf("%d ",p->data);
		p = p->pNext;//p往后移动一个  不能写成p++

	}
	printf("\n");
	return;//结束函数  写这个目的清晰
}

void main()
{
	PNODE pHead = NULL;
//	int val;
	pHead = create_list();//构建一个非循环单链表 并将链表头节点地址付给怕pHead
	traverse_list(pHead);//把地址发送给traverse_list()遍历输出

//	insert_list(pHead,4,33);
	sort_list(pHead);
	
/*
if(	delete_list(pHead,4,&val))
{
	printf("删除成功!您删除的元素是%d\n",val);
}
else
{
	printf("删除失败!\n");
}

 */
	traverse_list(pHead);
//	int len = length_list(pHead);
//	printf("链表长度是%d\n",len);

/*
	if(is_empty(pHead))
		printf("链表为空!\n");
	else
		printf("链表不为空!\n");
*/


}
