#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k=0; cin>>n;
    bool dau[100005];
    for (ll i=1; i<=n; i++) dau[i]=false;
    vector<ll> v;
    for (ll i=1; i<=n; i++) 
    {
        ll x; cin>>x;
        if (x<=n && dau[x]==false) dau[x]=true;
        else v.push_back(x);
    }
    ll ans=0, j=0;
    sort(v.begin(), v.end());   //for (ll i=0; i<v.size(); i++) cout<<v[i]<<" ";
    for (ll i=1; i<=n; i++) if (dau[i]==false)
    {
        if (v[j]>i*2) ++ans;
        else
        {
            cout<<-1<<"\n";
            return;
        }
        ++j;
    }
    cout<<ans<<"\n";
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
