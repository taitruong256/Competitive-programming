#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool tuanhoan(char s[50])
{
    bool kt=true;
    printf("\nDo dai cua xau : %d", strlen(s));
    if (strlen(s)/2==1) kt=false;
    for (int i=0; i<strlen(s) / 2; i++)
    {
        if (s[i]!=s[i+strlen(s)/2]) kt=false;
    }
    return kt;
}

int main()
{
    //------nhap----------
    int a, b;
    scanf("%d %d", &a, &b);

    //--------in phan nguyen-----------
    printf("nguyen %d \n", a/b);

    //--------------xu ly phan thuc-----------
    int tam=a%b;
    int kq=0;
    char thuc[50];
    sprintf(thuc, "%d", tam);
    printf("\nphan du %d", tam);
    while (tam!=0 && tuanhoan(thuc)==false)
    {
        tam=tam*10;
        kq=kq*10+tam/b;
        tam=tam%b;
        sprintf(thuc, "%d", kq);
        printf("\n%s  ", thuc);
    }
    printf("\nthuc %d", kq);

  /*  char test[50];
    printf("Nhap xau: ");scanf("%s", &test);
    if (tuanhoan(test)==true) printf("\n%s la tuan hoan", test);
    else printf("\n%s la khong tuan hoan", test);
*/
    return 0;
}
