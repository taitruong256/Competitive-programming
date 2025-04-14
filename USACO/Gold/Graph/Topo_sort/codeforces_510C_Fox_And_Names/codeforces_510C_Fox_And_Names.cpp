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
ll n, deg[30], cnt;
string name[105];
vector<ll> adj[30];

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>name[i];
    for (ll i=1; i<=n-1; i++)
    {
        bool check=false;
        for (ll j=0; j<min(name[i].size(), name[i+1].size()); j++)
        {
            if (name[i][j]!=name[i+1][j])
            {
                check=true;
                adj[name[i][j]-'a'].push_back(name[i+1][j]-'a');
                ++deg[name[i+1][j]-'a'];
                break;
            }
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
    queue<ll> q;
    string ans;
    for (ll i=0; i<26; i++) if (deg[i]==0) q.push(i);
    while (!q.empty())
    {
        ++cnt;
        ll u=q.front(); q.pop();
        ans.push_back(char(u+'a'));
        for (auto v: adj[u])
        {
            --deg[v];
            if (deg[v]==0) q.push(v);
        }
    }
    if (cnt<26) 
    {
        cout<<"Impossible";
        return;
    }
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