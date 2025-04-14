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

/*void check(int *a, int *b, int *c, int *dem)
{
    if (np[1]+np[2]+np[3]>0 && *a>np[1] && *b>np[2] && *c>np[3])
    {
        printf("----%d %d %d----a=%d  b=%d  c=%d\n", np[1], np[2], np[3], *a, *b, *c);
        *dem=*dem+1;
        *a=*a-np[1];
        *b=*b-np[2];
        *c=*c-np[3];

    }

}

void nhiphan(int i)
{
    for (int j=0; j<=1; +j++)
    {
        np[i]=j;
        if (i==3)
        {
            check(&a, &b, &c, &d);
            printf("----%d %d %d----\n", np[1], np[2], np[3]);
        }
        else nhiphan(i+1);
    }
}*/

void xuli()
{
    int gt[4];
    scanf("%d %d %d", &gt[1], &gt[2], &gt[3]);

    if (gt[1]<gt[2]) hoandoi(&gt[1], &gt[2]);
    if (gt[1]<gt[3]) hoandoi(&gt[1], &gt[3]);
    if (gt[2]<gt[3]) hoandoi(&gt[2], &gt[3]);

    d=0;
    for (int i=1; i<=3; i++) if (gt[i]>0)
    {
        d=d+1;    printf("%d\n", i);
        gt[i]=gt[i]-1;
    }

    for (int i=1; i<=3; i++) if (gt[i]>1)
    {
        for (int j=i+1; j<=3; j++) if (gt[j]>1)
        {
            d=d+1;      printf("%d %d\n", i, j);
            gt[i]=gt[i]-1;
            gt[j]=gt[j]-1;
        }
    }

    if (gt[1]>0 && gt[2]>0 && gt[3]>0)
    {
        d=d+1;              printf("%d %d %d\n", 1, 2, 3);
    }
    printf("--------------%d-----------------\n", d);
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
