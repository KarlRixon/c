#include<stdio.h>
int main()
{
	int i,j,m,n;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",i*j);
		}
	printf("\n"); 
	}
	return 0;
 } 
