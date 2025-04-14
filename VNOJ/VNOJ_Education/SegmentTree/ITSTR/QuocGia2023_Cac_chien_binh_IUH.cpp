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
ll n, k, a[100005], mx[400005], cnt[400005];

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        mx[id]=a[l];
        cnt[id]=1;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    mx[id]=max(mx[id*2], mx[id*2+1]);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}

ll query_mx(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return -1e9;
    if (u<=l && r<=v) return mx[id];
    ll mid=(l+r)/2;
    return max(query_mx(id*2, l, mid, u, v), query_mx(id*2+1, mid+1, r, u, v));
}

ll query_cnt(ll id, ll l, ll r, ll u, ll v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return cnt[id];
    ll mid=(l+r)/2;
    return query_cnt(id*2, l, mid, u, v)+query_cnt(id*2+1, mid+1, r, u, v);
}

ll index(ll id, ll l, ll r, ll k)  // vi tri thu k
{
    if (l==r) return l;
    ll mid=(l+r)/2;
    if (cnt[id*2]>=k) return index(id*2, l, mid, k);
    return index(id*2+1, mid+1, r, k-cnt[id*2]);
}

ll get_index(ll id, ll l, ll r, ll k)  //vi tri dau tien >=k trong [1, n]
{
    if (l==r) return l;
    ll mid=(l+r)/2;
    if (mx[id*2]>=k) return get_index(id*2, l, mid, k);
    return get_index(id*2+1, mid+1, r, k);
}

void update(ll id, ll l, ll r, ll pos)
{
    if (l>pos || r<pos) return;
    if (pos<=l && r<=pos) 
    {
        mx[id]=-1e9;
        cnt[id]=0;
        return;
    }
    ll mid=(l+r)/2;
    update(id*2, l, mid, pos);
    update(id*2+1, mid+1, r, pos);
    mx[id]=max(mx[id*2], mx[id*2+1]);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=4*n; i++) mx[i]=-1e9;
    build(1, 1, n);
    vector<ll> ans;
    ll m=n;
    for (ll i=1; i<=n; i++)
    {
        ll l=index(1, 1, n, 1);
        ll r=index(1, 1, n, min(m, 1+k));
        ll val=query_mx(1, 1, n, l, r);
        ll idx=get_index(1, 1, n, val);
        k-=query_cnt(1, 1, n, l, idx)-1;
        ans.push_back(val);
        update(1, 1, n, idx);
        --m;
    }
    for (auto i: ans) cout<<i<<" ";
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