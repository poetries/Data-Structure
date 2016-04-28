#include<stdio.h>
#include<malloc.h>

typedef struct QUEUE
{
	int * pBase;//定义一个数组 用于保存数组的首地址
	int front;
	int rear;

}QUEUE;

void init(QUEUE *); //初始化队列元素
bool en_queue(QUEUE *,int val); //入队
void traverse_queue(QUEUE *); //遍历队列
bool full_queue(QUEUE *); //队列已满
bool out_queue(QUEUE *,int *); //出队
bool empty_queue(QUEUE *);// 队列空

void main()
{
	int val;
	QUEUE Q;
	init(&Q);

	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);

	traverse_queue(&Q);

	if(out_queue(&Q,&val))
		printf("出队成功，出队的元素是：%d\n",val);
	else
		printf("出队失败!");

	traverse_queue(&Q);
}

void init(QUEUE *pQ) 
{
	pQ->pBase = (int *)malloc(sizeof(int)*6);
	pQ->front = 0;
	pQ->rear = 0;

}

bool full_queue(QUEUE * pQ)
{
	if((pQ->rear+1)%6 == pQ->front)
		return true;
	else
		return false;
}

bool empty_queue(QUEUE *pQ)
{
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}



bool en_queue(QUEUE * pQ,int val)
{
	if(full_queue(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear] = val; //存放值
		pQ->rear = (pQ->rear +1)%6; //往后移动一个

		return true;
	}
} 

void traverse_queue(QUEUE *pQ)
{
	int i = pQ->front;
	while(i!=pQ->rear)
	{
		printf("%d ",pQ->pBase[i]);
		i = (i+1)%6;
	}
	printf("\n");
	return;
}

bool out_queue(QUEUE *pQ,int *pVal)
{
	if(empty_queue(pQ))
		return false;
	else
	{
		*pVal  = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%6;
	}

	return true;
}
