#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second-a.first<b.second-b.first;
}

void solve()
{               
    ll n; cin>>n;
    ll a[n+1];
    for (ll i=1; i<=n; i++) cin>>a[i];
    set<ll> s[4];
    for (ll i=1; i<=n; i++) 
    {
        ll x; cin>>x;
        s[x].insert(a[i]);
    }
    for (ll i=1; i<=n; i++) 
    {
        ll x; cin>>x;
        s[x].insert(a[i]);
    }

    ll m; cin>>m;
    for (ll i=1; i<=m; i++) 
    {
        ll x; cin>>x;
        if (s[x].empty())
        {
            cout<<-1<<" ";
            continue;
        }
        ll p=*s[x].begin();
        cout<<p<<" ";
        for (ll i=1; i<=3; i++) 
            if (s[i].find(p)!=s[i].end()) 
                s[i].erase(s[i].find(p));
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;              //   cin>>t;
    while (t--) solve();
    return 0;
}