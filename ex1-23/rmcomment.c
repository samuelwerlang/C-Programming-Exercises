#include <stdio.h>

#define IN 0 
#define OUT 1 
#define SAW_SLASH 2
#define SAW_STAR 3
#define DOUBLE_SLASH 4
#define STRING 5
#define CHAR_CONSTANT 6

int main(void) {
	
	int c, prev;
	int state = OUT;
	c = prev = 0;
	while((c = getchar()) != EOF) {
		
		//Default comments
		if (state == IN && c == '/' && prev == '*') {
			state = OUT;
			prev = c;
			continue;
		} else if (state == IN) {
			prev = c; 
			continue;
		  }

		// Character Constants
		if (state == CHAR_CONSTANT && c == '\'') {
    			putchar(c);
    			state = OUT;
    			continue;
		} else if (state == CHAR_CONSTANT) {
    			putchar(c);
    			continue;
		  }

		if (state == OUT && c == '\'') {
    			putchar(c);
    			state = CHAR_CONSTANT;
    			continue;
		}

		//Strings
		if (state == STRING && c == '"') {
			putchar(c);
    			state = OUT;
			continue;
		} else if (state == STRING) {
    		  	putchar(c);
			continue;
		  }
		
		if (state == OUT && c == '"') {
			putchar(c);
			state = STRING;
			continue;
		}
		//Double slash comments
		if (state == DOUBLE_SLASH && c != '\n') {
			prev = c;
			continue;
		} else if (state == DOUBLE_SLASH && c == '\n') {
			state = OUT;
			prev = c;
			continue;

		  }
		if (state == SAW_SLASH && c == '/')
			state = DOUBLE_SLASH; 	
					
		//State in SAW_SLASH
		if (state == SAW_SLASH && c != '*') {
			putchar('/');
			state = OUT;
		} else if (state == SAW_SLASH && c == '*') {
			state = IN;
		  }
		//State in SAW_STAR
		if (state == SAW_STAR && prev != '/') {
			putchar('*');
			state = OUT;
		  }

		//State in OUT
		if (state == OUT && c == '/') {
			state = SAW_SLASH;
		} else if (state == OUT && c == '*') {
			state = SAW_STAR;
		  }

		if (state == OUT) {
			putchar(c);
		} 

		prev = c;

	}
	return 0;
}
