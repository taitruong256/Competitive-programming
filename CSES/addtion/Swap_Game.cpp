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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
unordered_map<ll, ll> dist;
ll dx[]={0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 6, 7};
ll dy[]={3, 4, 5, 6, 7, 8, 1, 2, 4, 5, 7, 8};

ll convert(ll n, ll idx)
{
    string s=to_string(n);   
    swap(s[dx[idx]], s[dy[idx]]);
    ll ans=0;
    for (auto i: s) ans=(ans*10)+i-'0';
    return ans;
}

void solve()
{
    queue<ll> q;
    q.push(123456789);
    dist[123456789]=0;
    while (!q.empty())
    {
        ll s=q.front(); q.pop();
        for (ll i=0; i<12; i++) 
        {
            ll t=convert(s, i); 
            if (dist.find(t)==dist.end())
            {
                q.push(t);
                dist[t]=dist[s]+1;
            }
        }
    }

    ll s=0;
    for (ll i=0; i<9; i++)
    {
        char c; cin>>c;
        s=(s*10)+c-'0';
    }
    cout<<dist[s];
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