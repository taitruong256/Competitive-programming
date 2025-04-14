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

ll binpow(ll x, ll n, ll mod)
{
    ll ans=1;
    while (n>0)
    {
        if (n%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return ans;
}
ll f[1005];

ll nCk(ll n, ll k)
{
    if (k>n) return 0;
    ll ans=f[n];
    ans=(ans*binpow(f[k], mod-2, mod))%mod;
    ans=(ans*binpow(f[n-k], mod-2, mod))%mod;
    return ans;
}

void solve()
{
    string s, t; cin>>s>>t;  
    ll k; cin>>k;
    ll n=s.size(), m=t.size();
    vector<ll> cntchu(30), cntso(12);
    for (auto c: s) ++cntchu[c-'A'];
    for (auto c: t) ++cntso[c-'0'];
    ll ans1=f[n];
    for (ll i=0; i<26; i++) if (cntchu[i]>0) ans1=(ans1*binpow(cntchu[i], mod-2, mod))%mod;
    cout<<ans1<<" ";
    ll ans2=f[m];
    for (ll i=0; i<10; i++) if (cntso[i]>0) ans2=(ans2*binpow(cntso[i], mod-2, mod))%mod;
    cout<<ans2<<" ";
     
    set<string> st;
    if (k%2==0)
    {
        sort(t.begin(), t.end());
        do 
        {
            st.insert(t);
        }
        while (next_permutation(t.begin(), t.end()));
        cout<<st.size();
    }
    else 
    {
        assert(k%2==0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    f[1]=1;
    for (ll i=2; i<=1000; i++) f[i]=(f[i-1]*i)%mod;
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}