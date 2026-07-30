#include <stdio.h>

/* atoi: converts s to integer */

int atoi(char s[])
{
    int i, n;

    n = 0;
    for (int i = 0; s[i] > '0' && s[i] <= '9'; i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

