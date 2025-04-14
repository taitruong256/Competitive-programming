#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const ll mod = 1e9+7;
const ll base = 31;
const ll maxn = 1e5+5;

ll mul(ll a, ll b) { return __int128_t(a)*b%mod; }
ll add(ll a, ll b) { return (a+b)%mod; }
ll sub(ll a, ll b) { return (a-b+mod)%mod; }
ll pw[maxn+5];

struct hashedstring
{
    vector<ll> hsh;
    ll n;
    string s;
    void init(string _s)
    {
        s=_s;
        s=" "+s;
        n=_s.size();
        hsh.resize(n+5);
        for (ll i=1; i<=n; i++) hsh[i]=add(hsh[i-1], mul((s[i]-'a'+1), pw[i-1]));
    }   

    ll gethash(ll l, ll r)
    {
        ll res=sub(hsh[r], hsh[l-1]);
        res=mul(res, pw[maxn-l]);
        return res;
    }
};

void solve()
{
    string st; cin>>st; 
    ll n=st.size();
    vector<string> suffixarray;
    for (ll i=0; i<n; i++) suffixarray.push_back(st.substr(i, n-i));
    sort(suffixarray.begin(), suffixarray.end());
    ll ans=1;
    for (auto s: suffixarray)
    {
        hashedstring hsh;
        hsh.init(s);
        ll m=s.size();
        for (ll len=1; len<=n; len++)
        {
            vector<ll> v;
            for (ll i=1; i+len-1<=m; i+=len) v.push_back(hsh.gethash(i, i+len-1));
            v.push_back(-1);
            ll now=1, cnt=1;
            for (ll i=1; i<v.size(); i++) 
            {
                if (v[i]==v[i-1]) ++cnt;
                else now=max(now, cnt), cnt=1;
            }
            // cout<<s<<" "<<len<<"      ";
            // for (auto i: v) cout<<i<<" "; 
            // cout<<"      "<<now<<endl;
            ans=max(ans, now);
        }            
        // cout<<endl;
    }
    cout<<ans<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    pw[0]=1;
    for (ll i=1; i<=maxn; i++) pw[i]=mul(pw[i-1], base);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}