#include<stdio.h>

void floyds(int n, int a[n][n], int cost[n][n]){
    for(int i =0 ; i<n; i++){
        for(int j=0 ; j<n; j++){
            a[i][j] = cost[i][j];
        }        
    }

    for(int k =0 ; k<n; k++){
        for(int i =0 ; i<n; i++){
            for(int j=0 ; j<n; j++){
                int min = a[i][j];
                min = (a[i][k]+a[k][j] < min) ? a[i][k]+a[k][j] :  min;
                a[i][j] = min;
            }        
        }
    }
}

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int a[n][n], cost[n][n];
    printf("Enter the vertices: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&cost[i][j]);
        }
    }
    floyds(n,a,cost);
    printf("Minimum path: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}