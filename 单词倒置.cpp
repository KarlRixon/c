#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
	char t[101];
	cin.getline(t,100);
//	cout<<t;
    char s[11][10];
    int i=0,j=0,k=0;
    while(i<100){
    	if(t[i]=='\0')break;
    	if(t[i]==' '){
    		j++;k=0;i++;continue;
		}
    	s[j][k]=t[i];
    	k++;
    	i++;
	}
	for(int h=j;h>=0;h--){
		for(int l=0;l<10;l++){
			if(s[h][l]=='\0'){
				break;
			}
			cout<<s[h][l];
		}
		cout<<' ';
	}
    return 0;
}
