#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, w; cin>>n>>w;
    multiset<ll> ms;
    for (ll i=1; i<=n; i++) 
    {
        ll x; cin>>x;
        ms.insert(x);
    }

    ll height=1, width=w;
    while (!ms.empty())
    {
        auto t=ms.upper_bound(width);
        if (t!=ms.begin())
        {
            --t;
            width-=*t;
            //cout<<*t<<" ";
            ms.erase(t);
        }
        else
        {
            width=w;
            ++height;
        }
    }
    cout<<height<<"\n";
}

int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
