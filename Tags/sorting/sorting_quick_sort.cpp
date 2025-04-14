#include<bits/stdc++.h>
using namespace std;

void  quickSort(int a[], int l, int r)
{
    int chot=a[(l+r)/2];
    int i=l, j=r;
    while (i<j)
    {
        while (a[i]<chot) ++i;
        while (a[j]>chot) --j;
        if (i<=j) 
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (i<r) quickSort(a, i, r);
    if (l<j) quickSort(a, l, j);
}

int main()
{
    system("cls");
    int n; cin>>n;
    int a[n+1];
    for (int i=0; i<n; i++) cin>>a[i];
    quickSort(a, 0, n-1);
    cout<<"Ket qua: ";
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
    return 0;
}