#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;          /* 数据 */
	struct node *next;  /* 指向下一结点的指针 */
};
struct node * search( struct node *head, int x ) 
{ 	struct node *p; 
	p=head;
	while( p!=NULL ) 
	{
		if(p->data == x)   return p;   
			    /* 若找到，则返回该结点指针 */
		p = p->next;
	}
	return NULL; /* 若找不到，则返回空指针 */
}	
int main(){} 
