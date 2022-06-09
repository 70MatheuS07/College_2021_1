#include <stdio.h>

int main () {
	int a, b, den=1, i=0, mdc=0, mmc=0, limMDC, limMMC;

	scanf ("%d %d", &a, &b);

	//Acha limites da busca
	if (a < b) {
		limMDC = b;
		limMMC = a;
	} else {
		limMDC = a;
		limMMC = b;
	}
	
	//MDC
	for (den=1; den <= limMDC; den++) {  
		if ((a%den==0) && (b%den==0)) { 
			mdc = den;
		}
	}
	
	//MMC
	i = limMMC;
	while(1) {
		if(!(i%a) && !(i%b)) {     
			mmc = i;
			break;
		}
		i++;                      
	}

	printf("%d %d ", mdc, mmc);

	return 0;
}
