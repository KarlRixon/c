/* 将p指向的结点插入链表，并使链表保持有序 */
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

