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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, q, a[100005];
ll tree[400005], lazyadd[400005], lazymul[400005];  

ll add(ll x, ll y)
{
    return (x+y+mod*mod)%mod;
}

void down(ll id, ll l, ll r)
{
    if (l==r) return;
    ll t, mid=(l+r)/2;

    t=lazymul[id];
    if (t!=1)
    {
        tree[id*2]*=t;                 tree[id*2]%=mod;
        tree[id*2+1]*=t;               tree[id*2+1]%=mod;
        lazymul[id*2]*=t;              lazymul[id*2]%=mod;
        lazymul[id*2+1]*=t;            lazymul[id*2+1]%=mod;
        lazyadd[id*2]*=t;              lazyadd[id*2]%=mod;
        lazyadd[id*2+1]*=t;            lazyadd[id*2+1]%=mod;
        lazymul[id]=1;
    }

    t=lazyadd[id];
    if (t>0)
    {
        tree[id*2]+=t*(mid-l+1);       tree[id*2]%=mod;
        lazyadd[id*2]+=t;              lazyadd[id*2]%=mod;
        tree[id*2+1]+=t*(r-mid);       tree[id*2+1]%=mod;
        lazyadd[id*2+1]+=t;            lazyadd[id*2+1]%=mod;
        lazyadd[id]=0;
    }
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return tree[id];
    down(id, l, r);
    ll mid=(l+r)/2;
    return add(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
}

void update_add(ll id, ll l, ll r, ll u, ll v, ll val)
{
    
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        tree[id]+=val*(r-l+1);         tree[id]%=mod;
        lazyadd[id]+=val;              lazyadd[id]%=mod;
        return;
    }
    down(id, l, r);
    ll mid=(l+r)/2;
    update_add(id*2, l, mid, u, v, val);
    update_add(id*2+1, mid+1, r, u, v, val);
    tree[id]=add(tree[id*2], tree[id*2+1]);
}

void update_mul(ll id, ll l, ll r, ll u, ll v, ll val)
{
    
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        tree[id]*=val;                 tree[id]%=mod;
        lazymul[id]*=val;              lazymul[id]%=mod;
        lazyadd[id]*=val;              lazyadd[id]%=mod;
        return;
    }
    down(id, l, r);
    ll mid=(l+r)/2;
    update_mul(id*2, l, mid, u, v, val);
    update_mul(id*2+1, mid+1, r, u, v, val);
    tree[id]=add(tree[id*2], tree[id*2+1]);
}

void update_ass(ll id, ll l, ll r, ll u, ll v, ll val)
{
    
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        tree[id]=val*(r-l+1);          tree[id]%=mod;
        lazymul[id]=0;                 lazymul[id]%=mod;
        lazyadd[id]=val;               lazyadd[id]%=mod;
        return;
    }
    down(id, l, r);
    ll mid=(l+r)/2;
    update_ass(id*2, l, mid, u, v, val);
    update_ass(id*2+1, mid+1, r, u, v, val);
    tree[id]=add(tree[id*2], tree[id*2+1]);
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) update_add(1, 1, n, i, i, a[i]);
    
    while (q--)
    {
        ll type; cin>>type;
        if (type==1)
        {
            ll l, r, v; cin>>l>>r>>v;
            update_add(1, 1, n, l, r, v);
        }
        else if (type==2)
        {
            ll l, r, v; cin>>l>>r>>v;
            update_mul(1, 1, n, l, r, v);
        }
        else if (type==3)
        {
            ll l, r, v; cin>>l>>r>>v;
            update_ass(1, 1, n, l, r, v);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<endl;
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
    solve();
    return 0;
}
