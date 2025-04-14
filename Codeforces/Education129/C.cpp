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

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].first;
    for (ll i=1; i<=n; i++) cin>>a[i].second;
    vector<pair<ll, ll>> ans;
    for (ll i=1; i<=n; i++)
        for (ll j=i+1; j<=n; j++) if (a[i].first>=a[j].first && a[i].second>=a[j].second)
        {
            pair<ll, ll> tam=a[i];
            a[i]=a[j];
            a[j]=tam;
            ans.push_back({i, j});
        }

    // for (ll i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
    // cout<<endl;
    
    if (n==1)
    {
        cout<<0<<endl;
        return;
    }
    for (ll i=2; i<=n; i++) if (a[i].first<a[i-1].first || a[i].second<a[i-1].second)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for (ll i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
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