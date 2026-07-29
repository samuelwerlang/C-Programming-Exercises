#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "\033[31mUsage: %s <file>\033[0m\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "\033[31mAn error occurred while reading the file\033[0m\n");
        return 1;
    }

    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while ((c = fgetc(fp)) != EOF) {
        nc++;

        if (c == '\n')
            nl++;

        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);

    fclose(fp);
    return 0;
}
