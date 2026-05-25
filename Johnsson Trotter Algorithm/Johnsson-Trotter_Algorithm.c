#include <stdio.h>

struct Element {
    int num;
    int dir;
};


int searchArr(struct Element a[], int n, int mobile)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i].num == mobile)
            return i;
    }
    return -1;
}


int getMobile(struct Element a[], int n)
{
    int mobile = 0;

    for(int i = 0; i < n; i++)
    {
       
        if(a[i].dir == 0 && i != 0)
        {
            if(a[i].num > a[i-1].num && a[i].num > mobile)
            {
                mobile = a[i].num;
            }
        }

        
        if(a[i].dir == 1 && i != n-1)
        {
            if(a[i].num > a[i+1].num && a[i].num > mobile)
            {
                mobile = a[i].num;
            }
        }
    }
    
    return mobile;
}


void printPermutation(struct Element a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d",a[i].num);
    printf("\n");
}


int fact(int n)
{
    int res = 1;
    for(int i=1;i<=n;i++)
        res *= i;
    return res;
}

void generatePermutation(int n)
{
    struct Element a[n];

    for(int i=0;i<n;i++)
    {
        a[i].num = i+1;
        a[i].dir = 0;
    }

    printPermutation(a,n);

    for(int i=1;i<fact(n);i++)
    {
        int mobile = getMobile(a,n);

        int pos = searchArr(a,n,mobile);

        if(a[pos].dir == 0)
        {
            struct Element temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;
            pos = pos-1;
        }
        else if(a[pos].dir == 1)
        {
            struct Element temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;
            pos = pos+1;
        }

        for(int j=0;j<n;j++)
        {
            if(a[j].num > mobile)
            {
                if(a[j].dir == 1)
                    a[j].dir = 0;
                else
                    a[j].dir = 1;
            }
        }

        printPermutation(a,n);
    }
}

int main()
{
    int n = 3;
    generatePermutation(n);
    return 0;
}