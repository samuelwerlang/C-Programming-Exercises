#include <stdio.h>

int main(void) {
	int c, prev = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ' && prev == ' ') continue;
		putchar(c);
		prev = c;
	}
	return 0;
}
