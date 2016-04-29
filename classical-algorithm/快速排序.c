//快速排序

#include<stdio.h>

int FindPos(int * a, int low, int high)
{
	int val = a[low];

	while (low < high)
	{
		while (low<high  && a[high]>=val)
			--high;
		a[low] = a[high];

		while (low<high && a[low]<=val)
			++low;
		a[high] = a[low];
	}//终止while循环之后low和high一定是相等的

	a[low] = val; 

	return high; //high可以改为low, 但不能改为val 也不能改为a[low]  也不能改为a[high]
}

void QuickSort(int *a,int low,int high)
{
	int pos;

	if(low<high)
	{
		pos = FindPos(a,low,high);//找到a数组下标low-high  
		QuickSort(a,low,pos-1);//把元素劈成两半  左半边
		QuickSort(a,pos+1,high);//右半边

	}
}

void main()
{
	int i;
	int a[6] = {2,1,3,0,5,4};

	QuickSort(a,0,5);//0表示第一个元素下标 5表示最后一个元素的下标
	
	for(i = 0;i<6;++i)
		printf("%d\n",a[i]);

}

