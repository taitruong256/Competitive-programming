#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

void xuli()
{
    int n, a[1000];
    bool kt=true;
    scanf("%d", &n);
    for (int j=0; j<n; j++) scanf("%d", &a[j]);

    for (int j=0; j<n-1; j++)
    for (int k=j+1; k<n; k++) if (a[j]>a[k])
    {
        int t=a[j];
        a[j]=a[k];
        a[k]=t;
    }

    for (int j=0; j<n-1; j++) if (abs(a[j+1]-a[j])>1)
    {
        kt=false;
        break;
    }

    if (kt==true) printf("YES\n");
    else printf("NO\n");
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
