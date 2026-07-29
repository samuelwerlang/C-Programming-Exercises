#include <stdio.h>
#define TAB_STP_INTERVAL 16

int calc_diff(int nc); /* calc_diff: calculate the difference between the currentc column and the next tab stop based on it's interval*/

int main(void) {
	int c, nc;
	nc = 0;
	while((c = getchar()) != EOF) {
		if (c == '\t') {
			int diff = calc_diff(nc);
			while (diff > 0) {
				printf("%c", ' ');
				--diff;
				++nc;
			}

			continue;
		}

		putchar(c);

		if (c == '\n') {
			nc = 0;
		} else {
			++nc;
		}
	}
	return 0;
}

int calc_diff(int nc) {
	int tabstp;
	tabstp = TAB_STP_INTERVAL;
	while(tabstp <= nc)
		tabstp += TAB_STP_INTERVAL;
	return tabstp - nc;
}


