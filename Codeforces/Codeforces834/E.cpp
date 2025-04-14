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
deque<ll> phuongan1, phuongan2, phuongan3;
ll a[200005], n, h;

ll test(deque<ll> phuongan, ll h)
{
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        while (h<=a[i] && !phuongan.empty())
        {
            h=h*phuongan.front();
            phuongan.pop_front();
        }
        if (h<=a[i]) break;
        h+=a[i]/2;
        ++ans;
    }
    return ans;
}

void solve()
{
    cin>>n>>h;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    cout<<max({test(phuongan1, h), test(phuongan2, h), test(phuongan3, h)})<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    phuongan1.push_back(2); phuongan1.push_back(2); phuongan1.push_back(3);
    phuongan2.push_back(2); phuongan2.push_back(3); phuongan2.push_back(2);
    phuongan3.push_back(3); phuongan3.push_back(2); phuongan3.push_back(2);
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}