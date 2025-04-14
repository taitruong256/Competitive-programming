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
ll a[200005], bit[200005];
vector<pair<ll, ll>> query[200005];

void update(ll index, ll val)
{
    for (ll i=index; i<=n; i+=-i&i) bit[i]+=val;
}

ll get_sum(ll index)
{
    ll sum=0;
    for (ll i=index; i>=1; i-=-i&i) sum+=bit[i];
    return sum;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    memset(bit, 0, sizeof(bit));
    map<ll, ll> cnt;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;
        ++cnt[r];
        query[r].push_back({l, i});
    }

    //for (auto it: query) sort(it.begin(), it.end());     
    map<ll, ll> truoc;
    ll ans[n+5];
    for (ll r=1; r<=n; r++)
    {             
        if (truoc[a[r]]) update(truoc[a[r]], -1);
        truoc[a[r]]=r;
        update(r, 1);
        for (auto [l, i]: query[r]) ans[i]=get_sum(r)-get_sum(l-1);
    }   
    for (ll i=1; i<=q; i++) cout<<ans[i]<<endl; 
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
