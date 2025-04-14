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

const ll MOD = (1LL<<61)-1;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
struct HashedString
{
    ll n;  
    ll maxn = 1e3+5;
    ll base = 331;
    string s;
    vector<ll> pw, hs;

    HashedString() {}
    void init(string _s)
    {
        maxn = n = _s.size(); s = _s; _s = " " + _s;
        // base = uniform_int_distribution<ll>(0, MOD - 1)(rng);
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

char conv(char c)
{
    if (c=='*') return 'a';
    return 'b';
}

char inv_conv(char c)
{
    if (c=='*') return 'b';
    return 'a';
}

ll n, m, q;
string c1[1005], c2[1005];
HashedString hash1[1005], hash2[1005];

void solve()
{
    cin>>n>>m>>q;
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<m; j++)
        {
            char x; cin>>x;
            c1[i].push_back(' ');
            c2[i].push_back(' ');
            c1[i][j]=conv(x);
            c2[i][j]=inv_conv(x);
        }
    }
    
    for (ll i=0; i<n; i++) hash1[i+1].init(c1[i]);
    for (ll i=0; i<n; i++) hash2[i+1].init(c2[i]);

    // for (ll i=0; i<n; i++) cout<<c1[i]<<endl;
    // for (ll i=0; i<n; i++) cout<<c2[i]<<endl;
    
    while (q--)
    {
        ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        assert(x1<=x2 && y1<=y2);
        ll hash_value=0;
        if (c1[x1-1][y1-1]=='a') hash_value=hash1[x1].gethash(y1, y2);
        else hash_value=hash2[x1].gethash(y1, y2);
        bool check=1;
        for (ll i=x1; i<=x2; i++) 
        {
            if (c1[i-1][y1-1]=='a' && hash1[i].gethash(y1, y2)!=hash_value) 
            {
                check=0;
                break;
            }
            if (c1[i-1][y1-1]=='b' && hash2[i].gethash(y1, y2)!=hash_value) 
            {
                check=0;
                break;
            }
        }   
        if (check) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    solve();
    return 0;
}