#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define cint int t; cin >> t; while(t--)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll r, c;
bitset<128> oc, ocdao, bulong[2005], val;
bool vis[2005][205];
bool ans=false;

bitset<128> xoay(bitset<128> x, bool xoaytrai)
{
    if (xoaytrai==true)
    {
        bool bit=x[1];
        x=(x>>1);
        if (bit==true) x.set(0, 0), x.set(c, 1);
        return x;
    }
    bool bit=x[c];
    x=(x<<1);
    if (bit==true) x.set(c+1, 0), x.set(1, 1);
    return x;
}

void bfs(bool dao)
{
    queue<tuple<ll, bitset<128>, ll>> q;
    for (ll i=0; i<=r; i++)
        for (ll j=0; j<=100; j++) vis[i][j]=0;
    if (dao==false) q.push({0, oc, 0});
    else q.push({0, ocdao, 0});
    vis[0][0]=true;
    while (!q.empty())
    {
        auto [i, x, l]=q.front(); q.pop();
        // cout<<i<<" "<<l<<" "<<x<<endl;
        if (i==r) 
        {
            ans=true;
            return;
        }
        if ((bulong[i]&xoay(x, true))==0 && vis[i][(l-1+c)%c]==false) 
        {
            vis[i][(l-1+c)%c]=true;
            q.push({i, xoay(x, true), (l-1+c)%c});
        }
        if ((bulong[i]&xoay(x, false))==0 && vis[i][(l+1+c)%c]==false) 
        {
            vis[i][(l+1+c)%c]=true;
            q.push({i, xoay(x, false), (l+1+c)%c});
        }
        if (i>=1 && (bulong[i-1]&x)==0 && vis[i-1][l]==false) 
        {
            vis[i-1][l]=true;
            q.push({i-1, x, l});
        }
        if ((bulong[i+1]&x)==0 && vis[i+1][l]==false) 
        {
            vis[i+1][l]=true;
            q.push({i+1, x, l});
        }
    }
}

void solve() {

    cin>>r>>c;
    string s; cin>>s; s=" "+s;
    for (ll j=1; j<=c; j++) if (s[j]=='1') oc.set(j, 1);
    for (ll j=1; j<=c; j++) if (s[c-j+1]=='1') ocdao.set(j, 1);

    for (ll i=1; i<=r; i++)
    {
        string s; cin>>s; s=" "+s;
        for (ll j=1; j<=c; j++) if (s[j]=='1') bulong[i].set(j, 1);
    }

    bfs(0);
    bfs(1);
    if (ans==true) cout<<"Y";
    else cout<<"N";
}
signed main () {
    ios
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}