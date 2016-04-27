***************************************************************************************************************************
												12.连续存储数组的算法演示1  2012.3.21
												13.连续存储数组的算法演示2	2012.3.21
***************************************************************************************************************************
模块一：线性结构【把所有的结点用一根直线串起来】
		
		连续存储[数组]
		1.	数组：元素类型相同，大小相等
		2.	数组优缺点：（相对于链表）

		
★★★★★   结构体变量不能+-*/,但能相互赋值

int a[10]
int *a=(int *)malloc(sizeof(int))	//java 内部就是这样实现数组的。

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//							数组的模拟
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"      //exit();
struct Arr
{
	int *pbase;			//存储数组的第一个元素的地址。
	int len;			//数组容纳的最大元素个数;
	int cnt;			//当前数组有效元素的个数
};

void init_arr(struct Arr *pArr,int length);				//初始化数组
bool append_arr(struct Arr *pArr,int val);				//追加元素
bool insert_arr(struct Arr *pArr,int pos,int val);		//插入元素      ★★★★★要掌握
bool delete_arr(struct Arr *pArr,int pos);				//删除元素
int	 get(struct Arr *parr,int pos);						//获取数组元素
bool is_empty();										//感觉这函数多余了
bool is_full();											//同上
void sort_arr(struct Arr *parr);						//数组排序      以冒泡法升序为例
void show_arr(struct Arr *starr);						//显示信息
void inversion_arr(struct Arr *pArr);					//数组倒置

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//				主函数
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void main()
{
	struct Arr a;
	init_arr(&a,6);
	append_arr(&a,1);
	append_arr(&a,666);
	append_arr(&a,8);
	append_arr(&a,4);
	append_arr(&a,58);
//	append_arr(&a,6);
//	insert_arr(&a,2,8888);
//	delete_arr(&a,2);
	show_arr(&a);
//	inversion_arr(&a);
	sort_arr(&a);
	show_arr(&a);
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//				数组初始化
//			跨函数使用内存实例 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void init_arr(struct Arr *pArr,int length)
{
	pArr->pbase=(int *)malloc(sizeof(int)*length);
	if(NULL==pArr->pbase)
	{
		printf("分配内存失败！！\n");
		exit(-1);
	}
	else
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return ;
//	pArr->len=99;	
//	(*pArr).len=88;
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组显示  
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void show_arr(struct Arr *starr)
{
	if(0==starr->cnt)
	{
		printf("数组为空！！\n");
	}
	else
	{
	//	printf("pbase=%p,len=%d,cnt=%d\n\n",starr->pbase,starr->len,starr->cnt);
		for (int i=0;i<starr->cnt;i++)
		{
			printf("%d",starr->pbase[i]);
			printf(" ");
		}
		printf("\n");
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组追加  
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool append_arr(struct Arr *pArr,int val)
{
	if (pArr->len==pArr->cnt)
	{
		printf("数组已满，追加失败！！\n");
		return false;
	}
	else
	{
		pArr->pbase[pArr->cnt]=val;
		pArr->cnt++;
		return true;
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组插入数值 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool insert_arr(struct Arr *pArr,int pos,int val)
{
	if (pArr->len==pArr->cnt)
	{
		printf("数组已满,无法插入新的数值!!\n");
		return 0;
	}
	else
	{
		register int cnt2=pArr->cnt;
		for (int i=0;i<=(cnt2-pos+1);i++)
		{
			pArr->pbase[pArr->cnt+1]=pArr->pbase[pArr->cnt];
			pArr->cnt--;
		}
		pArr->cnt=cnt2+1;
		pArr->pbase[pos-1]=val;
		return 1;
	}
	
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			删除数组数值 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
bool delete_arr(struct Arr *pArr,int pos)
{
	if (pos>pArr->cnt||pos<1)
	{
		printf("该元素不存在!!!\n");
		return false;
	} 
	else
	{
		int pos1=pos,deleteval=pArr->pbase[pos-1];
		for (int i=0;i<pArr->cnt;i++)
		{
			pArr->pbase[pos-1]=pArr->pbase[pos];
			pos++;
		}
		pArr->cnt--;
		printf("您删除的是第%d个元素(值为：%d)\n",pos1,deleteval);
		return true;
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			数组倒置 
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void inversion_arr(struct Arr *pArr)
{
	int *p1,*p3;
	int temp;
	p1=&pArr->pbase[0];						//p1指向  数组第一个元素
	p3=&pArr->pbase[pArr->cnt-1];			//p3指向  数组最后一个元素
	for (int i=0;i<pArr->cnt/2;i++)
	{					
		temp=*p1;			
		*p1=*p3;
		*p3=temp;
		p1=&pArr->pbase[i+1];				
		p3--;		
	}
//	show_arr(pArr);
	printf("\n");
}



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			冒泡排序（升序）
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

void sort_arr(struct Arr *parr)
{
	int i,j,t;
	for (i=0;i<parr->cnt;i++)
	{
		for (j=i+1;j<parr->cnt;j++)
		{
			if (parr->pbase[i]>parr->pbase[j])
			{
				t=parr->pbase[i];
				parr->pbase[i]=parr->pbase[j];
				parr->pbase[j]=t;
			}
		}
	}
}

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//			获取数组元素
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int get(struct Arr *parr,int pos)
{
	if (pos<1 || pos>parr->cnt)
	{
		printf("该数组元素为无效值\n");
		return 0;
	} 
	else
	{
		printf("您想获取的是第%d个元素，其值为：%d\n",pos,parr->pbase[pos-1]);
		return parr->pbase[pos-1];
	}
}
