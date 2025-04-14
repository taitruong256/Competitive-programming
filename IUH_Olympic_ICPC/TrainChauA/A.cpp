#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n*n+5];
    map<ll, ll> cnt;
    for (ll i=1; i<=n*n; i++) cin>>a[i];
    for (ll i=1; i<=n*n; i++) ++cnt[a[i]];

    vector<pair<ll, ll>> v;
    for (auto it: cnt) v.push_back({it.second, it.first});
    sort(v.begin(), v.end());
    for (auto it: v) cout<<it.first<<" "<<it.second<<endl;

    ll vt=0;
    ll ans[n*n+5];
    memset(ans, 0, sizeof(ans));
    for (ll i=1; i<=n; i++)
    {
        if (v[vt].first>=n)
        {
            ll d=n;
            for (ll j=1; j<=n*n; j++) if (d>0 && ans[j]==0 && a[j]==v[vt].second)
            {
                --d;
                ans[j]=v[vt].second;
                //cout<<ans[j]<<" ";
            }
            v[vt].first-=n;
            if (v[vt].first==0) ++vt;
        }
        else if (v[vt].first>0 && v[vt].first<n)
        {             cout<<v[vt].first<<endl;
            ll d=v[vt].first;
            for (ll j=1; j<=n*n; j++) if (d>0 && ans[j]==0 && a[j]==v[vt].second)
            {
                --d;
                ans[j]=v[vt].second;
                //cout<<ans[j]<<" ";
            }
            d=n-v[vt].first;
            v[vt].first=0;
            ++vt;
            ll t=d;
            for (ll j=0; j<v.size(); j++) if (v[j].first>=d)
            {
                bool check=false;
                for (ll k=1; k<=n*n; k++) if (check==false && d>0 && ans[j]==0 && a[j]==v[vt].second)
                {
                    check=true;
                    --d;
                    ans[k]=v[j].second;
                    //cout<<ans[j]<<" ";
                }
                v[j].first-=t;
            }
        }
        for (auto it: v) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
    }

    cout<<"YES\n";
    for (ll i=1; i<=n*n; i++) cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    solve();
    return 0;
}
