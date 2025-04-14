/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll vis[10][10];
// pair<ll, ll> d[]={{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
const ll dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const ll dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool exist=false;

bool isvalid(ll i, ll j)
{
    return 1 <= i && i <= 8 && 1 <= j && j <= 8 && !vis[i][j];
}

ll deg(ll x, ll y)
{
    ll cnt=0;
    for (ll i=0; i<8; i++) 
        if (isvalid(x+dx[i], y+dy[i])==true) ++cnt;
    return cnt;
}

void print_kq()
{
    for (ll i=1; i<=8; i++)
    {
        for (ll j=1; j<=8; j++) printf("%lld ", vis[i][j]);
        printf("\n");
    }
}

void dq(ll x, ll y, ll cnt)
{
    vis[x][y]=cnt;
    if (cnt==64)
    {
        print_kq();
        exit(0);
    }
    vector<tuple<ll, ll, ll>> pos;
    for (ll i=0; i<8; i++) if (isvalid(x+dx[i], y+dy[i])==true) 
        pos.push_back({deg(x+dx[i], y+dy[i]), x+dx[i], y+dy[i]});
    sort(pos.begin(), pos.end());
    for (auto it: pos) 
    {
        ll a, b, c;
        tie(a, b, c)=it;
        dq(b, c, cnt+1);
    }
    vis[x][y]=0;
}

void solve()
{
    ll x, y; cin>>x>>y;
    memset(vis, 0, sizeof(vis));
    for (ll i=1; i<=8; i++)
        for (ll j=1; j<=8; j++) vis[i][j]=0;
    dq(y, x, 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}