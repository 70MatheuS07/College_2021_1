#include <stdio.h>

int main () {

    int n, m, loop;

    scanf ("%d %d", &n, &m);

    loop = n+1;

    if (n != m) {
        printf ("RESP:");
    
        while ((loop > n) && (loop < m) && (n != m)) {
        
            if (loop%2 == 0) {
                printf ("%d ", loop);
            } 
            loop++;
        }
    
    } else if ((n = m) && (n > 0) && (m > 0)) {
        printf ("RESP:");
    }
    return 0;
}