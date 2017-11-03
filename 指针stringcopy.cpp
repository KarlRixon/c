#include <stdio.h>
void copy_string(char *from,char  *to)
{  for(;*from!='\0';from++,to++)
       *to=*from;
    *to='\0';
}
int main()
{  char a[]="I am a teacher.";
   char b[]="You are a student.";
   printf("string_a=%s\nstring_b=%s\n",a,b);
   copy_string(a,b);
   printf("\nstring_a=%s\nstring_b=%s\n",a,b);
   return 0;
}

