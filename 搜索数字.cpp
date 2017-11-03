#include <stdio.h>
int search(int list[],int n,int x);
int main()
{
int i,x,a[10],res;
for(i=0;i<10;i++)
scanf("%d",&a[i]);
scanf("%d",&x);
res=search(a,10,x);
printf("%d\n",res);
}
int search(int list[],int n,int x)
{
int i=0,*p;
p=list;
while(i<n)
{
if(*p==x)
{
return(i+1);
break;
}
p++;
i++;
if(i==10) return(-1);
}
}
