#include<stdio.h>

typedef struct item{
    int p;
    int w;
}p;

void main(){
    int m,n;
    printf("Enter maximum weight: ");
    scanf("%d",&m);
    printf("Enter the number of items");
    scanf("%d",&n);
    p pa[n+1];
    for(int i=1; i<=n; i++){
        p p1;
        printf("Enter profit and weight: ");
        scanf("%d%d",&p1.p,&p1.w);
        pa[i] = p1;
    }
    int a[n+1][m+1];
    for(int i=0;i<=n;i++)
        a[i][0] = 0;
    for(int i=0;i<=m;i++)
        a[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<pa[i].w)
                a[i][j] = a[i-1][j];
            else{
                int m = a[i-1][j];
                if(pa[i].p + a[i-1][j-pa[i].w] > m) m = pa[i].p + a[i-1][j-pa[i].w];
                a[i][j] = m;
            }
        }
    }
    printf("Maxiumum profit: %d",a[n][m]);
}