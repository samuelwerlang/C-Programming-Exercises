#include <stdio.h>

void left_shift(char s1[], int pos) 
{   
    int i;
    i = pos;

    while (s1[pos] != '\0') {
        s1[pos++] = s1[++i];
    }
}

void squeeze(char s1[], char s2[]) 
{
    int i, j;
    for (i =  0; s1[i] != '\0';) {
        int found = 0;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                left_shift(s1, i);
                found = 1;
                break;
            }
        }

        if (!found)
            i++;
    }
     
}

int main(void)
{
    char s1[] = "nvidia";
    char s2[] = "nomad";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}
