
***************************************************************************************************************************
										35.什么是队列 								2012.3.28
										36.队列的分类和链式队列伪算法的讲解 		2012.3.28
										37.学习循环队列必须要弄清楚的7个问题概述 	2012.3.28
										38.静态队列为什么必须是循环队列 			2012.3.28
										39.循环队列需要几个参数来确定及其含义的讲解 2012.3.28
										40.循环队列各个参数的含义					2012.3.28
										41.循环队列入队伪算法讲解					2012.3.28
										42.循环队列出队伪算法讲解					2012.3.28
										43.如何判断循环队列是否为空					2012.3.28
										44.如何判断循环队列是否已满					2012.3.28
										45.求链表的长度
										46.复习上节课队列知识						
										47.循环队列程序演示							2012.3.28
										48.队列的具体应用							2012.3.28					
										49.可以不看
***************************************************************************************************************************
队列：
	 先进先出的存储结构

栈	：
	 先进后出的存储结构 (First In Last Out) (FILO) 
						(Last In First Out) (LIFO)

队列分类：
		链式队列：（顾名思义，以链表实现，所以是动态的。）
		静态队列：循环队列(用数组实现)
		


循环队列的讲解
		1.静态队列为什么必须是循环队列
			重复利用空间
		
		2.循环队列需要几个参数来确定   
			需要2个参数（指针）  front和rear 
		
		3.循环队列各个参数的含义
			1.队列初始化
				front=rear=0
			2.队列非空
				front指向队列第一个有效元素，rear指向最后一个有效元素的下一个元素
			3.队列为空
				front=rear  但二者的值不一定为0！！
				
		4.循环队列入队伪算法讲解
			两步完成
				1.将入队的值赋给r所指向的地址
				2.r=(r+1)%n    (n代表数组长度)
		
		5.循环队列出队伪算法讲解
			f=(f+1)%n
			
		6.如何判断循环队列是否为空
			front=rear 则队列一定为空
			
		7.如何判断循环队列是否已满
			front与rear相邻则栈满
			if((rear+1)%n==f)
			{
				栈满
			}
			else
			{
				不满
			}
		
循环的意义
			在于重复利用空间
		



#include "stdio.h"
#include "malloc.h"

//*****************************************
//			结构体定义
//*****************************************
typedef		struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE, * PQUEUE;

//*****************************************
//			函数声明
//*****************************************
void	init(PQUEUE pq);					//初始化队列
bool	en_queue(PQUEUE ,int);				//入队函数
bool	out_queue(PQUEUE,int *);			//出队函数
bool	emp(PQUEUE);						//判断队列是否为空
bool	full(PQUEUE);						//判断队列是否已满
void	traverse(PQUEUE);					//遍历队列并输出

//*****************************************
//			main函数
//*****************************************
void	main()
{
	QUEUE queue;
	init(&queue);
	en_queue(&queue,1);
	en_queue(&queue,2);
	en_queue(&queue,3);
	en_queue(&queue,4);
	en_queue(&queue,5);
	traverse(&queue);
	int v;
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
	out_queue(&queue,&v);
	traverse(&queue);
}

//*****************************************
//			函数实现
//*****************************************

void	init(PQUEUE pq)
{
	pq->pBase=(int *)malloc(sizeof(int)*6);
	pq->front=0;
	pq->rear=0;
}


bool	en_queue(PQUEUE pq,int val)
{
	if (full(pq))
	{
		printf("队列已满！\n");
		return 0;
	} 
	else
	{
		pq->pBase[pq->rear]=val;
		pq->rear=(pq->rear+1)%6;
		return 1;
	}
}


bool	out_queue(PQUEUE pq,int *val)
{
	if (emp(pq))
	{
		printf("栈空！！\n");
		return false;
	} 
	else
	{
		*val=pq->front;
		pq->front=(pq->front+1)%6;
		return true;
	}
}


bool	emp(PQUEUE pq)
{
	if (pq->front==pq->rear)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

bool	full(PQUEUE pq)
{
	if ((pq->rear+1)%6==pq->front)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void	traverse(PQUEUE pq)
{
	int n=pq->front;
	while (n != pq->rear)
	{
		printf("%d  ",pq->pBase[n]);
		n=(n+1)%6;
	}
	printf("\n");
}



队列的应用
			所有与时间相关的操作都与队列相关