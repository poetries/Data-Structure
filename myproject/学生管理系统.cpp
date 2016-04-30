#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<conio.h>


//定于学生的结构体

struct student
{
	int num;//学号
	char name[15];//姓名
	char sex[2];//性别
	int age;//年龄
	double score[3];//三门课程的分数
	double sum;//总分
	double ave;//平均分

};

typedef struct node //定义学生链表的节点结构
{
	struct student data;//数据域
	struct node *next;//指针域

}Node, *link;

//实现主功能菜单
int  menu_select()
{
	int i;
	printf("\n\n\t ***************************STUDENT LIST***********************|\n");
	printf("\t}*                   1.input record							    *|\n");
	printf("\t}*                   2.delete record								*|\n");
	printf("\t}*                   3.list record								*|\n");
	printf("\t}*                   4.search record								*|\n");
	printf("\t}*                   5.save record								*|\n");
	printf("\t}*                   6.load record								*|\n");
	printf("\t}*                   7.quit										*|\n");
	printf("\n\n\t **************************************************************|\n");

	do
	{
		printf("\n\tEnter your  choice:");
		scanf("%d", &i);

	} while (i<=0||i>7);
	return i;

}

//输入学生信息模块
void input(link l)
{
	int i;
	Node *p, *q;//定义两个指针 将新的节点插入链表尾部
	while (l)
	{
		p = (Node *)malloc(sizeof(Node));
		//检测创建的内存是否成功
		if (NULL == l)
		{
			printf("内存分配失败!!");
			exit(-1);
		}

		//内存成功分配 执行以下

		printf("input number:");
		scanf("%d",&p->data.num);//将用户输入的数据存放在数据域num这个成员里面
		if (p->data.num == 0)//判断学生输入的学号是否为零
			break;

		//用for循环遍历用户所输入的学好是在链表中存在了 
		for (q = l; q->next != NULL; q = q->next) //q = l使q指向链表中第一个节点
		{

			if (q->data.num == p->data.num)//如果用户输入的学号在链表中存在
			{
				printf("the number has existed,please input again:");
				scanf("%d", &p->data.num);
			}
		}

		//数据域中已完成

		printf("input name:");
		scanf("%s", &p->data.name);
		printf("input sex:");
		scanf("%s",&p->data.sex);
		printf("input age:");
		scanf("%d", &p->data.age);
		//for遍历三门课成绩 保存到数组中
		for (i = 0; i < 3; i++)
			scanf("lf", &p->data.score[i]);

		//计算成绩总和
		p->data.sum = p->data.score[0] + p->data.score[1] + p->data.score[1];

		//三门成绩平均值
		p->data.ave = p->data.sum / 3;

		//使创建的新节点的next域为空 要插入到链表表尾  也就是新创建的节点将是链表中的最后一个节点
		p->next = NULL;
		q->next = p;//使之前的next域链表的指针指向新创建的节点
		q = p;//指针q指向新创建的节点  也就是链表中最后一个节点

	}
}

//保存学生信息模块
void save(link l)
{
	Node *p;
	FILE *fp;//定义文件类型指针操作文件
	p = l->next;//使p指向头节点的下一个节点

	if((fp=fopen("f:\\studentlist","wb")) == NULL)
	{
		printf("can not open file\n");
		exit(-1);
	}
	printf("\nSaving file\n");
	//遍历链表要通过指针 就可以找到来拿表中所有的节点

	while(p)  //如果p不空 将链表中学生信息写入磁盘文件中
	{
		fwrite(p,sizeof(Node),l,fp);//将当前结点写入文件中
		p=p->next; //写入完成后 移动指针 给p新的值
	}
	fclose(fp);//关闭文件
	getch();//按任意键后退出 
}

