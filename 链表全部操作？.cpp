#include <stdio.h>
#include <stdlib.h>

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

void free_list( struct node *head ) 
{
	struct node *p;		//pָ���ɾ�����
	while( head!=NULL)
	{	
		p=head;
		head=p->next;
		free(p);
	}
}

struct node *insert(struct node *head, struct node *p) 
{       
	struct node *p1, *p2;
   /* �������ǰ��ԭʼ����Ϊ��������Ӧ����� */
	if(head==NULL) 	{	
		head=p;
		p->next=NULL;
		return(head); /* ���������ͷָ�� */
	}
   p2=p1=head;                
     /* Ѱ�Ҵ�����λ�� */
    while( (p->data) > (p1->data ) && p1->next!=NULL ) 
    {p2=p1; 
      p1 = p1->next; /* p2ָ��Ľ����p1ָ��Ľ��֮ǰ */
    }
    if( (p->data) <= (p1->data) ) /* ����p1֮ǰ */
    {p->next = p1;
      if(head==p1)   head=p; /* ���������ײ�������� */
      else 	          p2->next = p;   /* ���������м䣬�� */
    }
    else /* ��������β���֮������� */
    {p1->next = p;
      p->next = NULL;
    }
    return(head);
}

struct node  *create_sort( )
{	struct node  *p, *head=NULL;
	int a;
	printf("Create an increasing list...\n");
	printf("Please input a number(if(-1) exit): ");
	scanf("%d", &a);
	while( a!=-1 )
	{	p = (struct node *) malloc(sizeof(struct node)) ;
		p->data = a;
		head = insert(head, p);
		printf("Please input a number(if(-1) exit): ");
		scanf("%d", &a);
	}
	return(head);
}

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

