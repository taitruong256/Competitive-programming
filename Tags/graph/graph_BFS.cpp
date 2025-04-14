/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
vector<ll> canh[105];

void bfs(ll u)
{
    queue<ll> q;
    while (!q.empty()) q.pop();
    bool dau[105]; 
    memset(dau, false, sizeof(dau));
    q.push(1);          
    dau[1]=true;
    while (!q.empty())
    {
        ll v=q.front();        // cout<<v<<" ";
        q.pop();
        for (auto i: canh[v]) if (dau[i]==false) 
        {
            q.push(i);
            dau[i]=true;
        }
    }
}

void solve()
{
    cin>>n>>m;
    for (ll i=1; i<=m; i++)
    {
        ll u, v; cin>>u>>v;
        canh[u].push_back(v);
        canh[v].push_back(u);
    }
    // for (auto i: canh)
    // {
    //     for (auto j: i) cout<<j<<" "; cout<<endl;
    // }
    bfs(1);
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