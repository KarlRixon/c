#include "stdio.h"
#include "stdlib.h"
#include "time.h"
typedef struct Node
{
int key;
Node * next;
}Node;	//定义结构
int main()
{
int *a,n,i;
Node *L0,*p;
scanf("%d",&n);//输入链表长度

a=(int*)malloc(sizeof(int)*n);//给数组a动态分配n个空间
L0=(Node*)malloc(sizeof(Node));
L0->next=NULL; //建立头结点
srand((unsigned)time( NULL ) ); //与rand()函数一起使用
for(i=0;i<n;i++)
{
a[i]=rand()%100; //产生100以内的随机数，也可以自己输入
}
for(i=0;i<n;i++)
{
p=(Node*)malloc(sizeof(Node));
p->key=a[i]; //分配一个结点空间，并赋值
p->next=L0->next; 
L0->next=p;	//连接单链表，这里是精髓
}

while(L0->next)
{
L0=L0->next;
printf("%d ",L0->key); //遍历单链表
}
return 0;
}

