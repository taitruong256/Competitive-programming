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
ll n, m;
char c[1005][1005];
ll dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
string path, direct="RLDU";
bool ok=false;
map<pair<ll, ll>, pair<ll, ll>> parent;

void truyvet(ll x, ll y)
{
    while (c[x][y]!='A')
    {           // cout<<x<<" "<<y<<endl;
        if (x==parent[{x, y}].first)
        {
            if (y-1==parent[{x, y}].second) path.push_back('R');
            else path.push_back('L');
        }
        else
        {
            if (x-1==parent[{x, y}].first) path.push_back('D');
            else path.push_back('U');
        }
        pair<ll, ll> truoc=parent[{x, y}];
        x=truoc.first;
        y=truoc.second;   
    }
    reverse(path.begin(), path.end());
}

bool isvalid(ll x, ll y)
{
    if (x<1 || x>n || y<1 || y>m || c[x][y]=='#' || c[x][y]=='A') return false;
    return true;
}

void bfs(ll x, ll y)
{
    queue<pair<ll, ll>> q;
    q.push({x, y});
    while (!q.empty())
    {
        pair<ll, ll> toado=q.front(); q.pop();   
        ll tx=toado.first, ty=toado.second;      //  cout<<tx<<" "<<ty<<endl;
        for (ll i=0; i<4; i++) if (isvalid(tx+dx[i], ty+dy[i])==true)
        {
            q.push({tx+dx[i], ty+dy[i]});       
            parent[{tx+dx[i], ty+dy[i]}]=toado;
            if (c[tx+dx[i]][ty+dy[i]]=='B')
            {
                ok=true;
                truyvet(tx+dx[i], ty+dy[i]);
                return;
            }
            c[tx+dx[i]][ty+dy[i]]='#';
        }   
    }
}

void solve()
{
    cin>>n>>m;                
    for (ll i=1; i<=n; i++) 
        for (ll j=1; j<=m; j++) cin>>c[i][j];
    
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) if (c[i][j]=='A') 
        {
            bfs(i, j);
            break;
        }
    if (ok==true) 
    {
        cout<<"YES\n";
        cout<<path.size()<<endl;
        cout<<path;
    }
    else cout<<"NO";
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