
/*
//求1-100之间所有的能被3整除的数之和
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    for (i = 3;i<=10; ++i)
    {
        if(i%3 == 0)
          sum = sum + i;
        printf("sum = %d\n",sum);
    }
        
}
  
  
//1到100奇数之和
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
        sum += i;
    }
    printf("sum = %d\n",sum);
}
 
//1到100奇数个数
#include<stdio.h>
void main()
{
    int i;
    int cnt = 0;//个数cnt
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
            ++cnt;
    }
    printf("cnt = %d\n",cnt);
}
   
//1到100奇数平均值
#include<stdio.h>
void main()
{
    int i;
    int sum = 0;
    int cnt = 0;
    float avg;
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
        {
            sum += i;
            ++cnt;
        }
    }
    avg = 1.0*sum / cnt;  //1.0默认double
    printf("sum = %d\n",sum);
    printf("cnt = %d\n",cnt);
    printf("avg = %f\n",avg);
}
 
//循环的举例  1到100奇数之和 1-100偶数之和
#include<stdio.h>
void main()
{
    int i;
    int sum1 = 0; //奇数和
    int sum2 = 0; //偶数和
    for(i = 1;i<101;++i)
    {
        if(i%2 == 1)
            sum1 = sum1 + i;
        
        else
            sum2 = sum2 + i;
    }
    printf("sum1 = %d\n",sum1);
    printf("sum2 = %d\n",sum2);
}
//求1+1/2+1/3+...+1/100之和
#include<stdio.h>
void main()
{
    int i;
    float sum = 0;
    for(i = 1;i<101; ++i)
    {
        sum = sum + 1.0/i; //强制类型转换  格式 （数据类型）（表达式）功能：把表达式强制转换给前面转换的类型
                                //  sum = sum + 1/(float)i  --->ok
                                //  sum = sum + (float)(1/i) --->不对的
                                //  sum = sum + 1.0/i  更简洁
    }
    printf("sum = %f\n",sum);
}
*/
/*
//递归求1-100的和
#include<stdio.h>

long sum(int val)
{
	int i;

	if(val == 1)
		return 1;
	else
	{
		return (sum(val-1) + val);
	}
}

void main()
{

	printf("1-100的和是：%d\n",sum(100));
}

*/

//递归求阶乘

#include<stdio.h>

long f(int n)
{
	int i;
	
	if(n == 1)
		return 1;
	else
		return f(n-1)*n;
}

void main()
{
	int n;
	printf("请输入您要求的阶乘：");
	scanf("%d",&n);
	printf("所求阶乘是：%d\n",f(n));
}
