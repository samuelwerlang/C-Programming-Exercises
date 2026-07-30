#include <stdio.h>

int compute_length(void);

int main(void) 
{
	printf("char %zd\n", sizeof(char));
	printf("short %zd\n", sizeof(short));
	printf("int %zd\n", sizeof(int));
	printf("float %zu\n", sizeof(float));
	printf("long %zd\n", sizeof(long));
	printf("double %zd\n", sizeof(double));
	printf("unsigned int %zd\n", sizeof(unsigned int));
	printf("signed int %zd\n", sizeof(signed int));
	printf("long double %zd\n", sizeof(long double));

	printf("Computed length of unsigned int: %d\n", compute_length());
	return 0;
}

int compute_length(void) 
{
	unsigned int x = 1;
	int i = 0;

	while (x) {
		x = x << 1;
		++i;	
	}
	return (i / 8);

}

