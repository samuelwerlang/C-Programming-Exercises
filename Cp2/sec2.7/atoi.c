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
i

/* lower: convert char c to lower case | ASCII only */

int lower(int c)
{
   if (c >= 'A' && c <= 'Z')
      return c + 'a' - 'A';
   return c;
}
