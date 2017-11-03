#include<stdio.h> 
#include<stdlib.h>
struct node
{	
	int data;          /* 数据 */
	struct node *next;  /* 指向下一结点的指针 */
};
struct node *delete( struct node *head,  int num )
{
	struct node *p1, *p2;
	if( head == NULL)      
		 /* 处理情况① ，链表为空 */
	{ 	
		printf("List is null.\n");
		return(NULL);
	}
    p1=head; /* 循环查找待删除结点 */
    while(p1->data != num && p1->next !=NULL )
    { 	p2=p1;       
	p1=p1->next; /* p2指向的结点在p1指向的结点之前 */
    }
    if(p1->data == num)  /* 找到待删除结点，由p1指向 */
   {  	if(p1==head)  /* 处理情况② */
	     head=p1->next; /* 若找到的结点是首结点 */
	else   /* 处理情况③ */
	     p2->next = p1->next;  /* 找到的结点不是首结点 */
	printf("The first node %d is deleted.\n", p1->data);
	free(p1);
    }
    else  /*处理情况④未找到待删除结点 */
    	printf("Node %d is not found.\n", num);
    return(head); /* 返回链表的头指针 */
}

int main()
{	 } 

