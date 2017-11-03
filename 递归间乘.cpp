#include<stdio.h>
int fac(int n)
{
	float f;
	if(n==0||n==1)  f=1;
	else f=fac(n-1)*n;
	return f;
 } 
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fac(n));
	return 0;
}
