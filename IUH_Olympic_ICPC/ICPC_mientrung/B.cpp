#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

void solve()
{
    ll n; cin>>n;
    ll a[n+1];
    ll gtmax=-10000000005;
    ll p=1, d1=0, d2=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]%=mod;
        if (a[i]==0) ++d1;
        else
        {
            if (a[i]<0)
            {
                ++d2;
                if (a[i]>gtmax) gtmax=a[i];
            }
            p=(p*a[i])%mod;
        }
    }
    if (d1>1) cout<<0;
    else if (d1==1)
    {
        if (d2%2==0) cout<<p;
        else cout<<0;
    }
    else 
    {
        if (d2%2==0) cout<<p;
        else cout<<p/gtmax;
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
