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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll base = 31;

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]=(bit[i]+val+mod*mod)%mod;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum=(sum+bit[i]+mod*mod)%mod;
        return sum;
    }
};
ll n, t, q, pw[200005];

void solve()
{
    string s1, s2; cin>>s1>>s2;
    n=s1.size(); s1=" "+s1; s2=" "+s2;
    pw[n]=1;
    for (ll i=n-1; i>=1; i--) pw[i]=(pw[i+1]*base)%mod;
    fenwick ft1(n), ft2(n);
    for (ll i=1; i<=n; i++) ft1.update(i, (s1[i]-'a'+1)*pw[i]%mod);
    for (ll i=1; i<=n; i++) ft2.update(i, (s2[i]-'a'+1)*pw[i]%mod);
    cin>>t>>q;
    queue<pair<pair<char, char>, pair<ll, ll>>> qu;
    for (ll i=1; i<=q; i++)
    {
        if (!qu.empty())
        {
            auto [x, y]=qu.front(); 
            ll timer=y.first, idx=y.second;
            char c1=x.first, c2=x.second;
            if (i-timer==t)
            {
                ft1.update(idx, (c1-'a'+1)*pw[idx]%mod);
                ft2.update(idx, (c2-'a'+1)*pw[idx]%mod);
                qu.pop();
            }
        }
        ll type; cin>>type;
        if (type==1)
        {
            ll pos; cin>>pos;
            qu.push({{s1[pos], s2[pos]}, {i, pos}});
            ft1.update(pos, -(s1[pos]-'a'+1)*pw[pos]%mod);
            ft2.update(pos, -(s2[pos]-'a'+1)*pw[pos]%mod);
        }
        if (type==2)
        {
            ll idx1, pos1, idx2, pos2; cin>>idx1>>pos1>>idx2>>pos2;
            char c1, c2;
            if (idx1==1) c1=s1[pos1]; else c1=s2[pos1];
            if (idx2==1) c2=s1[pos2]; else c2=s2[pos2];

            if (idx1==1) 
            {
                ft1.update(pos1, -(s1[pos1]-'a'+1)*pw[pos1]%mod);
                s1[pos1]=c2;
                ft1.update(pos1, (c2-'a'+1)*pw[pos1]%mod);
            }
            else 
            {
                ft2.update(pos1, -(s2[pos1]-'a'+1)*pw[pos1]%mod);
                s2[pos1]=c2;
                ft2.update(pos1, (c2-'a'+1)*pw[pos1]%mod);
            }
            if (idx2==1)
            {
                ft1.update(pos2, -(s1[pos2]-'a'+1)*pw[pos2]%mod);
                s1[pos2]=c1;
                ft1.update(pos2, (c1-'a'+1)*pw[pos2]%mod);
            }
            else 
            {
                ft2.update(pos2, -(s2[pos2]-'a'+1)*pw[pos2]%mod);
                s2[pos2]=c1;
                ft2.update(pos2, (c1-'a'+1)*pw[pos2]%mod);
            }
        }
        if (type==3)
        {
            if (ft1.query(n)==ft2.query(n)) cout<<"YES\n";
            else cout<<"NO\n";
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
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}