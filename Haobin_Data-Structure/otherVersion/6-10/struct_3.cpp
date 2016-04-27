# include <stdio.h>
# include <string.h>

struct Student
{	
	int sid;
	char name[200];
	int age;
}; //分号不能省

void f(struct Student * pst);
void g(struct Student st);
void g2(struct Student *pst);

int main(void)
{
	struct Student st;  //已经为st分配好了内存

	f(&st);
	g2(&st);

	//printf("%d %s %d\n", st.sid, st.name, st.age);

	return 0;
}

//这种方式耗内存 耗时间 不推荐
void g(struct Student st)
{
	printf("%d %s %d\n", st.sid, st.name, st.age);	
}

void g2(struct Student *pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);	
}

void f(struct Student * pst)
{
	(*pst).sid = 99;
	strcpy(pst->name, "zhangsan");
	pst->age = 22;
}