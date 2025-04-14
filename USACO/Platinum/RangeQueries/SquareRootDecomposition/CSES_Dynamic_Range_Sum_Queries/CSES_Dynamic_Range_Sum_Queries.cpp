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
ll n, q;
vector<ll> v;

struct sqrt_blocking
{
    ll n, block_size;
    vector<ll> num, blocks;
    sqrt_blocking(){}
    sqrt_blocking(ll _n, vector<ll> _v)
    {
        n=_n;
        num=_v;
        block_size=ceil(sqrt(n));
        blocks.resize(block_size+5);
        for (ll i=0; i<n; i++) blocks[i/block_size]+=num[i];
    }
    void update(ll pos, ll val)
    {
        --pos;
        blocks[pos/block_size]-=num[pos];
        num[pos]=val;
        blocks[pos/block_size]+=num[pos];
    }
    ll query(ll pos)
    {
        ll sum=0;
        --pos;
        for (ll i=0; i<pos/block_size; i++) sum+=blocks[i];
        for (ll i=pos/block_size*block_size; i<=pos; i++) sum+=num[i];
        return sum;
    }
    ll query(ll l, ll r)
    {
        return query(r)-query(l-1);
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        v.push_back(x);
    }
    sqrt_blocking sq(n, v);  
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll pos, val; cin>>pos>>val;
            sq.update(pos, val);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<sq.query(l, r)<<endl;
        }
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