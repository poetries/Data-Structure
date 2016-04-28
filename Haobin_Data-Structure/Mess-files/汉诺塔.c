#include<stdio.h>

void hannuota(int n,char A,char B,char C)
{
	/*
		如果是1个盘子，直接将A柱子上的盘子从A移动到C
		否则：
		1、先将A主子上的n-1个盘子借助C移动到B
		2、直接将A主子上的n个盘子从A移动到C
		3、最后将B主子上的n-1个盘子借助A移动到C

	*/

	if(n == 1)
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
	else
	{
		hannuota(n-1,A,C,B);
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
		hannuota(n-1,B,A,C);
	}
}

void main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	
	int n;
	printf("请输入要移动盘子的个数：");
	scanf("%d",&n);

	hannuota(n,'A','B','C');

}
