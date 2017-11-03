#include <stdio.h>
#include <stdlib.h>

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

void free_list( struct node *head ) 
{
	struct node *p;		//p指向待删除结点
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
   /* 如果插入前（原始链表）为空链表，对应情况① */
	if(head==NULL) 	{	
		head=p;
		p->next=NULL;
		return(head); /* 返回链表的头指针 */
	}
   p2=p1=head;                
     /* 寻找待插入位置 */
    while( (p->data) > (p1->data ) && p1->next!=NULL ) 
    {p2=p1; 
      p1 = p1->next; /* p2指向的结点在p1指向的结点之前 */
    }
    if( (p->data) <= (p1->data) ) /* 插在p1之前 */
    {p->next = p1;
      if(head==p1)   head=p; /* 插在链表首部，情况② */
      else 	          p2->next = p;   /* 插在链表中间，③ */
    }
    else /* 插在链表尾结点之后，情况④ */
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
	head=create( );              /* 建立一个无序链表 */
	print(head);                 /* 输出链表 */
	printf("Please input a node number to be deleted: ");
	scanf("%d", &num);
	head=delete(head, num); /* 删除一个结点 */
	print(head);                
	printf("Please input a node number to be searched: ");
	scanf("%d", &num);
	if(search(head, num)!=NULL)        /* 查找一个结点 */
		printf("It is in the list.\n");
	else 
		printf("It is not in the list.\n");
	free_list(head);  
	head=create_sort( );      /* 建立一个有序链表 */
	print(head);  
	free_list(head);          /* 释放有序链表空间 */
	return 0;
}

