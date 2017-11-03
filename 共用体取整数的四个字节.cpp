/*分别取出一个整数的四个字节*/
#include <stdio.h> 
int main( )
{	int k;
	union 
	{	int i;
		char c[4];
	}a;
	printf("Please input an integer:\n");
	scanf("%d", &a.i);
	printf("four bytes:");
	for(k=3; k>=0; k--)
		printf("%d\t", (int)a.c[k]); 	printf("\n");
          return 0;
} 
