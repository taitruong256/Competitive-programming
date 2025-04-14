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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll minprime[1000009];
map<ll, ll> cnt;

void phantich(ll n)
{
    while (n>1)
    {
        ll x=minprime[n];
        while (n%x==0) ++cnt[x], n/=x;
    }
}

ll so_uoc(ll m, ll power)
{
    cnt.clear();
    phantich(m);
    phantich(m+1);
    phantich(m+2);
    if (power==2)
    {
        phantich(m);
        phantich(m+1);
        phantich(m+2);
    }
    ll p=1;
    for (auto it: cnt) p=p*(it.second+1);
    return p;
}

void solve()
{
    ll m; cin>>m;
    ll d1=so_uoc(m, 1);
    ll d2=so_uoc(m, 2);
    cout<<(d2+1)/2-d1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    memset(minprime, 0, sizeof(minprime));
    for (ll i=2; i*i<=1000005; i++) if (minprime[i]==0)
        for (ll j=i; j<=1000005; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=1; i<=1000005; i++) if (minprime[i]==0) minprime[i]=i;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}