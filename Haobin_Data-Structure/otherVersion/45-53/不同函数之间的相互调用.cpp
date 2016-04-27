# include <stdio.h>

void f();
void g();
void k();

void f()
{
	printf("FFFF\n");
	g();
	printf("1111\n");
}

void g()
{
	printf("GGGG\n");
	k();
	printf("2222\n");
}

void k()
{
	printf("KKKK\n");
}

int main(void)
{
	f();

	return 0;
}