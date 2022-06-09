#include <stdio.h>

int main () {
  int n;
  
  scanf("%d",&n);
  if(n==1) {
    printf("Jan.");
  } else if(n==2) {
    printf("Fev.");
  } else if(n==3) {
    printf("Mar.");
  } else if(n==4) {
    printf("Abr.");
  } else if(n==5) {
    printf("Mai.");
  } else if(n==6) {
    printf("Jun.");
  } else if(n==7) {
    printf("Jul.");
  } else if(n==8) {
    printf("Ago.");
  } else if(n==9) {
    printf("Set.");
  } else if(n==10) {
    printf("Out.");
  } else if(n==11) {
    printf("Nov.");
  } else if(n==12) {
    printf("Dez.");
  } else {
    printf("Invalido.");
  }
    
  return 0;
}