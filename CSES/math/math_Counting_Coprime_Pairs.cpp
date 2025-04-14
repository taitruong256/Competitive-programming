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
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9, maxn=1e5+5, maxx=1e6+5;
ll minprime[1000005], n, a[100005], cnt[1000005];

void sieve()
{
    minprime[1]=1;
    for (ll i=0; i<maxx; i++) minprime[i]=0;
    for (ll i=0; i<maxx; i++) cnt[i]=0;
    for (ll i=2; i<maxx; i++) if (minprime[i]==0)
        for (ll j=i; j<maxx; j+=i) if (minprime[j]==0) minprime[j]=i;
    for (ll i=0; i<maxx; i++) if (minprime[i]==0) minprime[i]=i;
}

void solve()
{
    cin>>n;
    for (ll i=0; i<n; i++) cin>>a[i];

    sieve();
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        ll x=a[i];             
        vector<ll> divisor;
        while(x>1)
        {
            ll y=minprime[x];
            divisor.push_back(y);
            while (x%y==0) x/=y;
        }


        ll k=divisor.size();
        for (ll mask=1; mask<(1<<k); mask++)
        {
            ll p=1;
            for (ll j=0; j<k; j++) if (mask&(1<<j)) p*=divisor[j];
            if (__builtin_popcountll(mask)%2==1) ans+=cnt[p];
            else ans-=cnt[p];
            ++cnt[p];
        }          
    }
    cout<<n*(n-1)/2-ans;
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