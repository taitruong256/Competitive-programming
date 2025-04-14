#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define point pair<ll, ll>
#define x first
#define y second

ll huong(point p1, point p2, point p3)
{
    ll a=p1.y-p2.y;
    ll b=p2.x-p1.x;
    ll c=-(a*p1.x+b*p1.y);
    ll d=a*p3.x+b*p3.y+c;
    if (d<0) d=-1;
    if (d>0) d=1;
    return d;
}

void solve()
{
    ll n, m; cin>>n>>m;
    point a[m+5];
    vector<point> dagiac[n+5];
    vector<ll> nguoi(n+5);
    for (ll i=1; i<=m; i++) cin>>a[i].x>>a[i].y;
    for (ll i=1; i<=n; i++)
    {
        ll p; cin>>p;
        for (ll j=0; j<p; j++)
        {
            ll x, y; cin>>x>>y;
            dagiac[i].push_back({x, y});
        }
        dagiac[i].push_back(dagiac[i][0]);
    }
    for (ll i=1; i<=m; i++)
        for (ll j=1; j<=n; j++)
        {
            ll h=huong(dagiac[j][0], dagiac[j][1], a[i]);
            bool check=true;
            for (ll k=1; k<dagiac[j].size()-1; k++) if (huong(dagiac[j][k], dagiac[j][k+1], a[i])!=h) check=false;
            for (ll k=1; k<dagiac[j].size()-1; k++) if (huong(dagiac[j][k], dagiac[j][k+1], a[i])==0) check=true;
            if (check==true)
            {
                ++nguoi[j];
                break;
            }
        }
    ll ans=0;
    for (ll i=1; i<=n; i++) ans=max(ans, nguoi[i]);
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    solve();
    return 0;
}
