#include <stdio.h>
#include<stdlib.h>
struct node
{	
	int data;          /* 数据 */
	struct node *next;  /* 指向下一结点的指针 */
};
void print( struct node *head )
{	struct node *p;    
	p=head;
	printf("Output list: ");
	while( p!=NULL ) 
	{	
		printf("%d\t", p->data); 
		p=p->next;
		    /*p跳过当前结点，指向下一结点*/
	}
	printf("\n");
}
int main(){}
