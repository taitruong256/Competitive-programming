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
                                        Pratice, practice, and practice
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    k%=1000;
    multiset<ll> st1, st2;
    ll a[n+5], b[m+5], sum1=0, sum2=0;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        st1.insert(a[i]);
        sum1+=a[i];
    }
    for (ll i=1; i<=m; i++)
    {
        cin>>b[i];
        st2.insert(b[i]);
        sum2+=b[i];
    }
    if (k%2==0)
    {
        for (ll i=1; i<=2; i++)
        {
            if (i%2==1)
            {
                ll x=*st1.begin();
                ll y=*st2.rbegin();
                if (x>y) continue;
                st1.erase(st1.find(x));
                st2.erase(st2.find(y));
                st1.insert(y);
                st2.insert(x);
            }
            else 
            {
                ll x=*st2.begin();
                ll y=*st1.rbegin();
                if (x>y) continue;
                st2.erase(st2.find(x));
                st1.erase(st1.find(y));
                st2.insert(y);
                st1.insert(x);
            }
        }
        ll ans=0;
        for (auto i: st1) ans+=i;
        cout<<ans<<endl;
    }
    else cout<<sum1-*st1.begin()+max(*st1.begin(), *st2.rbegin())<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}