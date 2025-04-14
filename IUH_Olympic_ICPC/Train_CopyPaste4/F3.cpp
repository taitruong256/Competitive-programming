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
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

// ordered_set seg[800005];

// void build(ll id, ll l, ll r)
// {
//     if (l==r)
//     {
//         seg[id].insert(v[l-1].idx);
//         return;
//     }
//     ll mid=(l+r)/2;
//     build(id*2, l, mid);
//     build(id*2+1, mid+1, r);
//     seg[id]=seg[id*2];
//     for (auto it: seg[id*2+1]) seg[id].insert(it);
// }

// void update (ll id, ll l, ll r, ll u, ll v,ll oldval, ll newval)
// {
//     if(l>v || r<u) return;
//     if(l==r)
//     {    
//         seg[id].erase(oldval);
//         seg[id].insert(newval);
//         return;
//     }
//      ll mid = (l+r)/2;
//      update(id*2, l, mid, u, v, oldval, newval);
//      update(id*2+1, mid+1, r, u, v, oldval, newval);
//      seg[id] = max(seg[id*2], seg[id*2+1]);
// }

// ll get(ll id, ll l, ll r , ll u, ll v, ll x, ll y)
// {
//     if(l>v || r<u) return 0;
//     if(u<=l && r<=v) 
//     {
        
//         return seg[id].order_of_key(*seg[id].upper_bound(y))-seg[id].order_of_key(*seg[id].lower_bound(x))+1;
//     }
//      ll mid = (l+r)/2;
//      return max(get(id*2,l,mid,u,v, x, y), get(id*2+1,mid+1,r,u,v, x, y));
// }

void solve()
{
    ll n, m; cin>>n>>m;
    string s[n+5];
    for (ll i=1; i<=n; i++) cin>>s[i];
    sort(s+1, s+n+1);
    while (m--)
    {
        ll type; cin>>type;
        string t; cin>>t;
        ll upper=upper_bound(s+1, s+n+1, t)-s-1;
        ll lower=lower_bound(s+1, s+n+1, t)-s; 
        cout<<upper<<" "<<lower<<endl;
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