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
const int inf = 1e9;
int n, m, source, sink;
int f[1005][1005], c[1005][1005];
map<ll, vector<ll>> adj;
int ans=0;
int dist[1005], trace[1005];
bool visited[1005];

void bfs()
{
    memset(dist, -1, sizeof(dist));
    queue<int> q; q.push(source);
    dist[source]=0;
    visited[source]=true;
    while(!q.empty())
    {
        ll u=q.front(); q.pop();
        for (auto v: adj[u]) if (dist[v]==-1 && c[u][v]-f[u][v]>0)
        {
            dist[v]=dist[u]+1;
            q.push(v);
            visited[v]=true;
        }
    }
}

void dfs(int u)
{
    for (auto v: adj[u]) if (c[u][v]-f[u][v]>0 && dist[v]==dist[u]+1)
    {
        trace[v]=u;
        dfs(v);
    }
}

bool find_path(int source, int sink)
{
    memset(visited, false, sizeof(visited));
    bfs();
    return visited[sink];
}

int increase_flow(int source, int sink)
{
    int minCapacity=inf;
    dfs(source);
    int u=sink;
    while(u!=source)
    {      
        int pre=trace[u];
        minCapacity=min(minCapacity, c[pre][u]-f[pre][u]);
        u=pre;
    }           

    while (sink!=source)
    {              
        int pre=trace[sink];       //  cout<<pre<<" "; 
        f[pre][sink]+=minCapacity;
        f[sink][pre]-=minCapacity;
        sink=pre;
    }                           //   cout<<endl; cout<<"mincapacity = "<<minCapacity<<endl;  
    return minCapacity;
}

int maxflow()
{
    int ans=0;
    while (find_path(source, sink)) ans+=increase_flow(source, sink);
    return ans;
}

void solve()
{
    cin>>n>>m;
    source=1; sink=n;
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));

    for (int i=1; i<=m; i++)
    {
        int u, v, capacity; cin>>u>>v>>capacity;
        adj[u].push_back(v);
        c[u][v]=capacity;
    }    
    cout<<maxflow()<<endl;
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