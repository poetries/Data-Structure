# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int a[5] = {4, 10, 2, 8, 6};
	
	int len;
	printf("请输入你需要分配的数组的长度: len = ");
	scanf("%d", &len);
	int * pArr = (int *)malloc(sizeof(int) * len);
//	*pArr = 4;  //类似于 a[0] = 4;
//	pArr[1] = 10; //类似于a[1] = 10;
//	printf("%d %d\n", *pArr, pArr[1]);

	//我们可以把pArr当做一个普通数组来使用
	for (int i=0; i<len; ++i)
		scanf("%d", &pArr[i]);

	for (i=0; i<len; ++i)
		printf("%d\n", *(pArr+i));

	
	free(pArr);  //把pArr所代表的动态分配的20个字节的内存释放

	return 0;
}