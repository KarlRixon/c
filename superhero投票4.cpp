#include<stdio.h>
#include<stdlib.h>
struct man
{
	int num;
	char name[20];
 };
struct man hero[3]={{0,"IRON MAN"},{0,"Captian America"},{0,"thor"}};
 int main()
 {
 	int i;
 	printf("1/2/3?\n");
 	int n;
 	for(i=1;i<=10;i++)
 	{
 		scanf("%d",&n);
 		switch(n)
 		{case 1: hero[0].num++;break; 
		case 2: hero[1].num++;break;
		case 3: hero[2].num++;break;
		default:printf("please enter 1/2/3\n"); }
	 }
	for(i=1;i<=3;i++)
	printf("NO.%d:%d\t",i,hero[i-1].num);
 }
