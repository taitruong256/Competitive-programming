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
ll bit[1005][1005], a[1005][1005];
ll n, q;

void update(ll x, ll y, ll val)
{
    for (ll i=x; i<=n; i+=-i&i)
        for (ll j=y; j<=n; j+=-j&j) bit[i][j]+=val;
}

ll query(ll x, ll y)
{
    ll sum=0;
    for (ll i=x; i>=1; i-=-i&i)
        for (ll j=y; j>=1; j-=-j&j) sum+=bit[i][j];
    return sum;
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++)
        {
            char c; cin>>c;
            if (c=='*') update(i, j, 1), a[i][j]=1;
        }
    // for (ll i=1; i<=n; i++)
    //     for (ll j=1; j<=n; j++) cout<<query(i, j)<<" \n"[j==n];

    while (q--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ll x, y; cin>>x>>y;
            ll k=(a[x][y]^1)-a[x][y];
            a[x][y]^=1;
            update(x, y, k);
        }
        else 
        {
            ll a, b, c, d; cin>>a>>b>>c>>d;
            cout<<query(c, d)-query(a-1, d)-query(c, b-1)+query(a-1, b-1)<<endl;
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