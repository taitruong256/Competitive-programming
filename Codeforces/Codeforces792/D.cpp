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

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
}

void solve()
{
    map<ll, bool> dau;
    ll n, k; cin>>n>>k;
    ll a[n+5];
    pair<ll, ll> b[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    // if (n==k)
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    
    for (ll i=0; i<n; i++) b[i].first=a[i], b[i].second=i;
    sort(b, b+n, comp);
    // for (ll i=0; i<n; i++) cout<<b[i].first<<" "; cout<<endl;
    
    bool danhdau[n+5];
    memset(danhdau, true, sizeof(danhdau));
    for (ll i=0; i<k; i++) danhdau[b[i].second]=false;
    // for (ll i=0; i<n ;i++) cout<<danhdau[i]<<" "; cout<<endl;
    ll ans=0, cnt=0;
    for (ll i=0; i<n; i++)
    {
        if (danhdau[i]==false) ++cnt;
        else ans+=a[i]+cnt;
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