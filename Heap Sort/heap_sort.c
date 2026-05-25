#include<stdio.h>

void heapify(int a[],int n, int p){
    int item = a[p];
    int c = 2*p+1;
    while(c<=n-1){
        if(c+1<=n-1 && a[c+1] > a[c]) c++;
        if(item < a[c]){
            a[p] = a[c];
            p = c;
            c = 2*p+1;
        }
        else break;   
    }
    a[p] = item;
}

void create_heap(int a[], int n){
    for(int i = (n-1)/2; i>=0; i--) heapify(a,n,i);
}

void heap_sort(int a[],int n){
    create_heap(a,n);
    for(int i = n-1; i>=0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,i,0);
    }
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array :");
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heap_sort(a,n);
    printf("Sorted: ");
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}