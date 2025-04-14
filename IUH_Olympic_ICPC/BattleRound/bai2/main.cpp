#include<stdio.h>

 typedef long long ll;

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    if (t<10) for (int i=0; i<n; i++) printf("%d", t);
    else if (t==10 && n==1) printf("-1");
    else
    {
        for (int i=0; i<n-1; i++) printf("1");
        printf("0");
    }
    return 0;
}
