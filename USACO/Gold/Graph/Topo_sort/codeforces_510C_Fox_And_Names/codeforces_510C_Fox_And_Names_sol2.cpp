/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, cnt, vis[30];
string name[105], ans;
vector<ll> adj[105];

bool dfs(ll u)
{
    vis[u]=1;
    for (auto v: adj[u]) 
    {
        if (vis[v]==0) dfs(v);
        if (vis[v]==1) return false;
    }
    vis[u]=2;
    ans.push_back(char(u+'a'));
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>name[i];
    for (ll i=1; i<=n-1; i++)
    {
        bool check=false;
        for (ll j=0; j<min(name[i].size(), name[i+1].size()); j++) 
            if (name[i][j]!=name[i+1][j])
            {
                adj[name[i][j]-'a'].push_back(name[i+1][j]-'a');
                check=true;
                break;
            }
        if (check==false)
        {
            if (name[i].size()>name[i+1].size())
            {
                cout<<"Impossible";
                return;
            }
        }
    }
    for (ll i=0; i<26; i++) if (vis[i]==0)
    {
        if (dfs(i)==false)
        {
            cout<<"Impossible";
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}