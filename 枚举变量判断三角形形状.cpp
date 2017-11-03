#include <stdio.h>
int main( )
{	enum triangle{scalene, isosceles, equilateral, notriangle};
	enum triangle tri;
	int a, b, c;
	printf("Please input a, b, c:\n");
	scanf("%d%d%d", &a, &b, &c);
	if(a+b<=c||a+c<=b||b+c<=a) tri=notriangle;
	else if(a==b&&b==c) tri=equilateral;
	else if(a==b||b==c||a==c) tri=isosceles; 
	else tri=scalene; 
     switch(tri) 
     {	case scalene:
                  printf("scalene triangle\n"); 
                  break;
	case isosceles:
                  printf("isoceles triangle\n"); 
                  break;
	case equilateral:
                  printf("equilateral triangle\n"); 
                  break; 
	case notriangle: 
                  printf("notriangle\n"); 
                  break; 
     } 
} 

