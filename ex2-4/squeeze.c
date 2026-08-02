#include <stdio.h>
#include <stdbool.h>
// Caveats ---> This algorithm is O(n^2); I know it could've been done in a more accurate way, utilizing an array to map the seen ones; 
void left_shift(unsigned char s1[], unsigned int pos); 
void squeeze(unsigned char s1[], unsigned char s2[]); 

int main(void)
{
    unsigned char s1[] = "nvidia";
    unsigned char s2[] = "nomad";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(unsigned char s1[], unsigned char s2[]) 
{
    int i, j;
    for (i =  0; s1[i] != '\0';) {
        bool found = false;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                left_shift(s1, i);
                found = true;
                break;
            }
        }

        if (!found)
            i++;
    }
     
}

void left_shift(unsigned char s1[], unsigned int pos) 
{   
    unsigned int i;
    i = pos;

    while (s1[pos] != '\0') {
        s1[pos++] = s1[++i];
    }
}


