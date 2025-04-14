#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    vector<ll> v;
    for (ll i=0; i<n; i++)
    {
        char c; cin>>c;
        v.push_back(c);
    }
    ll ans=0;
    for (ll i=0; i<=999999; i++)
    {
        string s=to_string(i);
        while (s.size()<6) s="0"+s;
        set<char> st;
        for (auto c1: s) st.insert(c1);
        if (st.size()!=2) continue;

        bool check=1;
        vector<ll> cnt(11);
        for (char c1: s) ++cnt[c1-'0'];
        for (ll i=0; i<10; i++) if (cnt[i]!=3 && cnt[i]!=0) check=0;
        if (check==0) continue;

        for (char c1: s)
            for (auto c2: v) 
                if (c1==c2) check=0;
        
        if (check==1) ++ans;
    }
    cout<<ans;
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