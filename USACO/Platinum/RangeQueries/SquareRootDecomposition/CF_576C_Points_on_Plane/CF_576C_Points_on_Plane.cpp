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

struct Mo
{
    ll l, r, id, block_size;
    Mo(){}
    Mo(ll _l, ll _r, ll _id, ll _n)
    {
        l=_l;
        r=_r;
        id=_id;
        block_size=ceil(sqrt(_n));
    }
    bool operator< (Mo other)
    {
        if (l/block_size!=other.l/block_size) return l/block_size<other.l/block_size;
        if (l/block_size%2==1) return r<other.r;
        return r>other.r;
    }
};

ll dist(Mo a, Mo b)
{
    return abs(a.l-b.l)+abs(a.r-b.r);
}

void solve()
{
    ll n; cin>>n;
    vector<Mo> v;
    for (ll i=1; i<=n; i++)
    {
        ll l, r; cin>>l>>r;
        Mo mo(l, r, i, 1e6);
        v.push_back(mo);
    }
    sort(v.begin(), v.end());
    ll ans=0;
    for (ll i=1; i<n; i++) ans+=dist(v[i-1], v[i]);
    assert(ans<=1e9);
    for (auto i: v) cout<<i.id<<" ";
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