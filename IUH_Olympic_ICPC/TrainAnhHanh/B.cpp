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
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
bool nt[10000005];

bool doixung(ll n)
{
    string s=to_string(n);
    string t=s;
    reverse(t.begin(), t.end());
    return s==t;
}

void solve()
{
    memset(nt, true, sizeof(nt));
    nt[1]=false;
    for (ll i=2; i*i<=1e7; i++) if (nt[i]==true)
        for (ll j=i*i; j<=1e7; j+=i) nt[j]=false;
    ll l, r, s=0; cin>>l>>r;
    for (ll i=l; i<=r; i++) if (nt[i] && doixung(i)) s+=i;
    cout<<s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("palinprime.inp", "r", stdin);
    // freopen("palinprime.out", "w", stdout);
    solve();
    return 0;
}