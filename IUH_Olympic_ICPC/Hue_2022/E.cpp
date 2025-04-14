/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll minprime[100005], a[100005];
ll n, m;
bool ans[100005];
vector<ll> res;

void solve()
{
    memset(ans, true, sizeof(ans));
    memset(minprime, 0, sizeof(minprime));
    cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>a[i];

    minprime[1]=1;
    for (ll i=2; i*i<=100000; i++) if (minprime[i]==0)
        for (ll j=i; j<=100000; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=1; i<=100000; i++) if (minprime[i]==0) minprime[i]=i;
    
    set<ll> uoc;
    for (ll i=1; i<=n; i++)
    {
        while (a[i]>1)
        {
            uoc.insert(minprime[a[i]]);
            a[i]/=minprime[a[i]];
        }
        if (a[i]>1) uoc.insert(a[i]);
    }
    // for (auto i: uoc) cout<<i<<" "; cout<<endl;
    for (auto i: uoc)
        for (ll j=i; j<=100000; j+=i) ans[j]=false;

    for (ll i=1; i<=m; i++) if (ans[i]==true) res.push_back(i);
    cout<<res.size()<<endl;
    for (auto i: res) cout<<i<<endl;
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