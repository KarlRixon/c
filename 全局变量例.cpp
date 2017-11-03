#include <stdio.h> 
float   Max,Min;   //习惯将全局变量第一个字母大写
float  average(float  array[], int  n)
{   int i;   float  sum=array[0];
    Max=Min=array[0];
    for(i=1;i<n;i++)
    {   if(array[i]>Max)  Max=array[i];
         else if(array[i]<Min)  Min=array[i];
         sum+=array[i];
    }
    return(sum/n);
}
int main()
{   int i;   float ave,score[10];
    /*Input  */ 
    ave=average(score,10);
    printf("Max=%6.2f\nMin=%6.2f\naverage=%6.2f\n",Max,Min,ave);
     return 0;
}

