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
    ll n; cin>>n;
    string s[n+5];
    ll x[n+5], sum=0;
    for (ll i=1; i<=n; i++) cin>>s[i];
    for (ll i=1; i<=n; i++) cin>>x[i];


    for (ll i=1; i<=n; i++) sum+=s[i].size()*x[i];
    vector<ll> cnt(30);
    for (ll i=1; i<=n; i++)
    {
        map<char, ll> val;
        for (auto c: s[i]) ++val[c];
        for (auto [u, v]: val) cnt[u-'a']+=v*x[i];
    }
    
    if (sum%2==0)
    {
        bool check=true;
        ll s=0; 
        for (ll i=0; i<26; i++) if (cnt[i]>0)
        {
            s+=cnt[i]; 
            if (s>=sum/2) 
                if (check==true) cout<<char(i+'a')<<" ", check=false;
            if (s>=sum/2+1)
            {
                cout<<char(i+'a');
                return;
            }
        }
    }
    else 
    {
        ll s=0;
        for (ll i=0; i<26; i++) if (cnt[i]>0)
        {
            s+=cnt[i];
            if (s>=sum/2+1)
            {
                cout<<char(i+'a');
                return;
            }
        }
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}