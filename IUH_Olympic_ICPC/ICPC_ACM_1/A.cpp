#include<stdio.h>
#include<string.h>
#include<stdbool.h>


int main()
{
    char s[101];
    scanf("%s", &s);
    bool co=true;
    for (int i=0; i<strlen(s)-1; i++)
        for (int j=i+1; j<strlen(s); j++)
    {
        bool kt=true;
        for (int k=0; k<=(j-i+1)/2; k++) if (s[i+k]!=s[j-k]) kt=false;
        if (kt==true && (j-i)%2==1) co=false;
    }
    if (co==true) printf("Odd."); else printf("Or not.");
    return 0;
}
