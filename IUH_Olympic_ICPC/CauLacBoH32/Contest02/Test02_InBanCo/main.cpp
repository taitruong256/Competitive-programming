#include <stdio.h>

int main()
{
    int n, i, j, k;

    scanf("%d", &n);
    k = -1;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(k == 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }

            // If k = 1  then k *= -1 => -1
            // If k = -1 then k *= -1 =>  1
            k *= -1;
        }

        if(n % 2 == 0)
        {
            k *= -1;
        }

        printf("\n");
    }

    return 0;
}
