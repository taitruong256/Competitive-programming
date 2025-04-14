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
    if (a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}

void solve()
{
    ll n, m; cin>>n>>m;
    pair<ll, ll> a[m+5];
    for (ll i=1; i<=m; i++) cin>>a[i].first>>a[i].second;
    sort(a+1, a+m+1, comp);

    ll ans=0;
    for (ll i=1; i<=m; i++)
    {
        ll soluong=min(a[i].first, n);   //cout<<soluong<<endl;
        ans+=soluong*a[i].second;
        n-=soluong;
    }
    // for (ll i=1; i<=m; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}