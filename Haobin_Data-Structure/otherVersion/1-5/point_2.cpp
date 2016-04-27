# include <stdio.h>

int main(void)
{
	int * p; //p是个变量名字, int * 表示该p变量只能存储int类型变量的地址
	int i = 10;
	int j;

	p = &i;
	*p = i; // 等价于 i = i;
//	j = *p; // 等价于 j = i;
	printf("i = %d, j = %d, *p = %d\n", i, j, *p);	

	return 0;
}