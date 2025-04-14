#include<stdio.h>


void hoandoi(int a, int b)
{
    int tam=a;
    a=b;
    b=tam;
    return;
}

void xuli()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a>b) hoandoi(a, b);
    if (a>c) hoandoi(a, c);
    if (b>c) hoandoi(b, c);

    printf("%d %d %d\n", a, b, c);

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

