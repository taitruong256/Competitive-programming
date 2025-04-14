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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n, k; cin>>n>>k;
    string s, t; cin>>s>>t;
    s=" "+s+"@";
    t=" "+t+"#";
    set<char> st;
    for (ll i=1; i<=n; i++) st.insert(s[i]);
    string v="";
    for (auto i: st) v.push_back(i);

    vector<string> candidates;
    ll sz=st.size();
    if (sz<=k) candidates.push_back(v);
    for (ll i=0; i<(1<<sz); i++)
    {
        ll cnt=0;
        string x="";
        for (ll j=0; j<sz; j++) if (i&(1<<j)) ++cnt;
        if (cnt==k) 
        {
            for (ll j=0; j<sz; j++) if (i&(1<<j)) x.push_back(v[j]);
            candidates.push_back(x);
        }
    }

    ll ans=0;
    for (auto i: candidates)
    {
        vector<ll> cnt(30);
        for (auto j: i) ++cnt[j-'a'];
        string ss=s;
        ll res=0, sum=0;
        for (ll j=1; j<=n; j++) if (cnt[ss[j]-'a']>0) ss[j]=t[j];   
        for (ll j=1; j<=n+1; j++) 
        {
            if (ss[j]==t[j]) ++sum;
            else res+=sum*(sum+1)/2, sum=0;
        }
        ans=max(ans, res);
    }
    cout<<ans<<endl;
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