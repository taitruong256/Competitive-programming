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
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll int
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7, inf = 1e9;
const ll maxn=2e5+5, block_size=600;
ll n, q, block, a[maxn], lazy[maxn/block_size+5][maxn]; 

void init()
{
    for (ll i=0; i<block; i++) 
        for (ll j=1; j<=100; j++) lazy[i][j]=j;
}

void do_lazy(ll id)
{
    ll l=id*block_size;
    ll r=min((id+1)*block_size-1, n-1);
    for (ll i=l; i<=r; i++) a[i]=lazy[id][a[i]];         
    for (ll i=1; i<=100; i++) lazy[id][i]=i;
}

void update_block(ll l, ll r, ll oldval, ll newval)
{                            
    ll id=r/block_size;
    do_lazy(id);
    for (ll i=l; i<=r; i++) if (a[i]==oldval) a[i]=newval;
}

void update(ll l, ll r, ll oldval, ll newval)
{
    ll blockL=l/block_size;
    ll blockR=r/block_size;
    if (blockL==blockR) 
    { 
        update_block(l, r, oldval, newval);
        return;
    }
    for (ll i=blockL+1; i<blockR; i++)
        for (ll j=1; j<=100; j++) if (lazy[i][j]==oldval) lazy[i][j]=newval;
    update_block(l, (blockL+1)*block_size-1, oldval, newval);
    update_block(blockR*block_size, r, oldval, newval);
}

void solve()
{
    cin>>n;                         
    block=(n+block_size-1)/block_size;
    for (ll i=0; i<n; i++) cin>>a[i];
    init();
    cin>>q;
    while (q--)
    {
        ll l, r, oldval, newval; cin>>l>>r>>oldval>>newval;
        --l; --r;
        update(l, r, oldval, newval);
    }
    for (ll i=0; i<block; i++) do_lazy(i);         
    for (ll i=0; i<n; i++) cout<<a[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}