#include"stdio.h"
#include"string.h"
char s3[100];
char *insert(char *s1,char *s2,int f)
{
int a,i,j;
if(*(s1+f-1)!='\0')
{
for(i=0;i<f-1;i++)
s3[i]=*(s1+i);/*��s1��f֮ǰ���ַ����Ƶ�s3��*/
}
else return s1;
a=strlen(s2);
for(j=0;j<a;j++)/*��s2���ַ����Ƶ�s3��*/
s3[i++]=*(s2+j);
for(j=f;j<strlen(s1);j++)/*��s1ʣ�µĸ��Ƶ�s3��*/
s3[i++]=*(s1+j);
return s3;
}
int main()
{
char s1[40]={'\0'},s2[40]={'\0'};
int f;
printf("please input two strings:\n");
gets(s1);/*����s1*/
getchar();
gets(s2);/*����s2*/
printf("please input an int to cut the string:\n");
scanf("%d",&f);
printf("the new string is:%s\n",insert(s1,s2,f));
return 0;
}
