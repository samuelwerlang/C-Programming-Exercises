#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000
#define COL_N 25 

int get_line(char s[], int lim); /* get_line: reads a line, copies it into memory and return it's length */
int find_space(char s[], int nc, int col_n); /*finds the last space before the N column and return it's position */ 
void insert(char buff[], int *len, int pos, char val); /*Shifts all elements to the right and inserts $(val) in the specified position; if it's a blank, just replace it */

int main(void) {
	int len;
	int space_pos;
	int nc;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0){
		nc = 0;
		if (len > COL_N) {
			while (nc + COL_N < len) {
				space_pos = find_space(line, nc, (COL_N + nc));
				/* if (space_pos == -1) {
					nc += COL_N;
					continue;
				} */
				insert(line, &len, space_pos, '\n');
				line[space_pos] = '\n';
				nc = ++space_pos;
			}
			printf("%s", line);

			continue;
		}
		printf("%s", line);
	}

	return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) 
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

int find_space(char s[], int nc, int col_n) {
	int i;
	int space_pos = -1;
	for(i = nc; i < col_n; i++) {
		if (s[i] == ' ') {
			space_pos = i;	
		}
	}
	if (space_pos == -1)
		return col_n;
	return space_pos;
}

void insert(char buff[], int *len, int pos, char val) {
	if (*len >= MAXLINE - 1) {
		return;
	}
	if (buff[pos] == ' ') {
		buff[pos] = val;
		return;
	}

	//Shifts elements to the right
	for (int i = *len + 1; i > pos; --i)
		buff[i] = buff[--i];

	buff[pos] = val;
	++(*len);
}


