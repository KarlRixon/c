#include <stdio.h>
#include<stdlib.h>
struct node
{	
	int data;          /* ���� */
	struct node *next;  /* ָ����һ����ָ�� */
};
void print( struct node *head )
{	struct node *p;    
	p=head;
	printf("Output list: ");
	while( p!=NULL ) 
	{	
		printf("%d\t", p->data); 
		p=p->next;
		    /*p������ǰ��㣬ָ����һ���*/
	}
	printf("\n");
}
int main(){}
