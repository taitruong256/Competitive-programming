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
ll n, q, sq, a[100005];
struct node 
{
    ll steps, lst, to;
    node (){}
    node (ll _steps, ll _lst, ll _to){steps=_steps; lst=_lst; to=_to;}
};

struct sqrt_blocking
{
    ll n, block_size;
    vector<ll> num;
    vector<node> nxt;
    sqrt_blocking(){}
    sqrt_blocking(ll _n, vector<ll> _v)
    {
        n=_n;
        num=_v;
        block_size=ceil(sqrt(n));
        nxt.resize(n+5);
        for (ll i=n-1; i>=0; i--)
        {
            ll to=min(i+num[i], n);
            if (i/block_size<to/block_size || to>=n) nxt[i]=node(1, i, to);
            else nxt[i]=node(nxt[to].steps+1, nxt[to].lst, nxt[to].to);
        }
    }

    void update(ll pos, ll val)
    {
        num[pos]=val;
        for (ll i=pos; i>=pos/block_size*block_size; i--) 
        {
            ll to=min(i+num[i], n);
            if (i/block_size<to/block_size || to>=n) nxt[i]=node(1, i, to);
            else nxt[i]=node(nxt[to].steps+1, nxt[to].lst, nxt[to].to);
        }
    }

    pair<ll, ll> query(ll pos)
    {
        pair<ll, ll> ans={pos, 0};
        while (pos<n)
        {
            ans.first=nxt[pos].lst;
            ans.second+=nxt[pos].steps;
            pos=nxt[pos].to;
        }           
        return ans;
    }
};

void solve()
{
    cin>>n>>q;
    vector<ll> v(n);
    for (ll i=0; i<n; i++) cin>>v[i];
    sqrt_blocking sq(n, v);        
    
    while (q--)
    {
        ll type; cin>>type;
        if (type==0)
        {
            ll pos, val; cin>>pos>>val; --pos;  
            sq.update(pos, val);
        }
        else 
        {
            ll pos; cin>>pos; --pos;
            pair<ll, ll> ans=sq.query(pos);
            cout<<ans.first+1<<" "<<ans.second<<endl;
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