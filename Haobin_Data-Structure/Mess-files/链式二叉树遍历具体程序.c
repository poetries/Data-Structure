/*
	时间：2016-4-29

	二叉树遍历程序具体演示：

			先序遍历结果:
							A
							B
							C
							D
							E
			中序遍历结果:
							B
							A
							D
							E
							C
			后序遍历结果:
							B
							E
							D
							C
							A
*/


#include<stdio.h>
#include<malloc.h>

struct BTNode
{
	char data;
	struct BTNode *pLchild; //p是指针、L是左、child是孩子
	struct BTNode *pRchild;
};

//造二叉树

struct BTNode * CreateTRee(void)
{
	struct BTNode *pA = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode *pB = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode *pC = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode *pD = (struct BTNode*)malloc(sizeof(struct BTNode));
	struct BTNode *pE = (struct BTNode*)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;

}

//先序遍历

void preTraverseBTree(struct BTNode *pT)
{
	/*
		二叉树的先序遍历
		先访问     根节点
		再先序访问 左子树
		再先序访问 右子树
	*/

	
	if(pT!=NULL)
	{
		
		printf("%c\n",pT->data); //先根节点

		//PT->pLchild可以代表整个左子树

		if(NULL!=pT->pLchild)//先序遍历左子树
		{
			preTraverseBTree(pT->pLchild);
		}

	
		if(NULL!=pT->pRchild)//先序遍历右子树
		{
			preTraverseBTree(pT->pRchild);
		}
	}
} 

//中序遍历

void InTraverseBTRee(struct BTNode *pT)
{
	/*
		二叉树的中序遍历
		先中序遍历 左子树
		再中序访问 根节点
		再中序访问 右子树
	*/

	if(pT != NULL)
	{
	

		//PT->pLchild可以代表整个左子树

		if(NULL!=pT->pLchild)//中序遍历左子树
		{
			InTraverseBTRee(pT->pLchild);
		}

		printf("%c\n",pT->data); //中序遍历根节点

		if(NULL!=pT->pRchild)//中序遍历右子树
		{
			InTraverseBTRee(pT->pRchild);
		}
	}
}

//后续遍历

void posTraverseBTRee(struct BTNode *pT)
{
	/*
		二叉树的后续遍历
		中序遍历 左子树
		中序遍历 右子树
		访问     根节点
	*/

	if(pT != NULL)
	{
	

		//PT->pLchild可以代表整个左子树

		if(NULL!=pT->pLchild)//后续遍历左子树
		{
			posTraverseBTRee(pT->pLchild);
		}

		if(NULL!=pT->pRchild)//后续遍历右子树
		{
			posTraverseBTRee(pT->pRchild);
		}

		printf("%c\n",pT->data); //后续遍历根节点

	}
}  

void main()
{
	struct BTNode *PT = CreateTRee(); //CreateTRee()动态的 返回根节点的地址  PT静态的存储根节点的地址
	
	printf("先序遍历结果:\n");
	preTraverseBTree(PT);//先序输出

	printf("中序遍历结果:\n");
	InTraverseBTRee(PT);//中序输出

	printf("后序遍历结果:\n");
	posTraverseBTRee(PT);//后续输出


}
