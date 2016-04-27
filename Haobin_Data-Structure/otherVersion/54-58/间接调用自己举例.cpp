# include <stdio.h>

void f(int n)
{
	g(n);
}

void g(int m)
{
	f(m);
}

int main(void)
{

	return 0;
}


