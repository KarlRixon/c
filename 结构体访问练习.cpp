#include <stdio.h>
#include <string.h>
int main()
{   struct student
    {       long int num;
	 char name[20];
	 char sex;
	 float score;
    }stu_1,*p=&stu_1;
    stu_1.num=89101; 	//ֱ�ӷ��ʳ�Ա
    strcpy(stu_1.name,"Li Lin"); 
    p->sex='M'; 		//��ӷ��ʳ�Ա
    p->score=89.5; 		
    printf("\nNo:%ld\nname:%s\nsex:%c\nscore:%f\n",
	       (*p).num, p->name, stu_1.sex, p->score);
    return 0;
}

