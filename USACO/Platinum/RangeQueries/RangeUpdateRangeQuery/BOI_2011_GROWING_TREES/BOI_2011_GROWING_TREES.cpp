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
ll n, q, a[100005], seg[500005], lazy[500005];
 
void build(ll id, ll l, ll r)
{
    if (l==r)
    {       
        seg[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id]=max(seg[id*2], seg[id*2+1]);   
}
 
void down(ll id, ll l, ll r)
{
    if (lazy[id]!=0)
    {
        seg[id]+=lazy[id];
        if (l!=r)
        {
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
        }
        lazy[id]=0;
    }
}
 
void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if (u>v) return;
    down(id, l, r);
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        lazy[id]+=val;
        down(id, l, r);
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    seg[id]=max(seg[id*2], seg[id*2+1]);
}
 
ll getpos(ll id, ll l, ll r, ll val)
{
    down(id, l, r);  
    if (seg[1]<val) return n+1;
    if (l==r) return l;
    ll mid=(l+r)/2;
    if (seg[id*2]>=val) return getpos(id*2, l, mid, val);
    return getpos(id*2+1, mid+1, r, val);
}
 
ll getval(ll id, ll l, ll r, ll pos)
{                
    down(id, l, r);   
    if (l==r) return seg[id];
    ll mid=(l+r)/2;
    if (pos<=mid) return getval(id*2, l, mid, pos);
    return getval(id*2+1, mid+1, r, pos);
}
 
void solve()
{
    cin>>n>>q;  
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    build(1, 1, n);
    while (q--)
    {
        char c; cin>>c;
        if (c=='F')
        {
            ll cnt, h; cin>>cnt>>h;
            ll pos=getpos(1, 1, n, h); 
            if (pos==n+1) continue;
            if (pos+cnt-1>=n) 
            {   
                update(1, 1, n, pos, n, 1);
                continue;
            }
            ll mx=getval(1, 1, n, pos+cnt-1), l=getpos(1, 1, n, mx), r=getpos(1, 1, n, mx+1)-1;
            update(1, 1, n, pos, l-1, 1);   
            cnt-=(l-1-pos+1);
            update(1, 1, n, r-cnt+1, r, 1);  
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<getpos(1, 1, n, r+1)-getpos(1, 1, n, l)<<endl;
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
