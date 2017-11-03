#include<stdio.h>
#include<stdlib.h>
typedef struct
{
long id; 
char name[20]; 
float salary; 
struct stud *next ;
}EMP;
EMP *InsertNode(EMP *head)
{
EMP *p,*p1,*p2;
p=(EMP*)malloc(sizeof(EMP));
scanf("%ld %s %f",&p->id,&p->name,&p->salary);
p1=p2=head;
while((p->salary)>(p1->salary)&&(p1->next)!=NULL)
{
p2=p1;
p1=p1->next;
}
if((p->salary)<=(p->salary))
{
p->next=p1;
if(p1==head)
head=p;
else
p2->next=p;
}
else
{
p1->next=p;
p->next=NULL;
}
return(head);
}
