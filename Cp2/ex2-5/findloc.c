/* K&R exercise 2-5. I've utilized an array to store the char values, so my algorithm becomes O(m + n) instead of O(n^2). */

#include <stdio.h>

int any(unsigned char *s1, unsigned char *s2);

int main(void)
{
    unsigned char *s1 = "abcdei";
    unsigned char *s2 = "joi";

    printf("Found on %d\n", any(s1, s2)); 
    return 0;
}

int any(unsigned char *s1, unsigned char *s2)
{
    int chars[256] = {0};

    for (int i = 0; s2[i] != '\0'; i++)
        chars[s2[i]] = 1;

    for (int i = 0; s1[i] != '\0'; i++)
        if (chars[s1[i]])
            return i;

    return -1;
}

