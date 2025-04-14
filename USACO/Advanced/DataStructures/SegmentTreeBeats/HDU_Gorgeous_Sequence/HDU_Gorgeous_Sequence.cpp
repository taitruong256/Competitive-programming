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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;
ll n, q, a[100005];

struct segment_tree_beats
{
    struct node {ll mx1, mx2, mxc, mn1, mn2, mnc, sum, lazy;};
    vector<node> tree;
    ll n;

    segment_tree_beats(){}
    segment_tree_beats(ll _n)
    {
        n=_n;
        tree.resize(4*n+5);
        build(1, 1, n);
    }

    node merge(ll id)
    {
        node &new_node=tree[id];
        node &a=tree[id*2];
        node &b=tree[id*2+1];
        if (a.mx1==b.mx1)
        {
            new_node.mx1=a.mx1;
            new_node.mx2=max(a.mx2, b.mx2);
            new_node.mxc=a.mxc+b.mxc;
        }
        else if (a.mx1>b.mx1) 
        {
            new_node.mx1=a.mx1;
            new_node.mx2=max(a.mx2, b.mx1);
            new_node.mxc=a.mxc;
        }
        else 
        {
            new_node.mx1=b.mx1;
            new_node.mx2=max(a.mx1, b.mx2);
            new_node.mxc=b.mxc;
        }

        if (a.mn1==b.mn1)
        {
            new_node.mn1=a.mn1;
            new_node.mn2=min(a.mn2, b.mn2);
            new_node.mnc=a.mnc+b.mnc;
        }
        else if (a.mn1<b.mn1) 
        {
            new_node.mn1=a.mn1;
            new_node.mn2=min(a.mn2, b.mn1);
            new_node.mnc=a.mnc;
        }
        else 
        {
            new_node.mn1=b.mn1;
            new_node.mn2=min(a.mn1, b.mn2);
            new_node.mnc=b.mnc;
        }
        new_node.sum=a.sum+b.sum;
        return new_node;
    }

    void build(ll id, ll l, ll r)
    {
        if (l==r)
        {
            tree[id]={a[l], LLONG_MIN, 1, a[l], LLONG_MAX, 1, a[l], 0};
            return;
        }
        ll mid=(l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        merge(id);
    }

    void push_add(ll id, ll l, ll r, ll val)
    {
        if (val==0) return;
        tree[id].mx1+=val;
        if (tree[id].mx2!=LLONG_MIN) tree[id].mx2+=val;
        tree[id].mn1+=val;
        if (tree[id].mn2!=LLONG_MAX) tree[id].mn2+=val;
        tree[id].sum+=val*(r-l+1);
        tree[id].lazy+=val;
    }

    void push_max(ll id, ll l, ll r, ll val)
    {
        if (val>tree[id].mx1) return;
        tree[id].sum-=tree[id].mx1*tree[id].mxc;
        tree[id].mx1=val;
        tree[id].sum+=tree[id].mx1*tree[id].mxc;
        if (l==r) 
            tree[id].mn1=val;
        else if (val<=tree[id].mn1) 
            tree[id].mn1=val;
        else if (val<tree[id].mn2)
            tree[id].mn2=val;
    }   

    void push_min(ll id, ll l, ll r, ll v)
    {
        if (v<tree[id].mn1) return;
        tree[id].sum-=tree[id].mn1*tree[id].mnc;
        tree[id].mn1=v;
        tree[id].sum+=tree[id].mn1*tree[id].mnc;
        if (l==r) 
            tree[id].mx1=v;
        else if (v>=tree[id].mx1) 
            tree[id].mx1=v;
        else if (v>tree[id].mx2)
            tree[id].mx2=v;
    }

    void push_down(ll id, ll l, ll r)
    {
        if (l==r) return;
        ll mid=(l+r)/2;
        push_add(id*2, l, mid, tree[id].lazy);
        push_add(id*2+1, mid+1, r, tree[id].lazy);
        push_max(id*2, l, mid, tree[id].mx1);
        push_max(id*2+1, mid+1, r, tree[id].mx1);
        push_min(id*2, l, mid, tree[id].mn1);
        push_min(id*2+1, mid+1, r, tree[id].mn1);
        tree[id].lazy=0;
    }

    void update_add(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (u>r || v<l) return;
        if (u<=l && r<=v) 
        {
            push_add(id, l, r, val);
            return;
        }
        push_down(id, l, r);
        ll mid=(l+r)/2;
        update_add(id*2, l, mid, u, v, val);
        update_add(id*2+1, mid+1, r, u, v, val);
        tree[id]=merge(id);
    }

    void update_max(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (u>r || v<l || val<=tree[id].mn1) return;
        if (u<=l && r<=v && val<tree[id].mn2) 
        {
            push_min(id, l, r, val);
            return;
        }
        push_down(id, l, r);
        ll mid=(l+r)/2;
        update_max(id*2, l, mid, u, v, val);
        update_max(id*2+1, mid+1, r, u, v, val);
        tree[id]=merge(id);
    }

    void update_min(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if (u>r || v<l || val>=tree[id].mx1) return;
        if (u<=l && r<=v && val>tree[id].mx2) 
        {
            push_max(id, l, r, val);
            return;
        }
        push_down(id, l, r);
        ll mid=(l+r)/2;
        update_min(id*2, l, mid, u, v, val);
        update_min(id*2+1, mid+1, r, u, v, val);
        tree[id]=merge(id);
    }

    ll query_sum(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].sum;
        push_down(id, l, r);
        ll mid=(l+r)/2;
        return query_sum(id*2, l, mid, u, v)+query_sum(id*2+1, mid+1, r, u, v);
    }

    ll query_max(ll id, ll l, ll r, ll u, ll v)
    {
        if (l>v || r<u) return 0;
        if (u<=l && r<=v) return tree[id].mx1;
        push_down(id, l, r);
        ll mid=(l+r)/2;
        return query_max(id*2, l, mid, u, v)+query_max(id*2+1, mid+1, r, u, v);
    }
};

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    segment_tree_beats seg(n);
    while (q--)
    {
        ll type; cin>>type;
        if (type==0)
        {
            ll l, r, v; cin>>l>>r>>v;
            seg.update_min(1, 1, n, l, r, v);
        }
        else if (type==1)
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query_max(1, 1, n, l, r)<<endl;
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<seg.query_sum(1, 1, n, l, r)<<endl;
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}