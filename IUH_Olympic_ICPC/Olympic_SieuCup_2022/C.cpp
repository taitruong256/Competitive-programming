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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll base = 31;

ll mul(ll a, ll b)
{
    return (__int128_t)a*b%mod;
}

ll add(ll a, ll b)
{
    return (a+b)%mod;
}

ll sub(ll a, ll b)
{
    return (a-b+mod)%mod;
}

ll binpow(ll x, ll n)
{
    if (n==0) return 1;
    ll t=binpow(x, n/2);
    t=mul(t, t);
    if (n%2==1) t=mul(t, x);
    return t;
}

struct hashed
{
    string s;
    vector<ll> hsh, pw;
    ll n;
    void init(string _s)
    {
        s=" "+_s;
        n=_s.size();
        hsh.resize(n+5);
        pw.resize(n+5, 1);
        for (ll i=1; i<=n; i++) pw[i]=mul(pw[i-1], base);
        for (ll i=1; i<=n; i++) hsh[i]=add(hsh[i-1], (s[i]-'a'+1)*pw[i]);
    }

    ll gethash(ll l, ll r)
    {
        ll res=sub(hsh[r], hsh[l-1]);
        res=mul(res, binpow(pw[l], mod-2));
        return res;
    }
};
ll n, q;
vector<string> s;
vector<pair<char, string>> query;

void solve()
{
    ll sz=0;
    bool only_q=true;
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        string x; cin>>x;
        s.push_back(x);
        sz+=x.size();
    }
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        char c;
        string x;
        cin>>c>>x;
        query.push_back({c, x});
        if (c!='q') only_q=false;
    }
    if (sz<=1e4)
    {
        multiset<string> ms;
        for (string x: s) ms.insert(x);
        ll q; cin>>q;
        for (auto [c, s]: query)
        {
            if (c=='q')
            {
                ll cnt=0;
                for (string x: ms) if (x.find(s)<=x.size()) cnt+=1;
                cout<<cnt<<endl;
            }
            else if (c=='e') ms.erase(ms.find(s));
            else ms.insert(s);
        }
    }
    else if (only_q==true)
    {
        hashed hsh[n+5];
        for (ll i=1; i<=n; i++) hsh[i].init(s[i-1]);
        for (auto [c, x]: query)
        {
            hashed hshx;
            hshx.init(x);
            ll ans=0;
            for (ll i=1; i<=n; i++) 
            {
                bool check=false;
                for (ll j=0; j<hsh[i].s.size()-x.size()+1; j++) if (hsh[i].gethash(j, j+x.size()-1)==hshx.gethash(1, x.size()))
                {
                    check=true;
                }
                ans+=check;
            }
            cout<<ans<<endl;
        }
    }
    else assert(1>2);
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