#include<stdio.h>
#include<string.h>
  char s3[150];
int insert(char *s1,char *s2,int f);
int main()
{
	char s1[100];char s2[100];int f;
	printf("Insert s1:\n");
	gets(s1);
	printf("Insert s2:\n");
	gets(s2);
	printf("Insert position number:\n");
	scanf("%d",&f);
	printf("The result is:\n%s",insert(s1,s2,f));
	return 0;
}
int insert(char *s1,char *s2,int f)
{
	int i,j,k;
	for(i=0;i<=f-1;i++)
	{   s3[i]=*(s1+i);   //复制f前面部分 
	 }
	k=strlen(s2);
	for(j=0;j<=k-1;j++)
	{   s3[i]=*(s2+j);i++;  //复制s2 
	 } 
	for(j=f;j<strlen(s1);j++)
	{   s3[i]=*(s1+j);i++;  //复制后半部分 
	 }
	 return *s3;
}
