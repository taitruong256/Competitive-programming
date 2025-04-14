// /*==============================================================================================================
//          __                    __                                             _____     ______    _______
//         |  |                  |  |                                           /  __ \   / _____|  / ______|     
//       __|  |__              __|  |__                                         |_|  | |  | |       | |  
//      |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
//         |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
//         |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
//         |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
//         \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
//                                                                         | |
//                                                                       __/ |
//                                                                      |___/  
//                               Nothing is impossible, only you think it is impossible                 
//                                      Try, try, try again until you succeed     
//                                         Pratice, practice, and practice
//                                        Where is your bug, delete it there
// I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
//                               You may not be the best, but must be the most effort
//                  Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
//  I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
// ==============================================================================================================*/
// #include <bits/stdc++.h>
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// //using namespace __gnu_pbds;
// #define ll long long
// //tree<ll, null_type, less<ll>, rb_tree_tag,
// //tree_order_statistics_node_update> T;             //find_by_order            order_of_key
// #define endl '\n'
// const ll mod = 1e9+7, inf = 1e9;

// void solve()
// {
//     ll n; cin>>n;
//     map<ll, vector<ll>> pos;
//     for (ll i=1; i<=n; i++) 
//     {
//         ll x; cin>>x;
//         pos[x].push_back(i);
//     }

//     ll ans=-1, mx=-1, l=1, r=1;
//     for (auto [x, v]: pos)
//     {
//         ll prev=0, s=-1e9, left=0, right=0;
//         for (auto i: v)
//         {
//             s+=prev-i+2;
//             right=prev=i;
//             if (s<=0) left=i, s=1;
//             if (s>mx) mx=s, ans=x, l=left, r=right;
//         }
//     }
//     cout<<ans<<" "<<l<<" "<<r<<endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//     freopen("_input.txt", "r", stdin);
//     freopen("_output.txt", "w", stdout);
//     #endif
//     clock_t start = clock();
//     ll t; cin>>t;
//     while (t--) solve();
//     clock_t end = clock();
//     cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
//     return 0;
// }


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

struct segment_tree
{
    struct node {ll pref, suff, sum, val;};
    ll n;
    map<ll, ll> idx;
    vector<node> tree;
    segment_tree(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        for (ll i=1; i<=4*n; i++) tree[i]={0, 0, 0, 0};
        build(1, 1, n);
    }

    node merge(node a, node b)
    {
        node c;
        c.pref=max(a.pref, a.sum+b.pref);
        c.suff=max(b.suff, b.sum+a.suff);
        c.val=max({a.val, b.val, a.suff+b.pref});
        c.sum=a.sum+b.sum;
        return c;
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r) 
        {
            tree[id]={-1, -1, -1, -1}, idx[l]=id;
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tree[id]=merge(tree[id*2], tree[id*2+1]);
    }

    void update(ll id, ll val)
    {
        tree[id]={val, val, val, val};
        id/=2;
        while (id>0)
        {
            tree[id]=merge(tree[id*2], tree[id*2+1]);
            id/=2;
        }
    }
};

void solve()
{
    ll n; cin>>n;
    map<ll, vector<ll>> pos;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        pos[x].push_back(i);
    }

    ll ans=-1e16, mx=-1e16;
    segment_tree st(n);
    for (auto [x, v]: pos)
    {
        for (auto i: v) st.update(st.idx[i], 1);
        if (st.tree[1].val>mx) mx=st.tree[1].val, ans=x; //  cout<<st.tree[1].val<<endl;
        for (auto i: v) st.update(st.idx[i], -1);
    }
    
    ll prev=0, s=-1e16, l=pos[ans][0], r=pos[ans][0], left=l, right=r;
    mx=-1e16;
    for (auto i: pos[ans])
    {
        s+=prev-i+2;
        prev=right=i;
        if (s<=0) s=1, left=i;
        if (s>mx) mx=s, l=left, r=right;
    }
    cout<<ans<<" "<<l<<" "<<r<<endl;
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