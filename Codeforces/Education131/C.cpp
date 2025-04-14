/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n, m; 
ll a[200005];
vector<pair<ll, ll>> v;
map<ll, ll> cnt;

bool check(ll x)
{
    ll congviec=m, thua=0;
    for (ll i=0; i<v.size(); i++)
    {
        if (v[i].first>=x) thua+=v[i].first-x, congviec-=x;
        else congviec-=v[i].first, congviec-=(x-v[i].first)/2;
    }
    return congviec<=0;
}

void solve()
{
    v.clear();
    cnt.clear();
    cin>>n>>m; 
    for (ll i=1; i<=m; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) ++cnt[a[i]];
    for (ll i=1; i<=n; i++) v.push_back({cnt[i], i});
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    // for (auto it: v) cout<<it.first<<" "<<it.second<<endl;

    ll l=0, r=1e9, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}