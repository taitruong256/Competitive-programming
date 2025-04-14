#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char banphim[256], giatri[256], s[256];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", &banphim);
        for (int i=0; i<strlen(banphim); i++) giatri[banphim[i]]=i;
        scanf("%s", &s);
        int sum=0;
        if (strlen(s)==1) sum=0;
        else
        {
            for (int i=1; i<strlen(s); i++) sum=sum+abs(giatri[(int)s[i]]-giatri[(int)s[i-1]]);
        }
        printf("%d\n", sum);
    }
    return 0;
}
