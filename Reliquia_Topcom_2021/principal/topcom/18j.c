#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    float pontosX, pontosY, cestasX=0, cestasY=0;
    float soma1=0, soma2=0;
    
    for(i=0;i<30;i++){
        soma1 += a*2;
        soma2 += c*2;
    }
    for(i=0;i<30;i++){
        
        if(i<25)soma1 += b*2;
        if(i<22)soma2 += d*2;
        
    }
    if(a!=0&&b!=0){
        
        soma1 = soma1 -(cestasX*(10.0/30)) +(((10.0/60)*cestasX)*3.0);
    }
    if(c!=0&&d!=0){
        
        soma2 = soma2 -(cestasY*(16.0/30)) +(((16.0/60)*cestasY)*3.0);
    }
    pontosX = soma1;
    pontosY = soma2;

    if (pontosX == pontosY){
        printf("Empate %.0f-%.0f", pontosX, pontosY);
    }
    else{
        if (pontosX>pontosY){
            printf("X Venceu %.0f-%.0f", pontosX, pontosY-((16.0/60)*cestasY)*3.0);
        }
        else printf("Y Venceu %.0f-%.0f", pontosX-((10.0/60)*cestasX)*3.0, pontosY);
    }

}
