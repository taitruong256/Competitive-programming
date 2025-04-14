#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n, a, b; cin>>n>>a>>b;
    ll x[100005];
    if (abs(a-b)>1) 
    {
        cout<<-1<<"\n";
        return;
    }
    else if (a+b>2*n)
    {
        cout<<-1<<"\n";
        return;
    }
    ll cuctieu, cucdai;
    if (n%2==0) cuctieu=cucdai=n/2-1;
    else cuctieu=n/2, cucdai=n/2-1;
    if (max(a, b)>max(cuctieu, cucdai))
    {
        cout<<-1<<"\n";
        return;
    }
    for (ll i=1; i<=n; i++) x[i]=0;
    if (a>b)
    {
        x[1]=1;
        x[n]=2;
        ll ind=2, r=n;
        for (ll i=1; i<=a; i++)
        {
            x[ind]=r;
            --r;
            ind+=2;
        }
        ind=3;
        ll l=3;
        for (ll i=1; i<=b; i++)
        {
            x[ind]=l;
            ++l;
            ind+=2;
        }
        for (int i=1; i<=n; i++) if (x[i]==0)
        {
            x[i]=r;
            --r;
        }
    }
    else if (a<b)
    {
        ll ind=2, l=1;
        for (ll i=1; i<=a; i++)
        {
            x[ind]=l;
            ++l;
            ind+=2;
        }
        ind=3;
        ll r=n;
        for (ll i=1; i<=b; i++)
        {
            x[ind]=r;
            --r;
            ind+=2;
        }
        x[1]=r; --r;
        for (ll i=1; i<=n; i++) if (x[i]==0)
        {
            x[i]=r;
            --r;
        }
    }
    else
    {
        ll ind=1, l=1;
        for (ll i=1; i<=a+1; i++)
        {
            x[ind]=l;
            ++l;
            ind+=2;
        }
        ind=2;
        ll r=n/2+1;
        for (ll i=1; i<=b+1; i++)
        {
            x[ind]=r;
            ++r;
            ind+=2;
        }
    }
    for (ll i=1; i<=n; i++) cout<<x[i]<<" ";
    cout<<"\n";
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t; 
    while (t--) solve();
    return 0;
}
