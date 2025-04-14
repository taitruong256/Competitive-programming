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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
struct query{ll st, fi, id;} q[200005];
ll room[200005];
bool comp(query a, query b)
{
    if (a.st==b.st) return a.fi<b.fi;
    return a.st<b.st;
}

void solve()
{
    ll n; cin>>n;
    for (ll i=1; i<=n; i++)
    {
        cin>>q[i].st>>q[i].fi;
        q[i].id=i;
    }
    sort(q+1, q+n+1, comp);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    ll cnt=1;
    for (ll i=1; i<=n; i++)
    {
        if (q[i].st>pq.top().first)
        {
            pair<ll, ll> x=pq.top(); pq.pop();
            room[q[i].id]=x.second;
            pq.push({q[i].fi, x.second});
        }
        else
        {
            room[q[i].id]=++cnt;
            pq.push({q[i].fi, cnt});
        }
    }
    cout<<cnt<<endl;
    for (ll i=1; i<=n; i++) cout<<room[i]<<" ";
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