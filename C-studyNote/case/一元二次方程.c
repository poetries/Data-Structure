
#include<stdio.h>
#include<math.h>
void main()
{
    int a=1,b=5,c=3;
    double delta;//用于存放b*b-4*a*c
    double x1,x2;//函数的两个解
    delta = b*b-4*a*c;
    if(delta>0)
    {
        x1 = (b*b+sqrt(delta))/(2*a);
        x2 = (b*b-sqrt(delta))/(2*a);
        printf("该一元二次方程有两个解,x1 = %f,x2 = %f\n",x1,x2);
    
    }
    else if(delta=0)
    {
        x1 = (-b)/(2*a);
        x2 = x1;
        printf("该一元二次方程有唯一解，x1 = x2 =%f\n",x1=x2);
    }
    else
    {
        printf("无解\n");
    }
}
