#include<stdio.h>
int FUN(int i)
{
	int j;
	for(j=2;j<=i/2;j++) {if(i%j!=0) return 1; else return 0;}
	return 1;
}
int main()
{
	int a,b,i,m;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		if (FUN(i)) {printf("%d\t",i); m++;}
	}
	printf("\n%d numbers in total",m);
}
