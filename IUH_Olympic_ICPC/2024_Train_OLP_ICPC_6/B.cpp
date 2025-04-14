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
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, m;
string c1[305], c2[305];

const ll MOD = (1LL<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll base = uniform_int_distribution<ll>(0, MOD - 1)(rng);

struct HashedString
{
    ll n;  
    ll maxn = 305;
    // ll base = 331;
    string s;
    vector<ll> pw, hs;

    HashedString() {}
    void init(string _s)
    {
        n = _s.size()-2; s = _s;  
        pw.resize(maxn+5, 1);
        hs.resize(maxn+5, 0);
        for (ll i = 1; i <= maxn; i++) pw[i] = mul(pw[i - 1], base);
        for (ll i = 1; i <= n; i++) hs[i] = add(hs[i - 1], mul(_s[i] - 'a' + 1, pw[i - 1])); //chu y _s khong phai s
    }

    ll mul(ll a, ll b) { return ((__int128)a * b) % MOD; }
    ll add(ll a, ll b) { return (a + b) % MOD; }

    ll gethash(ll l, ll r)
    {
        ll x = (hs[r] - hs[l - 1] + MOD) % MOD;  
        x = mul(x, pw[maxn - r]);
        return x;
    }
};
HashedString hash1[305], hash2[305];

bool check(ll mid)
{
    for (ll x1=1; x1<=n-mid+1; x1++)
        for (ll y1=1; y1<=m-mid+1; y1++)
        {
            ll x2=x1+mid-1, y2=y1+mid-1;
            bool check=1;
            for (ll i=0; i<mid; i++) 
            {
                if (hash1[x1+i].gethash(y1, y2)!=hash2[x2-i].gethash(m-y2+1, m-y1+1))
                    check=0;
            }
            if (check==1) 
            {
                // cerr<<x1<<" "<<y1<<" "<<mid<<endl;
                return 1;
            }
        }
    return 0;
}

void solve()
{
    cin>>n>>m;

    for (ll i=1; i<=n; i++)
    {
        cin>>c1[i];
        c1[i]=" "+c1[i]+" ";
    }

    for (ll i=1; i<=n; i++)
    {
        c2[i]=c1[i];
        reverse(c2[i].begin(), c2[i].end());
    }

    for (ll i=1; i<=n; i++)

    for (ll i=1; i<=n; i++) hash1[i].init(c1[i]);
    for (ll i=1; i<=n; i++) hash2[i].init(c2[i]);

    vector<ll> chan;
    for (ll i=2; i<=min(n, m); i+=2) chan.push_back(i);
    ll l=0, r=chan.size(), anschan=-1;
    while (l<=r && !chan.empty())
    {
        ll mid=(l+r)/2;
        if (check(chan[mid])) anschan=chan[mid], l=mid+1;
        else r=mid-1;
    }

    vector<ll> le;
    for (ll i=3; i<=min(n, m); i+=2) le.push_back(i);
    ll ansle=-1;
    l=0, r=le.size();
    while (l<=r && !le.empty())
    {
        ll mid=(l+r)/2;
        if (check(le[mid])) ansle=le[mid], l=mid+1;
        else r=mid-1;
    }

    cout<<max(anschan, ansle);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}