#include <stdio.h>
enum color {red, yellow,  blue, white, black, purple};
void print(enum color c)
{	switch(c)
	{        case  red:    printf("red\t\t");     break;
	          case  yellow: printf("yellow\t\t");  break;
	          case  blue:   printf("blue\t\t");    break;
	          case  white:  printf("white\t\t");   break;
	          case  black:  printf("black\t\t");   break;
	          case  purple: printf("purple\t\t");  break;
	}
}
int main( )
{	enum color i,j,k;
	int count=0;
	for(i=red; i<=purple; i=(enum color)((int)i+1))
	   for(j=red; j<=purple; j=(enum color)((int)j+1))
	     for (k=red; k<=purple; k=(enum color)((int)k+1))
		if((i!=j)&&(k!=i)&&(k!=j))
		{	printf("%d\t", ++count);
			print(i);   print(j); 	print(k);
			printf("\n");
		}
	printf("combination: %d\n", count);
           return 0;
}

