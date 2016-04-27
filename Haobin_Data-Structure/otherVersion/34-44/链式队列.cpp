/*
	2008年3月26日16:31:56
	链式队列
*/

# include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *pNext;
}NODE, *PNODE;

class Queue
{
public:
	Queue()
	{
		this->pHead = this->pTail = new NODE;
		this->pHead->pNext = NULL;
	}
	
	void InQueue(int val)
	{
		PNODE pNew = new NODE;

		pNew->data = val;
		pNew->pNext = NULL;
		
		pTail->pNext = pNew; //将pNew挂到队列尾部 
		pTail = pNew; //注意是尾指针上移
	
		return;
	}

	bool Empty() const
	{
		if (this->pHead == pTail)
			return true;
		else
			return false;
	}

	int OutQueue()
	{
		if (Empty())
		{
			cout <<"队列为空，无法出队!" << endl;
		}
		else
		{
			PNODE pTemp = pHead->pNext; //pHead不是要删除的队首元素，pHead->pNext所指向的元素才是要删除的元素，
			pHead->pNext = pTemp->pNext;
			int val = pTemp->data;

			delete pTemp;

			if (NULL == pHead->pNext) //如果队列为空
			{
				pTail = pHead; //尾指针也指向无用的头结点
			}
			
			return val;
		}
	}

	//遍历队列
	void Travers(void) const
	{
		PNODE pTemp = pHead->pNext;

		while (pTemp != NULL)
		{
			cout << pTemp->data << "  ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}

	void Clear()
	{
		while (! this->Empty())
		{
			OutQueue();
		}
	}
	
	~Queue()
	{
		this->Clear(); 
		delete pHead;
	}

private:
	PNODE pHead, pTail; //pHead指向无用的头结点 pHead->pNext才是指向队首元素， pTail指向队尾元素
};

int main(void)
{
	Queue Q;

	for (int i=0; i<5; ++i)
		Q.InQueue(i+1);

	Q.Travers();

	Q.OutQueue();
	Q.OutQueue();

	Q.Travers();

	Q.Clear();
	Q.OutQueue();

	return 0;
}