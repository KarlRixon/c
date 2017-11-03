#include<stdio.h>
int fun(int n);
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",fun(x));
	return 0;
}
int fun(int n){
	int d,e=1,m=0;
	while(n!=0){
		d=n%10;
		if(d%2==1){
			m=d*e+m;
			e=e*10;
		}
		n=n/10;
	}
	return m;
}
