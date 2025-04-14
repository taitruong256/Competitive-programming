/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
         __                    __
        |  |                  |  |         
     ___|  |__             ___|  |__  
    |__ |   __|           |__ |   __| 
        |  |    ____    _     |  |    ____  __  __  ____    _____    _____
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \
        |  |_  | |_| | | |    |  |   | |   | \_/ | | |_| | | /  \ | | |_| |
        \____\ \____/| |_|    \__\   |_|   \_____/ \_____/ |_|  | | \__   |
                                                                        | |
                                                                      __/ |
                                                                     |___/  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, q;
ll a[200005], bit[200005];

void update(ll index, ll value)
{
    for (ll i=index; i<=n; i+=-i&i) bit[i]+=value;
}

ll query(ll index)
{
    ll s=0;
    for (ll i=index; i>=1; i-=-i&i) s+=bit[i];
    return s;
}

void build()
{
    memset(bit, 0, sizeof(bit));
    for (ll i=1; i<=n; i++) 
    {
        update(i, a[i]);
        update(i+1, -a[i]);
    }
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build();
    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll a, b, val; cin>>a>>b>>val;
            update(b+1, -val);
            update(a, val);
        }
        else
        {
            ll id; cin>>id;
            cout<<query(id)<<endl;
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