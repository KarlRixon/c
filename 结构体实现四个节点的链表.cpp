//�����ĸ����֣����뵥����Ȼ����ʾ���������κ����⣬��׷���ң��һ���ͦ����Ρ�����

#include "stdio.h"
#include "malloc.h"

struct node{ int data; struct node * next;};
struct node * head = ( struct node *) malloc ( sizeof( node));

//ͷ�巨���Ԫ��
void Add(){
	struct node * make =  ( struct node *) malloc ( sizeof( node));
	scanf( "%d", & make->data);
	make ->next = head->next;
	head->next = make;
}

//��ʾ����
void Display(){
	struct node * p = head->next;
	while( p){
	printf( "%d\n", p->data); p = p->next;
	}
}

//������
int main(){
	int i;
	head ->next = NULL;
	for( i = 1; i < 5; i++){
		printf( "\ninput the %dth data:", i);
		Add();
	}
	Display();
	return 0;
}
