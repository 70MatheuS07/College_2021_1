#include <stdio.h>

int main () {
char T1;
float X,R;
scanf("%f ""%c",&X,&T1);

if ((T1=='f') || (T1=='F')) {
  R=(X-32)/1.8;
  T1='C';
  printf("%.2f (%c)",R,T1);
}
else if ((T1=='c') || (T1=='C')) {
  R=(X*1.8)+32;
  T1='F';
  printf("%.2f (%c)",R,T1);
}
return 0;
}