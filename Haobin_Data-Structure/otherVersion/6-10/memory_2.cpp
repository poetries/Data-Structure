# include <stdio.h>
# include <malloc.h>

struct Student
{
	int sid;
	int age;
};

struct Student * CreateStudent(void);
void ShowStudent(struct Student *);

int main(void)
{
	struct Student * ps;

	ps = CreateStudent();
	ShowStudent(ps);

	return 0;
}

void ShowStudent(struct Student * pst)
{
	printf("%d %d\n", pst->sid, pst->age);
}

struct Student * CreateStudent(void)
{
	struct Student * p = (struct Student *)malloc(sizeof(struct Student));
	p->sid = 99;
	p->age = 88;
	return p;
}