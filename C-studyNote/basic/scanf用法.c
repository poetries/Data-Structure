/*
scanf用法

通过键盘将数据输入到变量中

两种用法：

	用法一：scanf（“输入控制符”，输入参数）
	功能： 将键盘输入的字符转化为输入控制符所规定格式的数据，然后存入以输入参数的值为地质的变量

 
	用法二：scanf（“非法输入控制符 输入控制符”，输入参数）
功能： 将从键盘输入的字符转化为输入控制符所规定格式的数据，然后存入以输入参数的值为地址的变量中，非法输入控制符必须原样输入


	 如何使用scanf写出高质量代码：
  
	1、使用scanf之前，最好先使用printf提示用户以什么样的方式输入
	2、scanf最好不要使用非控制符，尤其是不要使用\n
	3、应该编写代码对用户的非法输入进行处理

*/

/**
//不含输入控制符
#include<stdio.h>

void main()
{

	int i;
	
	scanf("%d",&i); //&表示变量的地址，是一个取地址符
	printf("i = %d\n",i);
}




//含输入控制符（一般不采用这方式）

#include<stdio.h>

void main()
{

	int i;
	
	scanf("m%d",&i); //当运行输入时应当加上m才正确，m123是正确的输入，123是非法的输入
	printf("i = %d\n",i);
}




//一次给多个变量赋值

#include<stdio.h>

void main()
{
	int i,j;

	printf("请输入两个值，中间以空格分开：");
	scanf("%d %d",&i,&j);//不要使用\n
	printf("i = %d,j = %d\n",i,j);
}

**/



//对用户非法输入的处理

#include<stdio.h>

void main()
{

	int i;
	char ch;

	printf("i = %d",i);
	scanf("%d",&i);
	printf("i = %d\n",i);

	//....
	while ( (ch = getchar()) !='\n')//对用户非法输入干掉
		continue;

	int j;
	scanf("%d",&j);
	printf("j = %d\n",j);


}
