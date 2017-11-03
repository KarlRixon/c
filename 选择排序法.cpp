#include <stdio.h>
void sort( int array[], int n)
{ int i,j,k,t;
  for(i=0;i<n-1;i++)
  { k=i;
    for(j=i+1;j<n;j++)
        if(array[j]<array[k])  k=j;
    if(k!=i)
    { t=array[i]; 
      array[i]=array[k];
      array[k]=t;
    }
  }
}
int main()
{ int a[10],i;
  for(i=0;i<10;i++)
     scanf("%d",&a[i]);
  sort(a,10);
  for(i=0;i<10;i++)  printf("%5d",a[i]);
  printf("\n");
  return 0;
}

