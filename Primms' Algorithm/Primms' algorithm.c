#include <stdio.h>

void prims(int n, int a[n+1][n+1]) {
    int near[n+1];
    int t[n][2]; 
    int mincost = 0;


    int min = 1000;
    int k = -1, l = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {  
            if (a[i][j] < min) {
                min = a[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[0][0] = k;
    t[0][1] = l;
    mincost = a[k][l];


    for (int i = 1; i <= n; i++) {
        if (a[i][k] < a[i][l]) near[i] = k;
        else near[i] = l;
    }
    near[k] = near[l] = 0; 


    for (int i = 1; i <= n-2; i++) {
        int min = 1000;
        int j = -1;
        for (int m = 1; m <= n; m++) {
            if (near[m] != 0 && a[m][near[m]] < min) {
                min = a[m][near[m]];
                j = m;
            }
        }

        t[i][0] = j;
        t[i][1] = near[j];
        mincost += a[j][near[j]];
        near[j] = 0;


        for (int m = 1; m <= n; m++) {
            if (near[m] != 0 && a[m][j] < a[m][near[m]]) {
                near[m] = j;
            }
        }
    }

    // Print MST edges
    printf("Edges in MST:\n");
    for (int i = 0; i < n-1; i++) {
        printf("%d - %d\n", t[i][0], t[i][1]);
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[n+1][n+1];
    printf("Enter cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    prims(n, a);
    return 0;
}