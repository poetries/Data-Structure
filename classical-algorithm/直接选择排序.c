//直接选择排序

#include<stdio.h>

void sort(int *a,int len)
{
	int i,j,min,t;

	for(i = 0;i<len-1;++i)
	{
		for(min=i,j=i+1;j<len;++j)
		{
			if(a[min]>a[j])
				min = j;

		}

		if(min!=i)
		{
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
}

void main()
{
	int a[6] = {4,0,3,2,5,1};

	sort(a,6);//a代表数组的首地址

	for(int i=0;i<6;++i)
		printf("%d\n",a[i]);
}
