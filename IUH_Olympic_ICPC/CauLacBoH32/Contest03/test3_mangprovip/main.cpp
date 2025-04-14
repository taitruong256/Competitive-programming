#include<stdio.h>


int doi(int a)
{
    if (a==1) return 0;
    else return 1;
}


void xuli()
{
    int n, a[40];
    scanf("%d", &n);
    for (int j=0; j<n; j++) scanf("%d", &a[j]);



    int d=0;
    for (int j=0; j<n; j++) if (j%2!=a[j]%2)
    {
        for (int k=j+1; k<n; k++) if (k%2!=a[k]%2 && k%2==doi(j%2))
        {
            d=d+1;       //printf("-----------%d %d\n", a[j], a[k]);
            int tam=a[j];
            a[j]=a[k];
            a[k]=tam;
            break;
        }
    }



    for (int j=0; j<n; j++) if (j%2!=a[j]%2)
    {
        d=-1;
        break;
    }
    printf("%d\n", d);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        xuli();
    }
    return 0;
}
