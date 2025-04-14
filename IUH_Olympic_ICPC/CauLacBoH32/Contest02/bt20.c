#include<stdio.h>

int main()
{
    //-----------nhap du lieu--------
    int m, n;
    scanf("%d%d", &n, &m);
    int a[10000];
    int dem[10000]={};
    int i, j, max =0;
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        dem[a[i]]++;
        if (a[i]>max) max=a[i];
    }
    for (j=0; j<m; j++)
    {
        scanf("%d", &a[n+j]);
        dem[a[n+j]]++;
        if (a[n+j]>max) max=a[n+j];
    }
    //for (i=0; i<=max; i++) if (dem[i]>0) printf("\n%d : %d", i, dem[i]); printf("\n"); printf("\n"); printf("\n");


    //-----------sap sep so lan xuat hien tang dan------------
    for (i=0; i<max-1; i++)
        for (j=i+1; j<max; j++) if (dem[i]>0 && dem[j]>0 && dem[i]<dem[j])
        {
            int tam=dem[i];
            dem[i]=dem[j];
            dem[j]=tam;
        }

    //for (i=0; i<=max; i++) if (dem[i]>0) printf("\n%d : %d", i, dem[i]); printf("\n"); printf("\n"); printf("\n"); printf("\n");

    //------------xu li------------
    int sl=0;
    for (i=0; i<=max; i++) if (dem[i]>0)
    {
        if (n>dem[i])
        {
            n=n-dem[i];
            sl=sl+1;         //  printf("\nTru di %d   %d", i, dem[i]);
        }
        else
        {
            sl=sl+1;         //   printf("\nTru di %d   %d", i, dem[i]);
            break;
        }
    }
    printf("%d", sl);
    return 0;
}
