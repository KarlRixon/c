#include "stdio.h"
#include "stdlib.h"
#include "time.h"
typedef struct Node
{
int key;
Node * next;
}Node;	//����ṹ
int main()
{
int *a,n,i;
Node *L0,*p;
scanf("%d",&n);//����������

a=(int*)malloc(sizeof(int)*n);//������a��̬����n���ռ�
L0=(Node*)malloc(sizeof(Node));
L0->next=NULL; //����ͷ���
srand((unsigned)time( NULL ) ); //��rand()����һ��ʹ��
for(i=0;i<n;i++)
{
a[i]=rand()%100; //����100���ڵ��������Ҳ�����Լ�����
}
for(i=0;i<n;i++)
{
p=(Node*)malloc(sizeof(Node));
p->key=a[i]; //����һ�����ռ䣬����ֵ
p->next=L0->next; 
L0->next=p;	//���ӵ����������Ǿ���
}

while(L0->next)
{
L0=L0->next;
printf("%d ",L0->key); //����������
}
return 0;
}

