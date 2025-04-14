#include<stdio.h>
#include<string.h>


int main()
{
    char s[100005], t[100005];
    scanf("%s", &s);
    long long n;
    if (strlen(s)%2==0) n=strlen(s)/2-1; else n=strlen(s)/2;
    long long d=0, i=0;
    t[i]=s[n];
    long long tam=n/2;
    for (long long k=0; k<n/2; k++)
    {
        d=d+1;
        i=i+1;
        t[i]=s[n+d];
        i=i+1;
        t[i]=s[n-d];
    }

    for (i=0; i<strlen(s); i++) printf("%c", t[i]);
    return 0;
}
