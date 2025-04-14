#include<stdio.h>

int main()
{
    int l, t, d, i, sl;
    scanf("%d %d %d", &l, &t, &d);
    sl=0;
    for (i=0; i<=d; i++)
    {
        if (l+d-i>t+i)
        {
            sl=sl+1;
            //printf("%d     %d  \n", l+d-i, t+i);
        }
    }
    printf("%d", sl);
    return 0;
}
