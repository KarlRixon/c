#include<stdio.h>
int main()
{
	int a[5][5],sum,i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<5;i++)
	{for(j=0;j<5;j++)
	printf("%d\t",a[i][j]);printf("\n") ;}
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	{if((i==1||i==3)&&(j==2||j==4)) sum+=a[i][j];}
		printf("\n%d",sum);
}
