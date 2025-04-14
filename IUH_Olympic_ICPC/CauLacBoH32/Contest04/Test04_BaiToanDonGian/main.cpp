#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    scanf("%s", &s); //printf("%s", s);
    for (int i=0; i<strlen(s)-1; i++) if (s[i]!='+')
    for (int j=i+1; j<strlen(s); j++) if (s[j]!='+' && s[i]>s[j])
    {
        char t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
    printf("%s", s);
    return 0;
}
