#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    //    ------nhap----------
    int a, b, vt;
    scanf("%d %d", &a, &b);

    //-----chuyen so thuc sang chuoi----------
    char thuc[100];
    float chia=(float)a/(float)b;
    sprintf(thuc, "%f", chia);
    //printf("%s     %c\n", thuc, thuc[0]);


    //---------tach chuoi truoc dau '.'--------
    for (int i=0; i<strlen(thuc); i++)
        if (thuc[i]=='.')
    {
        vt=i;
        break;
    }
    //printf("vi tri %d\n", vt);
    for (int i=0; i<vt; i++)
        printf("%c", thuc[i]);
    printf(" ");



    //----------tach chuoi sau dau '.'-----------
    int n=strlen(thuc)-1;
    while (thuc[n]=='0')
    {
        thuc[n]='\0';
        n=n-1;
    }
    for (int i=vt+1; i<strlen(thuc); i++)
        printf("%c", thuc[i]);

    return 0;
}
