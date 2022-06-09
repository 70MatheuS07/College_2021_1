#include <stdio.h>
#include <math.h>
int main () {
  int p,i,r;
  

  scanf("%d %d",&p,&i);
  
  if (p==1) {
      printf("RESP:1");
  } else if (i==1) {
      printf("RESP:1");
  } else if (p==i) {
      printf("RESP:%d",p);
  } else if (i%p==0) {
    printf("RESP:%d",p);
  } else {
    r=i%p;
    printf("RESP:%d",r);
  }
 
  return 0;
}