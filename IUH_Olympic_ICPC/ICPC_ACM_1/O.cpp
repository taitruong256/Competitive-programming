#include<stdio.h>

int main()
{
    int n;
    int giatri[256];
    char a[256][256];
    for (char i='0'; i<='9'; i++) giatri[(int)i]=(int)i-48;
    for (char i='A'; i<='Z'; i++) giatri[(int)i]=i-55;

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) scanf("%c", &a[i][j]);

    int d[255]={0};  for (int i=0; i<n; i++) printf("%d ", d[i]); printf("\n");
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        char t=a[i][j];
        d[(int)t]=d[(int)t]+1;
        if (d[(int)t]>1)
        {
            printf("No");
            //return 0;
        }
    }

    d[255]={0};
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
        char t=a[j][i];
        d[(int)t]=d[(int)t]+1;
        if (d[(int)t]>1)
        {
            printf("No");
            //return 0;
        }
    }
    return 0;
}
