#include<stdio.h>
#include<math.h>
int main()
{
   int cnt,m,n,i,j;
   scanf("%d %d",&m,&n);
   for(i=m;i<=n;i++)
   {  for(j=2;j<=sqrt(n);j++)
         {  if(i%j!=0)  { return 1;cnt++;}
            return 0; }
   }
   printf("there are %d numbers.\n",cnt);
   return 0;
   }
