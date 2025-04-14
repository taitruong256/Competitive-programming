#include<stdio.h>
#include<math.h>

void hoandoi(int *a, int *b)
{
    int tam=*a;
    *a=*b;
    *b=tam;
    return;
}

int main()
{
    int a[100];
    int n, tong=0;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        tong=tong+a[i];
    }          //printf("%d\n", tong);

    for (int i=0; i<n-1; i++)
    for (int j=i+1; j<n; j++) if (a[i]>a[j]) hoandoi(&a[i], &a[j]);

    //for (int i=0; i<n; i++) printf("%d ", a[i]); printf("\n");

    float tbc=(tong*1.0)/n;  //printf("%f\n", tbc);
    int d=0;
    while (tbc<4.5)
    {
        tong=tong-a[d]+5;
        tbc=(tong*1.0)/n;
        d=d+1;
    }

    if (d==0) printf("0"); else printf("%d", d);

    return 0;
}
