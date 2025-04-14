
#include<stdio.h>
#include<string.h>


int main()
{
    char s[100005], t[100005];
    scanf("%s", &s);
    int n;
    if (strlen(s)%2==0) n=strlen(s)/2-1; else n=strlen(s)/2;
    int d=0, i=0;
    printf("%c", s[n]);
    while (d<strlen(s)/2)
    {
        d=d+1;
        t[i]=s[n+d];
        t[i+1]=s[n-d];
        i=i+2;

    }
    for (int i=0; i<strlen(s)-1; i++) printf("%c", t[i]);
    return 0;
}
