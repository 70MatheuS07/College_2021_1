#include <stdio.h>

int main () {

    int n, m, ab=1, cd=1, ef=1, loop;
    
    scanf ("%d %d", &n, &m);

    loop = n;
    n = n + 1;
    m = m - 1;

    for (loop; (loop < m) && (n > 1000) && (m < 9999); loop++) {
        
        while (n < m) {
            
            ab = (n/100);
            cd = (n - (ab*100));
            ef = (ab + cd);

            if ((ef * ef) == n) {

                printf ("%d\n", n);
            }

            ab = 1;
            cd = 1;
            ef = 1;

            n++;
        }
    }
    return 0;

}