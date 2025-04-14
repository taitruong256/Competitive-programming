#include<stdio.h>

int main()
{
    int a, b, d=0;
    scanf("%d%d", &a, &b);
    if (a==1 && b==1) {printf("0"); return 0;}
    while (a>0 && b>0)
    {
        if(a<b)
        {
            a=a+1;  // printf("--%d   %d----\n", a, b);
            b=b-2;
        }
        else
        {
            a=a-2; // printf("--%d   %d----\n", a, b);
            b=b+1;
        }
        d=d+1;
    }

    printf("%d", d);
    return 0;
}
