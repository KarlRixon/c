#include<stdio.h>
#include<math.h>
int GONGYUE(int a,int b)
{
  int i;if(a<b) i=a/2;else i=b/2;
  while(i>=1)
  {  if(a%i==0&&b%i==0) break; else i--;}  return (i);}
int GONGYIN(int a,int b)
{
  int i;if(a<b) i=b;else i=a;
  while(i<=a*b)
  {  if(i%a==0&&i%b==0) break; else i++;}  return(i);}
int main()
{
  int a,b,yue,yin;
  scanf("%d%d",&a,&b);
  yue=GONGYUE(a,b);
  yin=GONGYIN(a,b);
  printf("最小公倍数是：%d\n最大公约数是：%d",yin,yue);
  return 0;
  }

