#include <stdio.h>

void delchar(char *s,char c)
{
	char *p;

	for(p=s;*s;s++)
		if(*s!=c)
			*p++=*s;
	*p='\0';
}

int main()
{
	char c,s[100];

	printf("�����ַ���:");
	gets(s);
	printf("����Ҫɾ�����ַ�:");
	scanf("%c",&c);
	delchar(s,c);
	printf("%s\n",s);
}
