#include <stdio.h> 
#include <math.h>
float f(float x)
{ float y;
  y=((x-5.0)*x+16.0)*x-80.0;
  return(y);
}
float xpoint(float x1,float x2)
{ float y;
  y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
  return(y);
}
float root(float x1,float x2)
{ float x,y,y1;
  y1=f(x1);
  do
  { x=xpoint(x1,x2);
    y=f(x);
    if(y*y1>0)                     /*ͬ��*/
    { y1=y; x1=x; }
    else  x2=x;                    /*���*/
  } while(fabs(y)>=0.0001);
  return(x);
}
int main()
{ float x1,x2,f1,f2,x;
  do
  { printf("\nInput x1,x2:\n");
    scanf("%f%f",&x1,&x2);
    f1=f(x1);
    f2=f(x2);
  } while(f1*f2>=0);
  x=root(x1,x2);
  printf("A root of equation is %8.4f",x);
   return 0;
}
