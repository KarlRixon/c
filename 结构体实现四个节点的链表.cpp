//输入四个数字，存入单链表，然后显示出来。有任何问题，就追问我，我还是挺厚道滴。。。

#include "stdio.h"
#include "malloc.h"

struct node{ int data; struct node * next;};
struct node * head = ( struct node *) malloc ( sizeof( node));

//头插法添加元素
void Add(){
	struct node * make =  ( struct node *) malloc ( sizeof( node));
	scanf( "%d", & make->data);
	make ->next = head->next;
	head->next = make;
}

//显示所有
void Display(){
	struct node * p = head->next;
	while( p){
	printf( "%d\n", p->data); p = p->next;
	}
}

//主函数
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
