#include <stdio.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

void escape(char s[], char t[]);
void escapetoc(char s[], char t[]);

int main(void)
{
    char s1[MAX_SIZE] = "Hello\nWorld";
    char s2[MAX_SIZE];
    escape(s1, s2);
    printf("The old string:\t %s\n", s2);
    escapetoc(s1, s2);
    printf("The new string:\t %s\n", s2);
    return 0;
}

void escape(char s[], char t[])
{
    int i, k;
    for (i = k = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\t':
                t[k++] = '\\';
                t[k++] = 't';
                break;
            case '\n':
                t[k++] = '\\';
                t[k++] = 'n';
                break;
            default:
                t[k++] = s[i];
                break;
        }
        t[k] = '\0';
    }
}

void escapetoc(char s[], char t[])
{
    int i, j, k;
    i = j = 0;

    while (s[i] != 0)
        switch (s[i]) {
            case '\\':
                switch(s[i + 1]) {
                    case 't':
                        t[j++] = '\t';
                        i += 2;
                        break;
                    case 'n':
                        t[j++] = '\n';
                        i += 2;
                        break;
                }
            break; 
            default:
                t[j++] = s[i++];
                break;
        }
        t[j] = '\0';
}
