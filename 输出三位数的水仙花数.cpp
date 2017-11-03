#include<stdio.h>
int main()
{
	int x,y,z,i;
	for(i=100;i<1000;i++)
	{
		x=i/100;y=(i/10)%10;z=i%10;
		if((x*x*x+y*y*y+z*z*z)==i) printf("%d\t",i);
	}
 } 
