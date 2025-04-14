#include<stdio.h>

int main()
{
    int n;
    char s[255];
    scanf("%d", &n);
    scanf("%s", &s);
    int dA=0, dC=0, dG=0, dT=0;

    if (n%4!=0) printf("===");
    else
    {
        for (int i=0; i<n; i++)
        {
            if (s[i]=='A') dA=dA+1;
            if (s[i]=='C') dC=dC+1;
            if (s[i]=='G') dG=dG+1;
            if (s[i]=='T') dT=dT+1;
        }
        if (dA>n/4 || dC>n/4 || dG>n/4 || dT>n/4) printf("===");
        else
        {
            if (dA<n/4)
                for (int j=0; j<n; j++) if (s[j]=='?' && dA<n/4)
                {
                    s[j]='A';
                    dA=dA+1;
                }
            if (dC<n/4)
                for (int j=0; j<n; j++) if (s[j]=='?' && dC<n/4)
                {
                    s[j]='C';
                    dC=dC+1;
                }
            if (dG<n/4)
                for (int j=0; j<n; j++) if (s[j]=='?' && dG<n/4)
                {
                    s[j]='G';
                    dG=dG+1;
                }
            if (dT<n/4)
                for (int j=0; j<n; j++) if (s[j]=='?' && dT<n/4)
                {
                    s[j]='T';
                    dT=dT+1;
                }
            puts(s);

        }
    }
    return 0;
}
