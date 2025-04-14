#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll k, n, m; cin>>k>>n>>m;
    ll a[n+1], b[m+1];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<m; i++) cin>>b[i];
    ll i=0, j=0;
    a[n]=1000000000, b[m]=1000000000;
    vector<ll> v;
    for (ll l=0; l<n+m; l++)
    {
        if (a[i]==0) 
        {
            ++k;
            v.push_back(a[i]);
            ++i;
        }
        else if (b[j]==0) 
        {
            ++k;
            v.push_back(b[j]);
            ++j;
        }
        else if (a[i]<=k)
        {
            v.push_back(a[i]);
            ++i;
        } 
        else if (b[j]<=k)
        {
            v.push_back(b[j]);
            ++j;
        }
        else
        {
            cout<<-1<<"\n";
            return;
        }
    }
    for (auto it:v) cout<<it<<" "; cout<<"\n";
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
