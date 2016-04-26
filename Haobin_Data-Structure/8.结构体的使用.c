//结构体：结构体是用户根据实际需要自己及定义的数据类型

//相对于C++的类而言，结构体里只能有属性，没有方法，就是说里面没函数。而类里可以有类函数。
//和类不同结构体适用于算法。

#include "stdio.h"
#include "string.h"

struct	Student
{
	int sid;
	char name[20];
	int age;
};							//末尾分号不能省略。。。。。。。。。

void main()
{
	struct Student	st={303930,"lose",12};					//第一种方式
	printf("%d  %s     %d\n",st.sid,st.name,st.age);

	st.sid=123456;
	//st.name="lose all";                    error!!
	strcpy(st.name,"loseall");
	st.age=34;
	printf("%d  %s  %d\n",st.sid,st.name,st.age);
	
	struct Student *pst;
	pst=&st
	(*pst).sid=999999;
	pst->name="nisi";
}


//两种方式，假如有结构体：
			struct Student
			{
				int sid;
				char name[20];
				int age;
			}
		struct Student st={1111111,"2222222",3333333}
		struct Student *pst=&st;
		
	则有：
		st.sid=100
		pst->sid=100    两种方式效果相同
		
************************************************************
//			比较两种方式的不同
#include "stdio.h"
#include "string.h"

struct Student
{
	int sid;
	char name[20];
	int age;
};

void f(struct Student *pst);		
void g1(struct Student st);
void g2(struct Student *st);


void main()
{
	struct Student	st;								
	f(&st);
	//方法一输出,特点是耗内存，耗时间
	g1(st);
	//方法二输出:
	g2(&st);
	
}

void f(struct Student *pst)
{
	pst->sid=1111111;
	strcpy(pst->name,"pst_name");
	pst->age=200;
}

void g1(struct Student st)
{
	printf("%d  %s  %d  方法1   特点是耗内存，耗时间\n",st.sid,st.name,st.age);
}

void g2(struct Student *st)
{
	printf("%d  %s  %d  方法2\n",st->sid,st->name,st->age);
}
