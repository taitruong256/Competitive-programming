#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, pos, d;
pair<ll, ll> a[1005];
bool vis[1005];

ll khoangcach(pair<ll, ll> a, pair<ll, ll> b)
{
    ll dx=(a.first-b.first)*(a.first-b.first);
    ll dy=(a.second-b.second)*(a.second-b.second);
    return dx+dy;
}

void solve()
{
    cin>>n>>pos>>d;
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;

    vector<ll> f1, f2;
    vis[pos]=true;
    for (ll i=1; i<=n; i++) if (vis[i]==false && khoangcach(a[i], a[pos])<=d)
    {
        f1.push_back(i);
        vis[i]=true;
    }
    for (ll i=0; i<f1.size(); i++)
    {
        for (ll j=1; j<=n; j++) if (vis[j]==false && khoangcach(a[f1[i]], a[j])<=d)
        {
            f2.push_back(j);
            vis[j]=true;
        }
    }
    cout<<f1.size()<<" "<<f2.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
