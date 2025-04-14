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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return abs(a.first-a.second)/2<abs(b.first-b.second)/2;
}

void solve()
{
    ll n, k; cin>>n>>k;
    map<char, ll> cnt;
    string s; cin>>s;
    for (auto c: s) ++cnt[c];
    vector<pair<ll, ll>> v;
    
    for (char c='a'; c<='z'; c++) v.push_back({cnt[c], cnt[char(c-32)]});
    sort(v.begin(), v.end(), comp);
    

    ll ans=0;
    for (auto [x, y]: v)
    {
        ll cost=abs(x-y)/2;
        if (cost<=k) k-=cost, ans+=(x+y)/2;
        else if (k>0) 
        {
            if (x>y) swap(x, y);
            x+=k;
            y-=k;
            k=0;
            ans+=min(x, y);
        }
        else ans+=min(x, y);
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