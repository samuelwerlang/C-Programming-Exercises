#include <stdio.h>
#define TABSTOP 8

int get_blank_len(void); /* get_blk: get the current blank length; */
void replace_blanks(int *spaces, int *col); /* Replace the current blank sequence with tabs and spaces; */

int main(void) {
	int c, spaces; //Current blank string length
	int col = 0;
	while((c = getchar()) != EOF){
		if (c == ' ') {
			spaces = get_blank_len();
			replace_blanks(&spaces, &col);
			continue;

		}

		putchar(c);

		if (c == '\n') { 
			col = 0;
		} else {
			++col;
		  }
	}

	return 0;
}

int get_blank_len(void) {
	int c, i = 1;
	while((c = getchar()) == ' ') {
		++i;
	}
	if (c  != EOF)
		ungetc(c, stdin);
	return i;
}

void replace_blanks(int *spaces, int *col) {
	while (*spaces > 0) {
		int to_tabstop = TABSTOP - (*col % TABSTOP);
		if (to_tabstop <= *spaces) {
			putchar('\t');
			*spaces -= to_tabstop;
			*col += to_tabstop;
		} else {
			putchar(' ');
			--(*spaces);
			++(*col);
		  }

	}	
}

