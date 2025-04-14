#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n, i, j, s;
    bool ans;
    ans=true;
    scanf ("%d", &n);

    for (i=2; i<n; i++)
    {
        if (n % i ==0)
        {
            ans=false;
            break;
        }
    }

    if (n<2)
    {
        ans=false;
    }

    if (ans==true)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}


