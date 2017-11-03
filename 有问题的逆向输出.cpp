#include<stdio.h>
int reverse(int a[9],int i)
{
	if(a[i+1]!='\0')
	reverse(a,i++);
	printf("%d",a[i]);
}
int main()
{
	int i,a[9]; 
	for(i=0;i<9;i++)
	{
		scanf("%d",a[i]);
	}
	reverse(a,i);
 }
