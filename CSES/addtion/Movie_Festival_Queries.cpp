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
const ll maxt = 1e6;
ll nxt[1000005][25];
vector<ll> time_fi[maxt+5];

void solve()
{
    ll n, q; cin>>n>>q;
    for (ll i=0; i<n; i++)
    {
        ll l, r; cin>>l>>r;
        time_fi[l].push_back(r);
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i=1; i<=maxt+1; i++)
        for (ll j=0; j<=20; j++) nxt[i][j]=maxt+1;

    for (ll i=maxt; i>=1; i--)
    {
        for (auto x: time_fi[i]) pq.push(x);
        nxt[i][0]=pq.empty()?maxt+1:pq.top();
    }

    for (ll k=1; k<=20; k++)
        for (ll i=1; i<=maxt; i++) 
            nxt[i][k]=nxt[nxt[i][k-1]][k-1];
    
    while (q--)
    {
        ll l, r; cin>>l>>r;
        ll ans=0;
        for (ll i=20; i>=0; i--)
        {
            if (nxt[l][i]<=r)
            {
                ans+=(1<<i);
                l=nxt[l][i];
            }
        }
        cout<<ans<<endl;
    }
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