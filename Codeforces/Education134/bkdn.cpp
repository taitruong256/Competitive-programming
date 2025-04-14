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
const ll mod = 1e9+7, inf = 1e16;
vector<bool> khoitao;
struct Node
{
    ll left, right, sum;
    vector<bool> ke;
    Node() {}
    Node(ll _left, ll _right, ll _sum, vector<bool> _s)
    {
        left=_left;
        right=_right;
        sum=_sum;
        ke=_s;
    }
} tree[200005];
ll n, m, q, cur, nNode=0, nVer=0, ver[100005];

void pull(ll cur)
{
    tree[cur].sum=tree[tree[cur].left].sum+tree[tree[cur].right].sum;
}

ll build(ll l, ll r)
{                  
    if (l==r)
    {
        ++nNode;
        tree[nNode]=Node(l, r, 0, khoitao);
        return nNode;
    }
    ll mid=(l+r)/2; 
    ll cur=++nNode;
    tree[cur].left=build(l, mid);
    tree[cur].right=build(mid+1, r);
    pull(cur);
    return cur;
}

ll update(ll l, ll r, ll x, ll y, bool val, ll old, bool daobit)
{
    if (l==r)
    {
        vector<bool> s=tree[old].ke;
        ll cnt=tree[old].sum;
        if (daobit==true)
        {
            cnt=0;
            for (ll i=1; i<=m; i++)
            {
                if (s[i]==0) ++cnt, s[i]=1;
                else s[i]=0;
            }
        }
        else
        {
            if (s[y]==0 && val==1) ++cnt, s[y]=1;
            if (s[y]==1 && val==0) --cnt, s[y]=0;
        }
        ++nNode;
        tree[nNode]=Node(l, r, cnt, s);
        return nNode;
    }
    ll mid=(l+r)/2;
    ll cur=++nNode;
    if (x<=mid)
    {
        tree[cur].left=update(l, mid, x, y, val, tree[old].left, daobit);
        tree[cur].right=tree[old].right;
        pull(cur);
    }
    else 
    {   
        tree[cur].left=tree[old].left;
        tree[cur].right=update(mid+1, r, x, y, val, tree[old].right, daobit);
        pull(cur);
    }
    return cur;
}

void solve()
{
    cin>>n>>m>>q;
    for (ll i=1; i<=m+1; i++) khoitao.push_back(0);
    ver[nVer]=1;
    build(1, n);


    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll x, y; cin>>x>>y;
            ll cur=nNode+1;
            update(1, n, x, y, 1, ver[nVer], false);
            ++nVer;
            ver[nVer]=cur;
            cout<<tree[ver[nVer]].sum<<endl;
        }
        else if (type==2)
        {
            ll x, y; cin>>x>>y;
            ll cur=nNode+1;
            update(1, n, x, y, 0, ver[nVer], false);
            ++nVer;
            ver[nVer]=cur;
            cout<<tree[ver[nVer]].sum<<endl;
        }
        else if (type==3) 
        {
            ll x; cin>>x;
            ll cur=nNode+1;
            update(1, n, x, 0, 0, ver[nVer], true);
            ++nVer;
            ver[nVer]=cur;
            cout<<tree[ver[nVer]].sum<<endl;
        }
        else 
        {
            ll k; cin>>k;
            nVer=k;
            cout<<tree[ver[nVer]].sum<<endl;
            nNode=ver[nVer]+12;
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
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}