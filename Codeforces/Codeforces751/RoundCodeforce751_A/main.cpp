#include<stdio.h>
#include<string.h>


int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        char s[101];
        scanf("%s", &s);
        char ch='z';
        for (int j=0; j<strlen(s); j++) if (s[j]<ch) ch=s[j];
        printf("%c ", ch);

        for (int j=0; j<strlen(s); j++) if (s[j]==ch)
        {
            for (int k=j; k<strlen(s)-1; k++) s[k]=s[k+1];
            break;
        }
        for (int j=0; j<strlen(s)-1; j++) printf("%c", s[j]);
        printf("\n");
    }

    return 0;
}
