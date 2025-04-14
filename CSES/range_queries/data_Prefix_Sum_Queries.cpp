/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, q;
ll pref[800005], sum[800005], a[200005];
map<ll, ll> idx;

void pull(ll id)
{
    pref[id]=max(pref[id*2], sum[id*2]+pref[id*2+1]);
    sum[id]=sum[id*2]+sum[id*2+1];
}

void build(ll id, ll l, ll r)
{
    if (l==r)
    {
        sum[id]=a[l];
        pref[id]=max(sum[id], 0LL);
        idx[l]=id;
        return;
    }
    ll mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    pull(id);
}

void update(ll pos, ll val)
{
    ll id=idx[pos];
    pref[id]=max(0LL, val);
    sum[id]=val;
    id/=2;
    while (id>0)
    {
        pull(id);
        id/=2;
    }
}

pair<ll, ll> query(ll id, ll l, ll r, ll u, ll v)
{
    if (r<u || l>v) return {0, 0};
    if (u<=l && r<=v) return {pref[id], sum[id]};
    ll mid=(l+r)/2;
    pair<ll, ll> left=query(id*2, l, mid, u, v);
    pair<ll, ll> right=query(id*2+1, mid+1, r, u, v);
    return {max(left.first, left.second+right.first), left.second+right.second};
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    
    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll pos, val; cin>>pos>>val;
            update(pos, val);
        }
        else 
        {
            ll l, r; cin>>l>>r;
            cout<<query(1, 1, n, l, r).first<<endl;
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