# include <stdio.h>
# include <string.h>

struct Student
{	
	int sid;
	char name[200];
	int age;
}; //分号不能省

int main(void)
{
	struct Student st = {1000, "zhangsan", 20};
	printf("%d  %s  %d\n", st.sid, st.name, st.age);

	st.sid = 99;
	//st.name = "lisi";  //error
	strcpy(st.name, "lisi");
	st.age = 22;
	printf("%d  %s  %d\n", st.sid, st.name, st.age);

	//printf("%d %s %d\n", st);  //error
	return 0;
}