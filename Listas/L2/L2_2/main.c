#include <stdio.h>

int main () {

    int n, m, loop;

    scanf ("%d %d", &n, &m);

    loop = n+1;

    while ((loop > n) && (loop < m)) {

        if ((loop%3==0) || (loop%4==0) || (loop%7==0)) {
        printf ("%d ", loop);
        }
        loop++;
    }

    return 0;
}