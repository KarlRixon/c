#include<stdio.h> 
int main()
{
char str[20];
int i=0,j,count=0;
printf("������Ҫͳ�Ƶ��ַ��Իس�����:\n");
gets(str);
while(str[i++]!='\0')
{
if(str[i]==' ')
{
i++;
while(str[i]==' ')//�ж������ո�
{ i++;}
count++;
}
}
printf("������Ϊ��%d\n",count+1);
}
