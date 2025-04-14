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
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7, inf = 1e9;
ll n, q, a[300005], cnt[1000005], ans, res[200005];
ll block_size=200;
struct qry
{
    ll left, right, idx;
};
qry query[200005];

bool comp(qry a, qry b)
{
    --a.left;
    --b.left;
    if (a.left/block_size==b.left/block_size) return a.right<b.right;
    return a.left/block_size<b.left/block_size;
}

void add(ll pos)
{
    cnt[a[pos]]++;
    if (cnt[a[pos]]==1) ++ans;
}

void remove(ll pos)
{
    cnt[a[pos]]--;
    if (cnt[a[pos]]==0) --ans;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=1000000; i++) cnt[i]=0;
    cin>>q;
    for (ll i=1; i<=q; i++) cin>>query[i].left>>query[i].right, query[i].idx=i;
    sort(query+1, query+q+1, comp);
    ll st=1, fi=0;
    for (ll i=1; i<=q; i++)
    {
        while (st<query[i].left) remove(st++);
        while (st>query[i].left) add(--st);
        while (fi<query[i].right) add(++fi);
        while (fi>query[i].right) remove(fi--);    
        res[query[i].idx]=ans;
    }   
    for (ll i=1; i<=q; i++) cout<<res[i]<<endl;
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