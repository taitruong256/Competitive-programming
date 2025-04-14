#include<stdio.h>
#include<string.h>

int main()
{

    //nhap
    long n;
    char str[100000];
    scanf("%d", &n);
    for (long i=0; i<n; i++) scanf("%c", &str[i]);         //printf("%s", str);


    //xoa chu H
    int i=0; n=strlen(str);
    while (i<n)
    {
        if (str[i]=='H')
        {
            for (int j=i; j<n; j++)
                str[j]=str[j+1];
            n=n-1;
        }
        else
        {
            i=i+1;
        }
    }
    //printf("\n%s", str);

    long doi=0;
    for (long i=0; i<n; i++)
    {
        if ((str[i]=='P' || str[i]=='L') && (str[i+1]=='3' || str[i+1]=='2'))
        {
            doi=doi+1;
        }
        else if ((str[i]=='3' || str[i]=='2') && (str[i+1]=='P' || str[i+1]=='L'))
        {
                doi=doi+1;
        }
    }
    printf("%d", doi);
    return 0;
}
