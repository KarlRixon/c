/* �ͷ�����ȫ����Ŀռ�*/
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

