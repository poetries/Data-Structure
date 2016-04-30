#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>  //exit()

//把每个节点的数据类型模拟出来
typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//pNext指向和他本身数据类型一样的节点

}NODE,*PNODE;//NODE等价于struct Node,PNODE等价于struct Node*

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
	pHead = create_list();//构建一个非循环单链表 并将链表头节点地址付给怕pHead
	traverse_list(pHead);//把地址发送给traverse_list()遍历输出
}
