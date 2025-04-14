#include<stdio.h>
#include<string.h>
using namespace std;


int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        char s[10000000];
        scanf("%s", &s);
        int gtmin=1000000000;
        for (int i=1; i<strlen(s); i++) if (s[i]=='a')
        {
            if (i>0 && s[i]=='a' && s[i-1]=='a') gtmin=min(gtmin, 2);
            if (i>1 && s[i]=='a' && s[i-2]=='a') gtmin=min(gtmin, 3);
            if (i>2 && s[i]=='a' && s[i-3]=='a' && s[i-2]!=s[i-1]) gtmin=min(gtmin, 4);
            if (i>5 && s[i]=='a' && s[i-3]=='a' && s[i-6]=='a' && s[i-1]!=s[i-4]) gtmin=min(gtmin, 7);
        }
        if (gtmin==1000000000) printf("-1\n"); else printf("%d\n", gtmin);
    }
    return 0;
}
