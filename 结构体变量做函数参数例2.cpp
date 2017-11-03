#include <stdio.h>
struct data
{   int a, b, c; };
int main()
{   void func(struct data  *parm);
    struct data arg;
    arg.a=27;   arg.b=3;    arg.c=arg.a+arg.b;
    printf("arg.a=%d arg.b=%d arg.c=%d\n",arg.a,arg.b,arg.c);
    printf("Call Func()....\n");
    func(&arg);
    printf("arg.a=%d arg.b=%d arg.c=%d\n",arg.a,arg.b,arg.c);
    return 0;
}
void func(struct data  *parm)
{   printf("parm->a=%d parm->b=%d parm->c=%d\n", 
		parm->a,parm->b,parm->c);
    printf("Process...\n");
    parm->a=18;     parm->b=5;    parm->c=parm->a*parm->b;
    printf("parm->a=%d parm->b=%d parm->c=%d\n", 
		parm->a,parm->b,parm->c);
    printf("Return...\n");
}

