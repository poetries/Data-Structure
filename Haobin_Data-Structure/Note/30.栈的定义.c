***************************************************************************************************************************
												30.栈的定义 			2012.3.27
												31.栈的分类 			2012.3.27
												32.栈可以执行哪些操作 	2012.3.27
												33.栈程序演示 			2012.3.27
												34.栈的日常具体应用 	2012.3.27
***************************************************************************************************************************

内存分为 静态内存和动态内存   静态内存分配在栈里，动态内存分配在堆里

栈 由操作系统维护，堆由程序员维护  LIFO原则（last in first out）


分类：
	 静态栈：数组为内核
	 
	 动态栈：链表为内核
	

算法：
	出栈
	压栈
	
	
应用：
	函数调用
	中断
	表达式求值    计算器（两个栈实现）
	内存分配
	缓冲处理
	迷宫        
	
	★★★★★算法的练习  计算器  迷宫



#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

//***************************************
//			结构体定义
//***************************************
typedef struct node
{
	int		data;
	struct	node * pNext;
}NODE,* PNODE;

typedef struct nstack
{
	PNODE	pTop;
	PNODE	pButtom;
}STACK, * PSTACK;

//***************************************
//			函数声明
//***************************************
void	init(PSTACK s);						//初始化 栈指针
void	push(PSTACK s,int val);				//压栈 函数
int		traverse(PSTACK s);					//遍历 栈段 并输出
bool	pop(PSTACK s,int * val);			//出栈 函数
bool	emp(PSTACK s);						//检测栈段是否为空
void	clear(PSTACK s);					//清空栈

//***************************************
//			入口函数
//***************************************

void main()
{
	int val;
	STACK S;
	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);
	if (pop(&S,&val))
	{
		printf("出栈的元素是%d\n",val);
	}
	clear(&S);
	traverse(&S);
	return;

}


//***************************************
//			函数实现
//***************************************
void	 init(PSTACK s)
{
	s->pButtom=(PNODE)malloc(sizeof(NODE));
	s->pButtom->pNext=NULL;
	s->pTop=s->pButtom;
	
}

void	push(PSTACK s,int val)
{
	PNODE newnode=(PNODE)malloc(sizeof(NODE));
	PNODE temp=newnode;
	newnode->data=val;
	newnode->pNext=s->pTop;
	s->pTop=temp;
	return;
}

int	traverse(PSTACK s)
{
	int len=0;
	PNODE pt=s->pTop;
	while (NULL !=pt->pNext)
	{
		len++;
		printf("%d  ",pt->data);
		pt=pt->pNext;
	}
	printf("栈里有%d个元素\n",len);
	return len;
}


bool	pop(PSTACK s,int * val)
{
	if (emp(s))
	{
		printf("栈空！！无法pop!\n");
		return 0;
	} 
	else
	{
		*val=s->pTop->data;

//		PNODE temp=s->pTop->pNext;
//		s->pTop=temp;
//		free(temp);                               //这种情况下是不能用free()释放内存的。

		PNODE temp=s->pTop;
		s->pTop=temp->pNext;
		free(temp);

		temp=NULL;
		return 1;
	}
}

bool	emp(PSTACK s)
{

	PNODE pt=s->pTop;
	if (NULL==pt->pNext)
	{
		return 1;
	} 
	else
	{

		return 0;
	
	}

}



void clear(PSTACK s)
{
	if (emp(s))
	{
		return;
	} 
	else
	{
		PNODE p=s->pTop;
		PNODE q=NULL;
		while (p != s->pButtom)					//如果这里条件写成 while(NULL != p)  会出错!!
		{
			q=p->pNext;
			free(p);
			p=q;
		}
		s->pTop=s->pButtom;

	}
}
