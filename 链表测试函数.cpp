#include <stdio.h>
#include <stdlib.h>
struct node
{	
	int data;          /* ���� */
	struct node *next;  /* ָ����һ����ָ�� */
};
/*ʡ��create�����Ķ���;
	 print�����Ķ���;
	 search�����Ķ���;
	 delete�����Ķ���;
	 free_list�����Ķ���;
	 insert�����Ķ���;
	 create_sort�����Ķ���;*/
int main( )
{	struct node *head;    int num;
	head=create( );              /* ����һ���������� */
	print(head);                 /* ������� */
	printf("Please input a node number to be deleted: ");
	scanf("%d", &num);
	head=delete(head, num); /* ɾ��һ����� */
	print(head);                
	printf("Please input a node number to be searched: ");
	scanf("%d", &num);
	if(search(head, num)!=NULL)        /* ����һ����� */
		printf("It is in the list.\n");
	else 
		printf("It is not in the list.\n");
	free_list(head);  
	head=create_sort( );      /* ����һ���������� */
	print(head);  
	free_list(head);          /* �ͷ���������ռ� */
	return 0;
}

