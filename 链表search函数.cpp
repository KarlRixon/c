#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;          /* ���� */
	struct node *next;  /* ָ����һ����ָ�� */
};
struct node * search( struct node *head, int x ) 
{ 	struct node *p; 
	p=head;
	while( p!=NULL ) 
	{
		if(p->data == x)   return p;   
			    /* ���ҵ����򷵻ظý��ָ�� */
		p = p->next;
	}
	return NULL; /* ���Ҳ������򷵻ؿ�ָ�� */
}	
int main(){} 
