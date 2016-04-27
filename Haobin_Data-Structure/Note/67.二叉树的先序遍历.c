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
