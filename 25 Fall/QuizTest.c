#include <stdio.h>

#define N 5

int main()
{
    int i, k, n;
    int t1[N] = {1, 2, 3, 4, 5}, t2[N] = {1, 2, 3, 4, 5}, pt[N][N];

    for (i = 0; i < N; i++)
    {
        for (k = 0; k < N; k++)
        {
            pt[N][N] = 0;
            for (n = 0; n < N; n++)
            {
                pt[i][n] = t1[i] * t2[n];
                printf("%4d", pt[i][n]);
            }
            printf("\n");
        }
    }

    return 0;
}