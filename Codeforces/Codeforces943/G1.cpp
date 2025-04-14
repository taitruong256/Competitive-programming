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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

struct Z_function
{
    vector<ll> z; // z[i]=do dai tien to dai nhat cua s[0:n-1] va s[i: n-1]
    ll n, l, r;
    string s;

    Z_function(){}
    void init(string _s)
    {
        s=_s;
        n=_s.size();
        z.resize(0);
        z.resize(n+5);
        z[0]=n;  //tuy bai toan ma z[0]=0;
        l=0; r=0;  //duy tri doan s[l, r)=s[0:r-l) da duoc tinh. z[i]=r-l 
        for (ll i=1; i<n; i++)
        {
            if (i<r) z[i]=min(z[i-l], r-i);  //lay min (z[i-l], r-i) vi z[i-l] co the lon hon r-i vo ly
            while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];  //thuat toan tam thuong 
            if (i+z[i]>r) l=i, r=i+z[i];  //cap nhat doan [l, r)=[i, i+z[i])
        }
    }
};

ll n, k; 
Z_function zf;

bool check(ll len)
{
    ll cnt=1;
    for (ll i=len; i<n; i++)
    {
        if (zf.z[i]>=len) ++cnt, i+=len-1;
    }
    return cnt>=k;
}

void solve()
{
    cin>>n>>k>>k; 
    string s; cin>>s; 
    zf.init(s);
    ll l=1, r=n, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}