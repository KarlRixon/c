#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Llist;

LNode *creat_head();/*创建一个空表*/
void Creatlist_L(LNode *,int);/*创建一个长度为n的线性链表*/
void ListInsert_L(LNode *,int,int );/*插入一个元素 */
int  Listdelete_L(LNode *,int);/*删除一个元素*/
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
/*创建一个空链表*/ 
LNode *creat_head() 
{ 
LNode *p; 
p=(Llist)malloc(sizeof(LNode)); 
p->next=NULL; 
return(p); 
} 

/*创建一个长度为n的线性链表*/ 
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
printf("data%d:",i);scanf("%d",&q->data); /*输入元素值*/
q->next=NULL;
p->next=q;
p =q;
}
} 
/*删除一个元素*/ 
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
/*插入一个元素*/ 
void ListInsert_L(LNode *head,int i,int e ) 
{ 
int j=0; 
LNode *p,*s; 
p=head; 
printf("The weizhi you want to insert:i=");
scanf("%d",&i);
printf("The elem you want to insert:e=");
scanf("%d",&e);
while(p&&(j<i-1)) /*寻找第i-1个结点*/
{ 
p=p->next; 
++j; 
} 
if(!p||j>i-1) exit(0); /*i小于1或者大于表长+1*/
s=(Llist)malloc(sizeof(LNode));/*生成新结点*/ 
s->data=e; /*插入L中*/
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
