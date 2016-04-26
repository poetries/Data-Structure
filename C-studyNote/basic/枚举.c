/**
【枚举】
    什么是枚举：
        把一个事物所有可能取值一一列举出来
    怎样使用枚举
    
    枚举的优缺点：
        代码更安全
        书写麻烦
//枚举
#include<stdio.h>
//只定义了一个数据类型 并没有定义变量 该数据类型的名字是enum WeekDay
enum WeekDay
{
    Monday,TuesDay,WednesDay,ThursDay,FriDay,SaturDay,Sunday	
};
void main()
{
    enum  WeekDay day = WednesDay;
    printf("%d\n",day);	
}
    **/
//枚举的应用举例
#include<stdio.h>
enum weekday
{
    Monday,TuesDay,WednesDay,ThursDay,FriDay,SaturDay,Sunday	
};
void f(enum weekday i)//本函数的目的只是期望接受0-6之间的数字，将形参i定义为枚举
{
    switch(i)
    {
        case 0:
            printf("MonDay!\n");
            break;
        case 1:
            printf("TuesDay!\n");
            break;
        case 2:
            printf("WednesDay!\n");
            break;
        case 3:
            printf("ThursDay!\n");
            break;
        case 4:
            printf("FriDay!\n");
            break;
        case 5:
            printf("SaturDay!\n");
            break;
        case 6:
            printf("Sunday!\n");
            break;
        //最好不要在写default，break
    }
}
void main()
{
    f(FriDay);//虽然Friday本质是5但写成f(5)是错的
}
