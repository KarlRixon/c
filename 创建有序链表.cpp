/* 创建升序链表。返回值: 链表的首指针 */
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

