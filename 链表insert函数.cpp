/* ��pָ��Ľ�����������ʹ���������� */
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

