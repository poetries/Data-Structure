# include <stdio.h>

//假定n的值是1或大于1的值
long f(long n)
{
	if (1 == n)
		return 1;
	else
		return f(n-1) * n;

}

int main(void)
{
	printf("%ld\n", f(100));

	return 0;
}