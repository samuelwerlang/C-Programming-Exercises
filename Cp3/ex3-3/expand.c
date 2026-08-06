#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

void expand(char s1[], char s2[]);
int expand_range(char start, char end, char s2[], int j);
int same_type(char a, char b);

int main(void)
{
    char s1[MAX_SIZE] = "-a-zYhelloa-f-a0-9\nz-a\na-a", s2[MAX_SIZE];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    i = j = 0;

    while (s1[i] != '\0') {
        int  next = i + 1;
        if (s1[next] == '-' && same_type(s1[i], s1[next + 1])) {
            j = expand_range(s1[i], s1[next + 1], s2, j);
            i += 3;
        }
        else
            s2[j++] = s1[i++];
    }
    s2[j] = '\0';
}

int expand_range(char start, char end, char s2[], int j)
{
    int start_lower = start < end? 1 : 0;
    if (start_lower)
        while (start <= end)
            s2[j++] = start++;
    else
        while (start >= end)
            s2[j++] = start--;
    return j;
}

int same_type(char a, char b)
{
    return (islower(a) && islower(b) ||
            isupper(a) && isupper(b) ||
            isdigit(a) && isdigit(b));
}
