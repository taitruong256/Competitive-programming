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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, a[200005], deg[200005], s[200005];
string st;
vector<ll> ans;

void solve()
{
    cin>>n;
    cin>>st; st=" "+st; cout<<st<<endl;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        ++deg[a[i]];
        s[i]=st[i]-'0';
    }
    for (ll i=1; i<=n; i++) cout<<s[i]<<" "; cout<<endl;
    queue<ll> q;
    for (ll i=1; i<=n; i++) if (deg[i]==0) q.push(i);
    while (!q.empty())
    {
        ll u=q.front(); q.pop();
        ll v=s[u];
        if (s[u]==1) 
        {
            s[u]=!s[u];
            s[v]=!s[v];
            ans.push_back(u);
        } 
        --deg[v];
        if (deg[v]==0) q.push(v);
    }

    vector<ll> vis(n+5, false);
    for (ll i=1; i<=n; i++) if (vis[i]==false && s[i]==1)
    {
        vector<ll> cycle;
        ll u=i, sum=0;
        while (vis[a[u]]==false) 
        {
            vis[u]=true;
            cycle.push_back(u);
            sum+=s[u];
            u=a[u];
        }
        for (auto x: cycle) cout<<x<<" "; cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}