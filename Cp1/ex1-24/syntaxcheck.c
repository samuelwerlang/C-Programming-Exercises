#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_SIZE 100
#define COMMENT_START '*' 
#define COMMENT_END '/'
#define STRING_MARKER '"'
#define CHAR_CONST_MARKER '\''
#define ESCAPE '\\'
#define OPEN_PAR '('
#define CLOSE_PAR ')'
#define OPEN_BRACKET '['
#define CLOSE_BRACKET ']'
#define OPEN_BRACE '{'
#define CLOSE_BRACE '}'

typedef enum {
	OUT,
	STRING,
	STRING_ESCAPE,
	CHAR_CONST,
	COMMENT,
	SINGLE_LINE_COMMENT
} State;

typedef struct {
	char arr[MAX_SIZE];
	int8_t top; 
} Stack;

void init(Stack *stack);
void push(Stack *stack, int val);
int pop(Stack *stack);
int peek(Stack *stack);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
bool match(Stack *stack, int val); /* match: receives a value and compare it to the last item pushed into the stack  */

int main(void) {
	unsigned int c, prev, char_num = 1;
	Stack stack;
	State state = OUT;
       	init(&stack);
	prev = 0;

	while ((c = getchar()) != EOF) {
		switch (state) {
			case OUT:
				if (c == COMMENT_START && prev == '/')
					state = COMMENT;
				if (c == '/' && prev == '/')
					state = SINGLE_LINE_COMMENT;
				if (c == STRING_MARKER)
					state = STRING;
				if (c == CHAR_CONST_MARKER)
					state = CHAR_CONST;

				if (is_full(&stack)) {
					printf("Stack is full, exiting...\n");
					return 1;
				}
				
				if (c == CLOSE_PAR ||  c == CLOSE_BRACKET || c == CLOSE_BRACE) {
			       		if (match(&stack, c)) {
				  		pop(&stack);
				  	} else {
				  		fprintf(stderr, "Syntax Error: char %c at %u\n", c, char_num);
				    	}
				}

				if (c == OPEN_PAR || c == OPEN_BRACKET || c == OPEN_BRACE) {
					push(&stack, c);
				}

				++char_num;
				prev = c;
				break;

			case COMMENT:
				if (c == COMMENT_END && prev == '*')
					state = OUT;
				++char_num;
				prev = c;
				break;
			
			case SINGLE_LINE_COMMENT:
				if (c == '\n')
					state = OUT;
				++char_num;
				prev = c;
				break;

			case STRING:
				if (c == ESCAPE)
					state = STRING_ESCAPE;
				if (c == STRING_MARKER)
					state = OUT;
				++char_num;
				prev = c;
				break;

			case STRING_ESCAPE:
				state = STRING;
				++char_num;
				prev = c;
				break;

			case CHAR_CONST:
				if (c == CHAR_CONST_MARKER)
					state = OUT;
				++char_num;
				prev = c;
				break;
		}
	}
	if (state == STRING) {
		printf("Syntax Error: double quotes were initialized, but not terminated\n");
		return 1;	
	} else  if (state == COMMENT) {
		printf("Syntax Error: comment initialized, but not terminated\n");
		return 1;	
	} else if (state == CHAR_CONST) {
		printf("Syntax Error: single initialized, but not terminated\n");
		return 1;	
	} 
	if (state == OUT && is_empty(&stack) == true) {
		printf("File syntax check has passed\n");
	} else {
		fprintf(stderr, "Stack not empty, please check for unbalanced characters\n");
	}
	
	return 0;
}

void init(Stack *stack) {
	stack->top = -1;
}

bool is_full(Stack *stack) {
	return stack->top >= MAX_SIZE - 1;
}

bool is_empty(Stack *stack) {
	return stack->top == -1;
}

void push(Stack *stack, int val) {
	if (is_full(stack)) {
		fprintf(stderr, "Stack overflow\n");
		return;
	}
	stack->arr[++stack->top] = val;	
}

int pop(Stack *stack) {
	if (is_empty(stack)) {
		fprintf(stderr, "Stack underflow\n");
		return -1;
	}
	int popped = stack->arr[stack->top];
	stack->top--;
	return popped;
}

int peek(Stack *stack) {
	if (is_empty(stack)) {
		fprintf(stderr, "Stack is empty");
		return -1;
	}
	return stack->arr[stack->top];
}

bool match(Stack *stack, int val) {
	if (is_empty(stack)) {
		return false;
	}
	bool matches = false;
	char top_val = peek(stack);
	switch (top_val) {
		case OPEN_PAR:
			if (val == CLOSE_PAR)
				matches = true;
			break;
		case OPEN_BRACKET:
			if (val == CLOSE_BRACKET)
				matches = true;
			break;
		case OPEN_BRACE:
			if (val == CLOSE_BRACE)
				matches = true;
			break;
	}
	return matches;
}
