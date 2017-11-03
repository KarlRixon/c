#include<stdio.h> 
int main()
{
char str[20];
int i=0,j,count=0;
printf("请输入要统计的字符以回车结束:\n");
gets(str);
while(str[i++]!='\0')
{
if(str[i]==' ')
{
i++;
while(str[i]==' ')//判断连续空格
{ i++;}
count++;
}
}
printf("单词书为：%d\n",count+1);
}
