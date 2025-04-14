#include<bits/stdc++.h>
using namespace std;
struct toanha
{
    int toado;
    int lan;
};

bool sosanh(toanha a, toanha b)
{
    return (a.lan<b.lan);
}

void solve()
{
    int n; cin>>n;
    toanha a[n+1], b[n+1];
    for (int i=1; i<=n; i++)
    {
        a[i].toado=i;
        cin>>a[i].lan;
        b[i]=a[i];
    }
    sort(a+1, a+n+1, sosanh); // for(int i=1; i<=n; i++) cout<<a[i].lan<<" "<<a[i].toado<<endl;
    int s=0, d=1, vitri[2000005];
    for (int i=n; i>=1; i--)
    {
        s=s+2*a[i].lan*((n-i)/2+1);
        if ((n-i/2)%2==0) vitri[a[i].toado]=d; else vitri[a[i].toado]=-d;
        if ()
    }
    cout<<s<<endl;

    cout<<0<<" ";
    for (int i=1; i<=n; i++) cout<<vitri[i]<<" ";
    cout<<endl;
    return;
}

int main()
{
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

