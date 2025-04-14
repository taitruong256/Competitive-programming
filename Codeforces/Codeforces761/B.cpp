#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nt[100]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

ll ucln(ll a, ll b)
{
    while (a%b!=0)
    {
        ll r=a%b;
        a=b;
        b=r;
    }
    return b;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=0; i<25; i++) if (ucln(n-1-nt[i], nt[i])==1)
    {
        cout<<n-1-nt[i]<<" "<<nt[i]<<" "<<1<<"\n";
        return;
    }
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
