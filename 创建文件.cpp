#include <stdio.h>  //ex13_4_1.c
#include<stdlib.h>
int main()
{  FILE *fp;
    char ch,*filename="out.txt";
    if((fp=fopen(filename,"w"))==NULL)
    {   	printf("cannot open file\n");
	exit(0);	
    }
    printf("Please input string:");
    while((ch=getchar())!='#')
    {    
          putchar(ch);
    }
    fclose(fp);
    return 0;
}

