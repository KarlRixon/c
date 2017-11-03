#include<stdio.h>
int main()
{
	char c;int num=0;
	c=getchar();
	while(c!='\n')
	{
		if(c==' ')
		{
			num++;
		}
	c=getchar();
	}
	printf("%d",num);
	return 0;
}
