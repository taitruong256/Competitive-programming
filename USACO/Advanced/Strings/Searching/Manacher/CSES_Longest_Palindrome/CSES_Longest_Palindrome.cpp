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

struct manacher   //luu y index cua t, p bat dau tu 1
{                 //      index cua s, p_odd, p_even bat dau tu 0
    string s, t;
    ll n, m, l=1, r=1;
    vector<ll> p, p_odd, p_even;    
    //p_odd[i] = so luong palindrome lay s[i] lam tam doi xung, palidrome dai nhat s[i-p[i]+1..i+p[i]-1]
    //p_even[i] = so luong palindrome lay s[i-1] va s[i] lam tam doi xung, palidrome dai nhat s[i-p[i]..i+p[i]-1]
    manacher(){}
    manacher(string _s)
    {
        s=_s; 
        n=s.size();
        for (auto c: s) t+=c, t+="#"; 
        m=t.size();
        p.resize(m+5);
        p_even.resize(n+5);
        p_odd.resize(n+5);

        //manacher's algorithm
        t="#"+t+"@";             
        for (ll i=1; i<=m; i++)
        {
            p[i]=min(r-i, p[l+r-i]);
            while (t[i-p[i]]==t[i+p[i]]) ++p[i];
            if (i+p[i]>r) l=i-p[i], r=i+p[i];
        }

        for (ll i=1; i<=m; i++) 
            if (i%2==1) p_odd[i/2]=p[i]/2;
            else p_even[i/2]=p[i]/2;
    }
};

void solve()
{
    string s; cin>>s;
    manacher ma(s);
    ll st=-1, mx=-1;
    for (ll i=0; i<s.size(); i++) if (ma.p_odd[i]*2-1>mx)
    {
        mx=ma.p_odd[i]*2-1;
        st=i-ma.p_odd[i]+1;
    }
    for (ll i=0; i<s.size(); i++) if (ma.p_even[i]*2>mx)
    {
        mx=ma.p_even[i]*2;
        st=i-ma.p_even[i];
    }
    cout<<s.substr(st, mx);
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