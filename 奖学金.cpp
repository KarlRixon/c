#include<stdio.h>
#include<stdlib.h>


typedef struct Student{

    int snum;
    char score[10];
    int sum;
}Student;
int main(){
    int n;
    scanf("%d",&n);
    Student a[128];   
    int i,j;
    for(i=0;i<n;i++){
        a[i].snum = i+1;
        a[i].sum = 0;
        for(j=0;j<3;j++){
            scanf("%d",&a[i].score[j]);
            a[i].sum += a[i].score[j];
        }
    }
    Student tmp;
    for(j=n-1;j>0;j--){
        for(i=0;i<j;i++){
            if(a[i].sum < a[i+1].sum){
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;  
            }
            else if(a[i].sum==a[i+1].sum){
                if(a[i].score[0] < a[i+1].score[0]){
                    tmp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = tmp; 
                }    
            }
        }
    }
    for(i=0;i<5;i++){
        printf("%d %d\n",a[i].snum,a[i].sum);
    }
    system("pause");
    return 0;
}
