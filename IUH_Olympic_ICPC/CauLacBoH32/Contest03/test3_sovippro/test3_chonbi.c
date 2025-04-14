#include<stdio.h>

int main()
{
    int n, a[1000];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i=0, j=n-1;
    int Bao=0, Trong=0;
    int luot=0;
    while (i<=j)
    {
        if (a[i]>a[j])
        {
            if (luot%2==0) Bao=Bao+a[i];
            else Trong=Trong+a[i];
            i=i+1;
        }
        else
        {
            if (luot%2==0) Bao=Bao+a[j];
            else Trong=Trong+a[j];
            j=j-1;
        }
        luot=luot+1;
    }
    printf("%d %d", Bao, Trong);
    return 0;
}
