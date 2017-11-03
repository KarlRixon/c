#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Llist;

LNode *creat_head();/*����һ���ձ�*/
void Creatlist_L(LNode *,int);/*����һ������Ϊn����������*/
void ListInsert_L(LNode *,int,int );/*����һ��Ԫ�� */
int  Listdelete_L(LNode *,int);/*ɾ��һ��Ԫ��*/
void Destroy_L(LNode*);
main()
{
LNode *head,*p; 
int n,m; 
int e,i; 
int b; 
system("cls"); /*VC++:system("cls")*/
head=creat_head();
Creatlist_L(head,n);
for(p=head->next;p!=NULL;) 
{ 
printf("%d ",p->data); 
p=p->next;
} 
printf("\n\t\t================================\n\n");
printf("\t\t================================\n\n");
printf("\t\t choose function \n\n");
printf("\t\t 1: Delete a elem! \n\n");
printf("\t\t 2: Insert a elem! \n\n");
printf("\t\t 3: Destroy the List!\n\n");
printf("\t\t 4: Exit \n\n");
printf("\t\t=================================\n\n");
printf("\t\t=================================\n\n");
printf("Choose your number(1-4):[ ]\b\b");
scanf("%d",&m);
switch(m)
{
case 1:Listdelete_L(head,i);break;
case 2:ListInsert_L(head,i,e);break;
case 3:Destroy_L(head);break;
case 4:exit(0);
} 
}
/*����һ��������*/ 
LNode *creat_head() 
{ 
LNode *p; 
p=(Llist)malloc(sizeof(LNode)); 
p->next=NULL; 
return(p); 
} 

/*����һ������Ϊn����������*/ 
void Creatlist_L(LNode *head,int n) 
{ 
LNode *p,*q; 
int i; 
p=head;
printf("please input the number of the data:n=");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
q=(Llist)malloc(sizeof(LNode));
printf("data%d:",i);scanf("%d",&q->data); /*����Ԫ��ֵ*/
q->next=NULL;
p->next=q;
p =q;
}
} 
/*ɾ��һ��Ԫ��*/ 
int Listdelete_L(LNode *head,int i)
{
LNode *p,*q;
int j=0;
int e;
p=head;
printf("The number of the elem you want to delete:i=");
scanf("%d",&i);
while((p->next)&&(j<i-1))
{
p=p->next;
++j;
}
if(!(p->next)||j>i-1) exit(0);
q=p->next;
p->next=q->next;
e=q->data;
free(q);
for(p=head->next;p!=NULL;) 
{ 
printf("%d ",p->data); 
p=p->next;
}
}
/*����һ��Ԫ��*/ 
void ListInsert_L(LNode *head,int i,int e ) 
{ 
int j=0; 
LNode *p,*s; 
p=head; 
printf("The weizhi you want to insert:i=");
scanf("%d",&i);
printf("The elem you want to insert:e=");
scanf("%d",&e);
while(p&&(j<i-1)) /*Ѱ�ҵ�i-1�����*/
{ 
p=p->next; 
++j; 
} 
if(!p||j>i-1) exit(0); /*iС��1���ߴ��ڱ�+1*/
s=(Llist)malloc(sizeof(LNode));/*�����½��*/ 
s->data=e; /*����L��*/
s->next=p->next; 
p->next=s;
for(p=head->next;p!=NULL;) 
{ 
printf("%d ",p->data); 
p=p->next; 
} 
}
void Destroy_L(LNode *head)
{
 
 LNode *tmp; 
 tmp = head; 
 while(tmp!=NULL) 
 { 
  head = tmp->next; 
  free(tmp); 
  tmp = head; 
} 
} 
