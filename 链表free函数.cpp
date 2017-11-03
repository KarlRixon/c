/* 释放链表全体结点的空间*/
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

