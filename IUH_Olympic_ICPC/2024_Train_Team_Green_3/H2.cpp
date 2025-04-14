#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, pref[200005];
string s;
vector<pair<ll, ll>> seg;

void solve()
{
    cin>>n;
    cin>>s; s=" "+s+" ";
    ll cnt=1, sum_cnt2=0, ans=0;
    for (ll i=1; i<=n+1; i++) 
    {
        if (s[i]==s[i-1]) ++cnt;
        else seg.push_back({i-cnt, i-1}), sum_cnt2+=cnt*cnt, cnt=1;
    }
    sum_cnt2+=1;
    seg.push_back({n, n});

    cout<<sum_cnt2<<endl;
    for (auto [l, r]: seg) cout<<l<<" "<<r<<endl; cout<<endl;
    ll m=seg.size()-2;
    for (ll i=1; i<=m-1; i++)
    {
        ll x=max(1LL, seg[i-1].first), y=min(seg[i+1].second, n), pos=seg[i].second;
        swap(s[pos], s[pos+1]);
        ll lenx1=seg[i].second-seg[i].first+1, leny1=seg[i+1].second-seg[i+1].first+1;
        ll lenx2=seg[i-1].second-seg[i-1].first+1, leny2=seg[i+2].second-seg[i+2].first+1;
        ll cnt=0, sum=0;
        for (ll j=x; j<=y+1; j++) 
            if (s[j]==s[j-1]) ++cnt;
            else sum+=cnt*cnt, cout<<cnt<<"    ", cnt=1;
        cout<<s.substr(x, y-x+1)<<"      "<<s<<"      ";
        cout<<x<<" "<<y<<" "<<sum<<" "<<endl;
        swap(s[pos], s[pos+1]);
        ans=max(ans, sum_cnt2-lenx1*lenx1-leny1*leny1+sum);
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