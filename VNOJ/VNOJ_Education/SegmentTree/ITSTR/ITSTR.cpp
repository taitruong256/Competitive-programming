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
#define endl '\n'
const ll mod = 1007050321;
string s;
ll n, q, a[100005], sum[400005], idx[400005], lazy[400005];

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}

ll add(ll x, ll y)
{
    return (x+y+mod*mod)%mod;
}

ll mul(ll x, ll y)
{
    return (x*y)%mod;
}

void build(ll id, ll l, ll r)
{
    lazy[id]=1;
    if (l==r)
    {
        sum[id]=a[l];
        idx[id]=1;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    sum[id]=add(sum[id*2], sum[id*2+1]);
    idx[id]=add(idx[id*2], idx[id*2+1]);
}

void down(ll id)
{
    ll t=lazy[id];
    sum[id*2]=mul(sum[id*2], t);
    lazy[id*2]=mul(lazy[id*2], t);
    sum[id*2+1]=mul(sum[id*2+1], t);
    lazy[id*2+1]=mul(lazy[id*2+1], t);
    lazy[id]=1;
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return sum[id];
    ll mid=(l+r)/2;
    down(id);
    return add(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
}

void deleted(ll id, ll l, ll r, ll pos)
{
    if (l>pos || r<pos) return;
    if (l==r) 
    {
        sum[id]=0;
        idx[id]=0;
        lazy[id]=1;
        return;
    }
    ll mid=(l+r)/2;
    down(id);
    deleted(id*2, l, mid, pos);
    deleted(id*2+1, mid+1, r, pos);
    sum[id]=add(sum[id*2], sum[id*2+1]);
    idx[id]=add(idx[id*2], idx[id*2+1]);
}

void update(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v) 
    {
        ll val=binpow(2, mod-2, mod);
        sum[id]=mul(sum[id], val);
        lazy[id]=mul(lazy[id], val);
        return;
    }
    ll mid=(l+r)/2;
    down(id);
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    sum[id]=add(sum[id*2], sum[id*2+1]);
    idx[id]=add(idx[id*2], idx[id*2+1]);
}

ll index(ll id, ll l, ll r, ll k)  // vi tri thu k
{
    if (l==r) return l;
    ll mid=(l+r)/2;
    down(id);
    if (idx[id*2]>=k) return index(id*2, l, mid, k);
    return index(id*2+1, mid+1, r, k-idx[id*2]);
}

void solve()
{
    string s; cin>>s;
    n=s.size(); s=" "+s;
    for (ll i=1; i<=n; i++) a[i]=(s[i]-'0')*binpow(2, n-i, mod);
    build(1, 1, n);
    cin>>q;
    ll m=n;
    ll cnt=0;
    // for (ll i=1; i<=n; i++) cout<<query(1, 1, n, i, i)<<" "; cout<<endl;
    for (ll i=1; i<=q; i++)
    {
        char c; cin>>c;
        if (c=='?')
        {
            ll l, r; cin>>l>>r;
            ll _r=r;
            l=index(1, 1, n, l);
            r=index(1, 1, n, r);
            ll ans1=query(1, 1, n, l, r);
            ll ans2=binpow(2, m-_r, mod); 
            ans2=binpow(ans2, mod-2, mod);
            cout<<(ans1*ans2)%mod<<endl;
        }
        else 
        {
            ll pos; cin>>pos;    
            pos=index(1, 1, n, pos);    
            deleted(1, 1, n, pos);
            update(1, 1, n, 1, pos);
            // for (ll i=1; i<=n; i++) cout<<query(1, 1, n, i, i)<<" "; cout<<endl;
            --m;
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
