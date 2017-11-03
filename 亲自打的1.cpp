#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int num;
	char name[10];
	struct stu *next;
};
struct stu *head=(struct stu*)malloc(sizeof(stu));
stu a={1616,"karl"};
struct stu *creat(int n);
void insert(stu *head,stu *pn,int i);
void delete(stu *head,i);
void display(stu *head);
int main()
{
	struct *head,*pn,*pe;
	int i,n;
	printf("how many students?\n");
	scanf("%d",&n);
	head=creat(n);
	printf("want to add new member y/n?\n");
	if(getchar()=='y')
	{ printf("type the no.\n");
	  scanf("%d",&i);
	  insret(*head,*pn,i);
	  printf("tpye the num and name\n");
	  scanf("%d%s",pn.num,pn.name);}
	printf("display the chart\n");
	display(*head);
	printf("delete a member? y/n");
	if(getchar()='y')
	{printf("which one would you like to delete?  ");
	scanf("%d",i);
    delete(*head,i)
    display(*head);
    return 0;
}
struct stu *creat(int n)
{
	int i;
	struct *pn,*pe,*head;
	struct stu *make=(struct stu*)malloc(sizeof(stu));
//	if(head==NULL) printf("fail to creat a chart");
	while(i<n)
	{
		head->next=make;
		
	 } 
} 
























 
