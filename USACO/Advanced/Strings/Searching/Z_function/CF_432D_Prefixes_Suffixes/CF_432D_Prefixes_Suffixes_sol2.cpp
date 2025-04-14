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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct KMP
{
    string s;  //tim so lan xuat hien cua s trong t
    ll n;
    vector<ll> pi;  //pi[i]=do dai tien to k lon nhat s[0:k-1] ma hau to ket thuc tai i s[i-k+1:k] 

    KMP(){}
    KMP(string _s)
    {
        s=_s;
        n=s.size();
        pi.resize(n+5);  //index bat dau tu 0
        pi[0]=0;
        for (ll i=1; i<n; i++)
        {
            ll j=pi[i-1];
            while (j>0 && s[i]!=s[j]) j=pi[j-1];  //neu s[i]!=s[pi[i-1]] thi tim k lon nhat < j thoa man tinh chat cua pi 
            if (s[i]==s[j]) ++j;
            pi[i]=j;
        }
    }
};

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    vector<ll> cnt(n+5, 1);
    KMP kmp(s);
    for (ll i=n-1; i>=0; i--) cnt[kmp.pi[i]]+=cnt[i+1];  //do ham pi index tu 0

    vector<pair<ll, ll>> ans;
    ll x=n;
    while (x>0)
    {
        ans.push_back({x, cnt[x]});
        x=kmp.pi[x-1];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto [x, y]: ans) cout<<x<<" "<<y<<endl;
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