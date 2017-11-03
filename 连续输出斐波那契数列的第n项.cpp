#include<stdio.h>
int main()
{
    int n,num=0,num0=1,num1=1,c=1,i;
	while(1)
	{
	scanf("%d",&n);
	if(n==1||n==2) num=1;
	for(i=1;i<=(n-2);i++)
	{
		num=num0+num1;
		num0=num1;num1=num;
	}  
	printf("%d\n",num);
	printf("one more time? 1/0 ");
	scanf("%d",&c);
	if(c!=0) num=0;num0=1;num1=1;
	if(c==0) break;
    }
    return 0;
} 
