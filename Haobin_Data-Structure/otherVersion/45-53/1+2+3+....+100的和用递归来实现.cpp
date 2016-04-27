# include <stdio.h>

long sum(int n)
{
	if (1 == n)
		return 1;
	else
		return n + sum(n-1);
}

int main(void)
{
	printf("%ld\n", sum(100));

	return 0;
}

