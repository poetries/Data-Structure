# include <stdio.h>

int f();

int main(void)
{
	int i = 10;

	i = f();
	printf("i = %d\n", i);

	for (i=0; i<2000; ++i)
		f();

	return 0;
}

int f()
{
	int j = 20;
	return j;
}