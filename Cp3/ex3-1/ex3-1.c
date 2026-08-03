#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1000000
/* bin_search: find x in v[0] <= v[1] <= ... <= v[n-1] */
int bin_search(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else /* found match */
            low = mid + 1;
    }
    return (x == v[low]) ? low : -1; /* no match */
}

int main(void)
{
    int i, j;
    int r_val = 0;
    int v[MAX_SIZE];
    double seconds = 0;

    for (i = j = 0; i < MAX_SIZE - 1; i++) {
        v[i] = j;
        ++j;
    }
    clock_t t1 = clock();
    bin_search(256, v, MAX_SIZE);
    clock_t t2 = clock();
    seconds = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("CPU TIME: %lf\n", seconds);
    return 0;
}
