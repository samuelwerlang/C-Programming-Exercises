#include <stdio.h>

int htoi(char s[]); /* htoi: convert s to int */

int main(void)
{
    char s[] = "0x1A3F";
    printf("%d\n", htoi(s));
    return 0;
}

int htoi(char s[])
{
    int i, k, n;
    n = k = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) 
            k = 2;
    
    for (i = k; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); i++) {

            if (s[i] >= '0' && s[i] <= '9')
                n = n * 16 + (s[i] - '0');
            else if (s[i] >= 'a' && s[i] <= 'f')
                n = n * 16 + (s[i] - 'a' + 10);
            else
                n = n * 16 + (s[i] - 'A' + 10);
    }
    return n;
}
