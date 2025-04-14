#include<stdio.h>

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    int a[10001];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    int dem=0;
    for (int i=0; i<n-1; i++)
    for (int j=i+1; j<n; j++) if (a[i]+a[j]==d) dem=dem+1;
    printf("%d", dem);
    return 0;
}