//加载学生信息模块
void load(link l)
{
	Node *p,*r;
	FILE *fp;
	l->next = NULL;
	r = l;
	if((fp=fopen("f:\\studentlist","rb"))=NULL)//打开磁盘文件
	{
		printf("can not open file\n");
		exit(-1);
	}
	printf("\nLoading file\n");

	//使用while将磁盘文件加载到内存中
	while(!feof(fp))//判断是否到达磁盘文件尾部
	{
		p = (Node *)malloc(sizeof(Node));  //创建节点
		//检测创建的内存是否成功
		if (NULL == l)
		{
			printf("内存分配失败!!"); //因为在分配内存空间的时候有可能碰队中没有可分配内存的情况 返回的就是空指针
			exit(-1);
		}
	//内存成功分配  开始读入
		if((fread(p,sizeof(Node),l,fp))!=l)
			break;//读入失败 break 退出
		else
		{
			p->next = NULL;
			r->next = p;  //把一个新节点加入到链表中
			r = p;//指针r指向创建的链表的节点 也就是当前链表中的最后一个节点
		}
	}
	fclose(fp);
	getch();//按任意键后退出 
}

//显示学生信息模块
void display(Node *p) //显示节点的信息
{
	printf("STUDENT INFORMATTON\n");
	printf("number:%d\n",p->data.num);
	printf("name:%s\n",p->data.name);
	printf("sex:%s\n",p->data.sex);
	printf("age:%d\n",p->data.age);
	printf("Chinese:%lf\n",p->data.score[0]);
	printf("Math:%lf\n",p->data.score[1]);
	printf("English:%lf\n",p->data.score[2]);
	printf("sum:%lf\n",p->data.sum);
	printf("avaerage:%lf\n",p->data.ave);
}

void list(link l)
{
	Node *p;
	p = l->next;//指针p付初值
	if(p == NULL)
		printf("no student record!");
	while(p!=NULL) //while将链表中所有学生的信息显示出来
	{
		display(p);
		p = p->next;
	}
	getch();//按任意键后退出 
}

//查找学生信息模块
void search(link l)
{
	int num;//接受用户输入的学号
	Node *p;//定义指向链表的指针
	p = l->next;//变量赋初值 让p指针指向链表中第一个存储数据的节点
	printf("input number of the student:");//提示用户要输入查找的学好
	scanf("%d",&num);

	//遍历链表 使用指针变量P遍历
	while(p) //判断指针是否为空
	{
		if(p->data.num == num) //节点中的某一个值和用户输入的相等就显示学生信息
		{
			display(p);
			getch();//按任意键后退出 
			break;
		}
		
		//节点中的某一个值和用户输入的不相等  修改指针p的值
		p = p->next;

	}

	if(p==NULL)//在链表中没有找到这样一个节点
		printf("没有找到指定的学生!\n");
}


//删除学生信息模块

void del(link l)
{
	int num;//用来接收用户要删除的学好
	Node *p,*q;
	q = l; //q指向链表中的头节点
	p = q->next;//p指向来拿表中的头节点的下一个节点
	printf("请输入您需要删除的学生的学号：");
	scanf("%d",&num);

	//在链表中删除指定的表节点  在链表中查找

	while(p)
	{
		if(num==p->data.num) //找到当前结点情况下
		{
			q->next=p->next; //删除的过程就是修改指针的过程
			free(p);
			printf("删除成功!");
			break;
		}
		else //没有找到当前结点  及用户输入的和节点中不匹配
		{
			q = p;
			p = q->next;

		}
	}

	if(p == NULL)//指针变量当前值空 没有找到这样的信息
		printf("没有找到要删除的学生!");
}



void main()
{
	link l;

	//动态分配内存
	l = (Node*)malloc(sizeof(Node));

	//检测创建的内存是否成功
	if (NULL == l)
	{
		printf("内存分配失败!!");
		exit(-1);
	}
	l->next = NULL;//把新分配的节点的next置为空
	while (l)
	{
		system("cls");//清屏函数
		switch (menu_select())
		{
		case 1:
			input(l);//input输入一条记录 学生的信息保存在l所指向的链表中
			break;
		case 2:
			del(l);//调用del函数 删除l指针所指向的链表节点
			break;
		case 3:
			list(l);//列出学生所有的信息
			break;
		case 4:
			search(l);//查找指定的学生信息
			break;
		case 5:
			save(l);//把链表中的学生信息保存到磁盘上
			break;
		case 6:
			load(l);//从磁盘上加载学生的信息
			break;
		case 7:
			exit(0);//退出系统

		}
	}
}

