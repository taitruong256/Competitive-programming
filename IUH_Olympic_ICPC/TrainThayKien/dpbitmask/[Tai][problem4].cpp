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
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll tree[4000005];
vector<pair<ll, ll>> a, b;

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        tree[id]=b[l].second;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tree[id]=max(tree[id*2], tree[id*2+1]);
}

ll query(ll id, ll l, ll r, ll u, ll v)
{          
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return tree[id];
    ll mid=(l+r)/2;
    return max(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
}

void solve()
{
    ll n, w; cin>>n>>w;
    ll weight[n+5], value[n+5];
    for (ll i=0; i<n; i++) cin>>weight[i]>>value[i];

    ll na=n/2, nb=n-na;
    
    for (ll i=0; i<(1<<na); i++)
    {
        ll sumw=0, sumv=0;
        for (ll j=0; j<na ;j++) if (i&(1<<j)) sumw+=weight[j], sumv+=value[j];
        a.push_back({sumw, sumv});
    }

    b.push_back({0, 0});
    for (ll i=0; i<(1<<nb); i++)
    {
        ll sumw=0, sumv=0;
        for (ll j=0; j<nb; j++) if (i&(1<<j)) sumw+=weight[j+na], sumv+=value[j+na];
        b.push_back({sumw, sumv});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll m=b.size();
    build(1, 1, b.size()-1);
    vector<ll> c;
    for (auto i: b) c.push_back(i.first);
    
    ll ans=0;
    for (auto i: a)
    {
        ll j=upper_bound(c.begin(), c.end(), w-i.first)-c.begin()-1;
        ll k=query(1, 1, b.size()-1, 1, j);
        ans=max(ans, i.second+k);
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}