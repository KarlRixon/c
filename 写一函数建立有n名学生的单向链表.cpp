#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
struct student
{  long num;
   float score;
   struct student *next;
};
int n;		/*n为结点个数*/
struct student *creat(void)
{   struct student *head;
     struct student *p1,*p2;
     n=0;
     head=NULL; 	/* 空链表 */
     p1= (struct student*)malloc(LEN); 
				/* p1总是指向新开辟结点 */
     scanf("%ld,%f",&p1->num,&p1->score);
     while(p1->num!=0)
     {  n=n+1;
         if(n==1) 	head=p1;   	  /* ①首结点 */
	     else 		p2->next=p1; /* ②中间结点 */
	     p2=p1;
	     p1=(struct student*)malloc(LEN);
         scanf("%ld,%f",&p1->num,&p1->score);
    }
    if(head != NULL) p2->next=NULL; /* ③尾结点*/
    return(head);
}
int main(){}
