#include<stdio.h>
#include<stdbool.h>

void xuli()
{
    int s1, s2, s3, s4;
    scanf("%d %d %d %d", &s1, &s2, &s3, &s4);
    bool kt=true;
    if (s1>s3 && s1>s4 && s2>s3 && s2>s4) kt=false;
    if (s3>s1 && s3>s2 && s4>s1 && s4>s2) kt=false;
    if (kt==true) printf("YES\n"); else printf ("NO\n");
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        xuli();
    }
    return 0;
}
