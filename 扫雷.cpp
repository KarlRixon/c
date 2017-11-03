#include<stdio.h>   
  
int main(void)  
{  
    char a[101][101];  
    int sum[100][100]={0};  
    int j,i,n,m;  
    scanf("%d%d",&n,&m);  
    for(i=0;i<n;i++)  
    {  
            scanf("%s",a[i]);getchar();  
    }  
  
         
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            if(a[i][j]=='*')  
            {sum[i][j]=-1;  continue;  
            }   
            if(a[i-1][j-1]=='*')  
                 sum[i][j]++;  
            if(a[i-1][j]=='*')  
                 sum[i][j]++;  
            if(a[i-1][j+1]=='*')  
                 sum[i][j]++;  
            if(a[i][j-1]=='*')  
                 sum[i][j]++;  
            if(a[i][j+1]=='*')  
                 sum[i][j]++;  
            if(a[i+1][j-1]=='*')  
                 sum[i][j]++;  
            if(a[i+1][j]=='*')  
                 sum[i][j]++;  
            if(a[i+1][j+1]=='*')  
                 sum[i][j]++;                             
        }  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            if(sum[i][j]!=-1)  
                printf("%d",sum[i][j]);  
            else putchar('*');  
        }  
        putchar('\n');  
    }  
    return 0;  
}  


