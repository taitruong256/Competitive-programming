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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ll int
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

ll numdiv(ll n)
{
    ll cnt=0;
    for (ll i=2; i*i<=n; i++)
    {
        while (n%i==0 && n>1) ++cnt, n/=i;
    }
    return cnt+(n>1);
}

void solve()
{
    ll a, b, k; scanf("%lld%lld%lld", &a, &b, &k);
    ll g=__gcd(a, b), mn;
    if (a==b) mn=0;
    else if (g==a || g==b) mn=1;
    else mn=2;
    ll mx=numdiv(a)+numdiv(b);                 //   cout<<mn<<" "<<mx<<endl;
    if (mn==1 && k==1) printf("YES\n");
    else if (mn<=k && k<=mx)
    {
        if (k==1) printf("NO\n");
        else printf("YES\n");
    }
    else printf("NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; scanf("%lld", &t);
    while (t--) solve();
    return 0;
}