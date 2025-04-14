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
    ll n; cin>>n;
    string s; cin>>s; 
    string t=s;

    map<char, ll> cnt;
    for (char c='a'; c<='z'; c++) cnt[c]=0;
    for (auto c: s) ++cnt[c];
    set<ll> uoc;
    for (ll i=1; i*i<=n; i++) if (n%i==0) 
    {
        uoc.insert(i);
        if (n/i!=i) uoc.insert(n/i);
    }
    vector<pair<ll, char>> v;
    for (auto i: cnt) v.push_back({i.second, i.first});
    sort(v.begin(), v.end(), greater<pair<ll, char>>()); 

    ll mn=1e12, val=1;
    for (auto i: uoc)
    {
        ll res=0, sl=n/i, du=0;
        if (i>26) continue;
        for (ll j=0; j<i; j++) 
        {
            if (v[j].first==sl) continue;
            if (v[j].first>sl)
            {
                res+=v[j].first-sl;
                du+=v[j].first-sl;
            }
            if (v[j].first<sl)
            {
                ll thieu=sl-v[j].first;
                if (du-thieu>=0) du-=thieu;
                else 
                {
                    res+=thieu-du;
                    du=0;
                }
            }
        }
        if (res<mn) mn=res, val=i;
    }
    
    multiset<char> du, thieu;
    for (ll i=0; i<val; i++) 
    {
        if (v[i].first==n/val) continue;
        if (v[i].first<n/val) 
            for (ll j=0; j<n/val-v[i].first; j++) thieu.insert(v[i].second);
        else 
            for (ll j=0; j<v[i].first-n/val; j++) du.insert(v[i].second);
    }
    for (ll i=val; i<v.size(); i++) 
        for (ll j=0; j<v[i].first; j++) du.insert(v[i].second);
    
    // cout<<val<<endl;
    // for (auto i: du) cout<<i<<" "; cout<<endl;
    // for (auto i: thieu) cout<<i<<" "; cout<<endl;
    
    
    for (ll i=0; i<n; i++)
    {   
        if (du.find(t[i])!=du.end())
        {
            auto it=du.find(t[i]);
            du.erase(it);
            t[i]=*thieu.begin();
            it=thieu.find(t[i]);
            thieu.erase(it);
        }
    }
    ll d=0;  
    for (ll i=0; i<n; i++) if (s[i]!=t[i]) ++d;
    cout<<d<<endl;
    cout<<t<<endl;
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