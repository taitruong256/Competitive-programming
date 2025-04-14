#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, vb, vs;
    cin>>n>>vb>>vs;
    int a[100001];
    for (int i=0; i<n; i++) cin>>a[i];
    int xu, yu;
    cin>>xu>>yu;
    float min=10000000, kq=0;;
    for (int i=0; i<n; i++)
    {
        float d=sqrt((xu-a[i])*(xu-a[i])+yu*yu);
        if (d<min) kq=i;
    }
    cout<<kq+1;
    return 0;
}
