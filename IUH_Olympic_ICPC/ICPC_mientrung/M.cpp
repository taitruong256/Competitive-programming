#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

void solve()
{
    ll n, m; cin>>n>>m;
    ll giaithua[100005];
    giaithua[0]=1;
    for (ll i=1; i<100005; i++) giaithua[i]=(giaithua[i-1]*i)%1000000007;
    map<ll, ll> truoc;
    for (ll i=0; i<m; i++)
    {
        ll x, y; cin>>x>>y;
        if (truoc[x]==0) truoc[y]=2;
        else
        {
            truoc[y]=truoc[x]+1;
            truoc.erase(x);
        }
    }
    ll ans=0;
    for (auto it:truoc)
    {
        //cout<<it.first<<" "<<it.second<<"\n";
        if (it.second>2) ans=(ans+giaithua[it.second])%1000000007;
    }
    cout<<ans;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
