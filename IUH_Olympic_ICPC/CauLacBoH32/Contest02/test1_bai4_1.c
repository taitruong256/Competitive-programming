#include<stdio.h>
#include<string.h>
#include<conio.h>


int main()
{
    char  a[10000], b[10000], s[10000];
    scanf("%s", &s);
    int vt=0;
    printf("\n%s", s);


    for (int i=0; i<strlen(s); i++) if (s[i]==' ')
    {
        vt=i;

    }
    printf("\nvi tri khoang trang %d", vt);


    for (int i=0; i<vt; i++) a[i]=s[i];
    for (int i=0; i<vt; i++) b[i]=s[vt+i+1];
    printf("\n%s               %s", a, b);
    return 0;
}
