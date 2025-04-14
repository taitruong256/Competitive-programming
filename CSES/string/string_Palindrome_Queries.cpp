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
const ll maxn = 2e5+5;
const ll base = 31;
ll n, m, power[maxn];
string s;

struct fenwick
{
    ll bit[maxn]={0};

    void update(ll idx, ll val)
    {
        val=(val+mod*mod)%mod;
        for (ll i=idx; i<maxn; i+=-i&i) bit[i]=(bit[i]+val)%mod;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum=(sum+bit[i])%mod;
        return sum;
    }
} pref, suff;


void solve()
{
    cin>>n>>m;
    cin>>s;
    s=" "+s;       
    power[0]=1;
    for (ll i=1; i<maxn; i++) power[i]=(power[i-1]*base)%mod;
    for (ll i=1; i<=n; i++) 
    {
        pref.update(i, (s[i]-'a'+1)*power[i-1]);
        suff.update(i, (s[i]-'a'+1)*power[n-i]);
    }

    while (m--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            char c;
            ll k;  
            cin>>k>>c;            
            pref.update(k, -(s[k]-'a'+1)*power[k-1]);
            pref.update(k, (c-'a'+1)*power[k-1]);
            suff.update(k, -(s[k]-'a'+1)*power[n-k]);
            suff.update(k, (c-'a'+1)*power[n-k]);
            s[k]=c; 
        }
        else 
        {
            ll l, r; cin>>l>>r;       
            ll h1=(pref.query((l+r)/2)-pref.query(l-1)+mod)%mod;
            ll m1=power[l-1];
            ll h2=(suff.query(r)-suff.query((l+r-1)/2)+mod)%mod;
            ll m2=power[n-r];
            if ((h1*m2)%mod==(h2*m1)%mod) cout<<"YES\n";
            else cout<<"NO\n";
        }
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