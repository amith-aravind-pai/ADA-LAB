#include<stdio.h>
#define MAX 1000

typedef struct prop{
    float p;
    float x;
    float w;
    float r;
}pr;

void sort(pr a[],int n){
    for(int i = 0 ; i < n - 1; i++){
        int max_p = i;
        for(int j = i+1 ; j < n; j++){
            if(a[max_p].r < a[j].r){
                max_p = j;
            }
        }
        pr temp = a[i];
        a[i] = a[max_p];
        a[max_p] = temp;
    }
}

void main(){
    int n;
    float m;
    printf("Enter the number of fruits: ");
    scanf("%d", &n);
    printf("Enter total weight: ");
    scanf("%f", &m);
    pr a[MAX];
    for(int i = 0; i<n;i++){
        pr j;
        printf("Enter the profit and weight");
        scanf("%f%f",&j.p,&j.w);
        j.x = 0;
        j.r = (j.p/j.r);
        a[i] = j;
    }
    sort(a,n);
    float tot_profit=0;
    int i = 0;
    float rem = m;
    while(i<n){
        if(rem < a[i].w) break;
        a[i].x = 1.0;
        tot_profit += a[i].p;
        rem -= a[i].w;
        i++;
    }
    if(i<n){
        float frac = rem/a[i].w;
        a[i].x = frac;
        tot_profit += frac * a[i].p;
    }

    printf("Here the maximum profit is : %f",tot_profit);
}