#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 100
#define NUM_QUERIES 10

static int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int binary_search(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    FILE *fp = fopen("Lab11.dat", "r");
    if (!fp) {
        perror("Error opening lab11.dat");
        return 1;
    }

    int a[MAXN], n = 0, x;
    while (n < MAXN && fscanf(fp, "%d", &x) == 1) {
        if (x == -1) break;
        if (x <= 0) { fprintf(stderr, "Non-positive value ignored: %d\n", x); continue; }
        a[n++] = x;
    }
    fclose(fp);

    if (n == 0) {
        fprintf(stderr, "No data read from lab11.dat (before -1).\n");
        return 1;
    }

    // Binary search requires sorted input; sort to be safe.
    qsort(a, n, sizeof(int), cmp_int);

    printf("Loaded %d values (sorted):\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], (i+1==n?'\n':' '));
    }

    srand((unsigned)time(NULL));

    // Generate random queries around the observed range
    int minv = a[0], maxv = a[n-1];
    int lo = (minv > 1 ? minv - (minv/3 + 1) : 1);
    int hi = maxv + (maxv/3 + 10);

    printf("\nRandom search queries and results:\n");
    for (int i = 0; i < NUM_QUERIES; ++i) {
        int key = lo + rand() % (hi - lo + 1);
        int idx = binary_search(a, n, key);
        if (idx >= 0) {
            printf("Query %2d: key=%d -> FOUND at index %d\n", i+1, key, idx);
        } else {
            printf("Query %2d: key=%d -> not found\n", i+1, key);
        }
    }

    return 0;
}