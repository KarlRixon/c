#include<stdio.h>
int delchar(char *s,char c)
{
	char *p;int i;
	for(p=s;*s;s++)
		if(*s!=c)  *p++=*s;  *p='\0';
 } 
int main()
{
	char s[100],c;
	gets(s);scanf("%c",&c);
	delchar(s,c);
	printf("%s\n",s);
	return 0;
}
