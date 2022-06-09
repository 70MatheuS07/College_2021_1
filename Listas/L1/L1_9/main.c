#include <stdio.h>

int main () {
  char letra;
  scanf("%c",&letra);

  if (letra>=97 && letra<=122) {
    letra = letra - 32;
    printf("%c(%d)",letra,letra);
  }else if (letra>=65 && letra<=90) {
    printf("A letra deve ser minuscula!");
  }else if ("%d") {
    printf("Nao e letra!");
  }
return 0;
}