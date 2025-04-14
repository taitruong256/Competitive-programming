/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
ll n;
ll d[505][505], trace[505][505], w[505][505];

void floyd()
{
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) trace[i][j]=i;

    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) d[i][j]=w[i][j];

    for (ll k=0; k<n; k++)
        for (ll i=0; i<n; i++)
            for (ll j=0; j<n; j++) 
                if (d[i][k]<INF && d[k][j]<INF && d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    trace[i][j]=trace[k][j];
                }
}

vector<ll> truyvet(ll u, ll v)
{
    vector<ll> path;
    while (v!=u)
    {
        path.push_back(v);
        v=trace[u][v];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) w[i][j]=INF;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++) cin>>w[i][j];
    floyd();
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<n; j++) cout<<d[i][j]<<" ";
        cout<<endl;
    }

    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<n; j++) 
        {
            vector<ll> p=truyvet(i, j);
            cout<<i<<" "<<j<<"    ";
            for (auto it: p) cout<<it<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
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