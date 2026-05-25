#include <stdio.h>
#include <stdlib.h>

int x[20], n, count = 0;

int PLACE(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}
void printSolution()
{
    count++;
    printf("\nSolution %d:\n", count);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void NQueens(int n)
{
    int k = 1;
    x[k] = 0;
    while (k > 0)
    {
        x[k] = x[k] + 1;
        while ((x[k] <= n) && !PLACE(k, x[k]))
        {
            x[k] = x[k] + 1;
        }
        if (x[k] <= n)
        {
            if (k == n)
            {
                printSolution();
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else{
            k--;
        }
    }
}

int main()
{
    printf("Enter no of queens: ");
    scanf("%d", &n);
    NQueens(n);
    if (count == 0)
    {
        printf("No solution exists.\n");
    }
    return 0;
}