#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
struct student
{  long num;
   float score;
   struct student *next;
};
int n;		/*nΪ������*/
struct student *creat(void)
{   struct student *head;
     struct student *p1,*p2;
     n=0;
     head=NULL; 	/* ������ */
     p1= (struct student*)malloc(LEN); 
				/* p1����ָ���¿��ٽ�� */
     scanf("%ld,%f",&p1->num,&p1->score);
     while(p1->num!=0)
     {  n=n+1;
         if(n==1) 	head=p1;   	  /* ���׽�� */
	     else 		p2->next=p1; /* ���м��� */
	     p2=p1;
	     p1=(struct student*)malloc(LEN);
         scanf("%ld,%f",&p1->num,&p1->score);
    }
    if(head != NULL) p2->next=NULL; /* ��β���*/
    return(head);
}
int main(){}
