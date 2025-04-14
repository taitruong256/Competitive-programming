#include<stdio.h>
#include<string.h>


int main()
{
    char  a[10000], b[10000], s[10000];
    gets(s);
    int vt=0;
    for (int i=0; i<strlen(s); i++) if (s[i]=' ')
    {
        vt=i;
        break;
    }


    return 0;
}
