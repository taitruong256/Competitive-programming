#include<stdio.h>

int main()
{
    int n;  printf("Nhap n = "); scanf("%d", &n);
    int a[100];
    for (int i=0; i<n; i++) {printf("A[%d]=", i); scanf("%d", &a[i]);}


    for (int i=0; i<100; i++) printf("%d ", a[i]);
    return 0;
}
