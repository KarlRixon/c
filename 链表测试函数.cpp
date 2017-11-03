#include <stdio.h>
#include <stdlib.h>
struct node
{	
	int data;          /* 数据 */
	struct node *next;  /* 指向下一结点的指针 */
};
/*省略create函数的定义;
	 print函数的定义;
	 search函数的定义;
	 delete函数的定义;
	 free_list函数的定义;
	 insert函数的定义;
	 create_sort函数的定义;*/
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

