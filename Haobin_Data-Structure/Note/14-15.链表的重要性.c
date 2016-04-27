
***************************************************************************************************************************
14.链表的重要性 2012.3.22
15.typedef用法  2012.3.22
***************************************************************************************************************************
typedef 用法

1.
	typedef int	lose; //这样定义以后"lose"变成一个关键字，完全等价于int 例如: lose num=88;<=>int num=88; 完全等价;
2.	
//从以下代码可以看出，typedef类似于宏替换#define
#include "stdio.h"
#include "string.h"

typedef struct Student
{
	int age;
	int sid;
	char name[20];
} ST,* PST;

void main()
{
	ST student;
	student.age=17;
	student.sid=55555;
	strcpy(student.name,"lose");
	printf("name:%s  age=%d  sid=%d\n",student.name,student.age,student.sid);
	PST pst=&student;
	strcpy(pst->name,"xtr");
	pst->age=19;
	pst->sid=18181;
	printf("name:%s   age=%d  sid=%d\n",student.name,student.age,student.sid);
	printf("%c%c%c%c\n",student.name[0],student.name[1],student.name[2],student.name[3]);
}
