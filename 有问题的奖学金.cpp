#include<stdio.h>
int main()
{
	int i,a[6][5],j,k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{ for(j=0;j<3;j++) 
	  scanf("%d",a[i][j]);a[i][4]=i+1;
	}
	for(i=0;i<k;i++)
	{ a[i][3]=a[i][1]+a[i][2]+a[i][0];}
	for(i=0;i<(k-1);i++)    //Ã°ÅÝÅÅÐò 
	{
		if(a[i][3]==a[i+1][3]&&a[i][0]>a[i+1][0])
		{  int b[5];  b=a[i+1];  a[i+1][]=a[i][];  a[i][]=b;
		}
		else if(a[i][3]>a[i+1][3])
		{  int b[1][5];  b=a[i+1][];  a[i+1][]=a[i][];  a[i][]=b;
		}
	}
	for(i=0;i<4;i++)
	{   for(j=0;j=3;j--)
	    printf("%d\t%d\n",a[i][j]);
	}
	return 0;
}
