#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    ll q; cin>>q;
    vector<ll> t(q), x(q), y(q), change(500005);
    for (ll i=0; i<500005; i++) change[i]=i;
    for (ll i=0; i<q; i++)
    {
        cin>>t[i]>>x[i];
        if (t[i]==2) cin>>y[i];
    }

    vector<ll> ans;
    for (ll i=q-1; i>=0; i--)
    {
        if (t[i]==1) ans.push_back(change[x[i]]);
        else change[x[i]]=change[y[i]];
    }
    reverse(ans.begin(), ans.end());
    for (auto it:ans) cout<<it<<" ";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
