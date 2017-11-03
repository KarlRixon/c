#include<stdio.h> 
#include<stdlib.h>
struct node
{	
	int data;          /* ���� */
	struct node *next;  /* ָ����һ����ָ�� */
};
struct node *delete( struct node *head,  int num )
{
	struct node *p1, *p2;
	if( head == NULL)      
		 /* ��������� ������Ϊ�� */
	{ 	
		printf("List is null.\n");
		return(NULL);
	}
    p1=head; /* ѭ�����Ҵ�ɾ����� */
    while(p1->data != num && p1->next !=NULL )
    { 	p2=p1;       
	p1=p1->next; /* p2ָ��Ľ����p1ָ��Ľ��֮ǰ */
    }
    if(p1->data == num)  /* �ҵ���ɾ����㣬��p1ָ�� */
   {  	if(p1==head)  /* ��������� */
	     head=p1->next; /* ���ҵ��Ľ�����׽�� */
	else   /* ��������� */
	     p2->next = p1->next;  /* �ҵ��Ľ�㲻���׽�� */
	printf("The first node %d is deleted.\n", p1->data);
	free(p1);
    }
    else  /*���������δ�ҵ���ɾ����� */
    	printf("Node %d is not found.\n", num);
    return(head); /* ���������ͷָ�� */
}

int main()
{	 } 

