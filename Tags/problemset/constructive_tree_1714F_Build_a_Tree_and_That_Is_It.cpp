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
vector<pair<ll, ll>> tree;
ll n, d12, d23, d31, cur;

void make_path(ll u, ll v, ll len)
{
    ll nxt=u;
    for (ll i=0; i<len-1; i++) 
    {
        tree.push_back({nxt, cur});
        nxt=cur;
        ++cur;
    }
    if (len>0 && v!=n) tree.push_back({nxt, v});
}

void solve()
{
    ll n, d12, d23, d31; cin>>n>>d12>>d23>>d31;   
    tree.clear();

    if (d12+d23==d31)
    {
        cur=4;
        make_path(1, 2, d12);
        make_path(2, 3, d23);
        for (ll i=cur; i<=n; i++) tree.push_back({1, i});
    }
    else if (d23+d31==d12)
    {
        cur=4;
        make_path(2, 3, d23);
        make_path(3, 1, d31);
        for (ll i=cur; i<=n; i++) tree.push_back({1, i});
    }
    else if (d12+d31==d23)
    {
        cur=4;
        make_path(2, 1, d12);
        make_path(1, 3, d31);
        for (ll i=cur; i<=n; i++) tree.push_back({1, i});
    }
    else if ((d12+d23+d31)<=2*(n-1))
    {
        // d12 + d23 + d31 = (d14 + d42) + (d24 + d43) + (d34 + d41)
        ll lca14=(d12+d31-d23);
        ll lca24=(d12+d23-d31);
        ll lca34=(d23+d31-d12);
        if (lca14<0 || lca24<0 || lca34<0 || lca14%2==1 || lca24%2==1 || lca34%2==1)
        {
            cout<<"NO\n";
            return;
        }
        lca14/=2;
        lca24/=2;
        lca34/=2;    
        cur=5;
        make_path(1, 4, lca14);
        make_path(2, 4, lca24);
        make_path(3, 4, lca34);               
        for (ll i=cur; i<=n; i++) tree.push_back({1, i});
    }
    else
    {
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    for (auto [x, y]: tree) cout<<x<<" "<<y<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}