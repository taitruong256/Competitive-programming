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
ll n, m, xs, ys;
char c[1005][1005];
ll dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
map<pair<ll, ll>, pair<ll, ll>> truoc;
vector<pair<ll, ll>> ans;
string res;

bool isvalid(ll x, ll y)
{
    if (x<1 || x>n || y<1 || y>m || c[x][y]=='#') return false;
    return true;
}

char huong(ll x, ll y, ll truocx, ll truocy)
{
    if (x==truocx)
    {
        if (y-1==truocy) return 'R';
        else return 'L';
    }
    else
    {
        if (x-1==truocx) return 'D';
        else return 'U';
    }
}

void truyvet(ll x, ll y, ll xs, ll ys)
{
    if (x==xs && y==ys) return;
    truyvet(truoc[{x, y}].first, truoc[{x, y}].second, xs, ys);
    res.push_back(huong(x, y, truoc[{x, y}].first, truoc[{x, y}].second));
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>c[i][j];
    
    queue<pair<ll, ll>> q;
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) if (c[i][j]=='A') q.push({i, j}), xs=i, ys=j;
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) if (c[i][j]=='M') q.push({i, j});

    while (!q.empty())
    {
        pair<ll, ll> dinh=q.front(); q.pop();
        ll x=dinh.first, y=dinh.second;
        if (c[x][y]=='A')
        {
            if (x==1 || x==n || y==1 || y==m)
            {
                cout<<"YES\n";
                truyvet(x, y, xs, ys);
                for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
                cout<<res.size()<<endl;
                cout<<res;
                return;
            }
            for (ll i=0; i<4; i++)
            {
                ll xx=x+dx[i], yy=y+dy[i];
                if (isvalid(xx, yy)==true && c[xx][yy]!='M' && c[xx][yy]!='A')
                {
                    c[xx][yy]='A';
                    truoc[{xx, yy}]={x, y};
                    q.push({xx, yy});
                }
            }
        }
        else if (c[x][y]=='M')
        {
            for (ll i=0; i<4; i++)
            {
                ll xx=x+dx[i], yy=y+dy[i];
                if (isvalid(xx, yy)==true && c[xx][yy]!='M')
                {
                    c[xx][yy]='M';
                    q.push({xx, yy});
                }
            }
        }

    }
    cout<<"NO";
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