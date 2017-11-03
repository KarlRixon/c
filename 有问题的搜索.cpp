#include<stdio.h>
int search(int *list,int n,int x);
int main()
{  int n,a[5],x,i,rex;
   scanf("%d",&n);
   for(i<n;i++;)
   {  scanf("%d",&a[i]);}
   scanf("%d",&x);
   rex=search(a,n,x);
   printf("%d",rex);
   return 0;
   }
int search(int *list,int n,int x)
{  int i,*p=NULL;
   p=list;
   for(i<n;i++;)
   {if(*p==x) {return i;break;}
    p++;} 
    return -1;}
   
