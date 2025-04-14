#include<stdio.h>

int d;
int np[4];
int a, b, c;


void hoandoi(int *a, int *b)
{
    int tam=*a;
    *a=*b;
    *b=tam;
    return;
}


void xuli()
{
    int gt[4];
    scanf("%d%d%d", &gt[1], &gt[2], &gt[3]);

    if (gt[1]<gt[2]) hoandoi(&gt[1], &gt[2]);
    if (gt[1]<gt[3]) hoandoi(&gt[1], &gt[3]);
    if (gt[2]<gt[3]) hoandoi(&gt[2], &gt[3]);

    d=0;
    for (int j=1; j<=3; j++) if (gt[j]>0)
    {
        d=d+1;                 // printf("%d\n", i);
        gt[j]=gt[j]-1;
    }

    for (int j=1; j<=2; j++) if (gt[j]>0)
    {
        for (int k=j+1; k<=3; k++) if (gt[k]>0)
        {
            d=d+1;            //printf("%d %d\n", i, j);
            gt[j]=gt[j]-1;
            gt[k]=gt[k]-1;
        }
    }

    if (gt[1]>0 && gt[2]>0 && gt[3]>0)
    {
        d=d+1;           //   printf("%d %d %d\n", 1, 2, 3);
    }
    printf("%d\n", d);
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
