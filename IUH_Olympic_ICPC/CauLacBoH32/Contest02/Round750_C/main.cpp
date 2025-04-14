#include<stdio.h>

int main()
{
    int t;
    char s[100001];
    scanf("%d", &t);
    while (t--)
    {
        int n, kq=100001;
        scanf("%d", &n);
        scanf("%s", &s);
        for (char ch='a'; ch<='z'; ch++)
        {
            int l=0;
            int r=n-1;
            int d=0;
            while (l<r)
            {
                if (s[l]==s[r]) {l=l+1;r=r-1;}
                else if (s[l]==ch) {l=l+1; d=d+1;}
                else if (s[r]==ch) {r=r-1; d=d+1;}
                else {d=100001; break;}
            }
            //printf("----%c  %d  %d\n", ch, l, r);
            if (l>=r) kq=d<kq?d:kq;

        }
        printf("%d\n", kq==100001?kq:-1);
    }
    return 0;
}
