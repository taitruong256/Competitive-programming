/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll p[n+5];
    for (ll i=0; i<n; i++) cin>>p[i];
    set<ll> st[4];
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        st[x].insert(p[i]);
    }
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        st[x].insert(p[i]);
    }

    // for (auto i: st)
    // {
    //     for (auto j: i) cout<<j<<" ";
    //     cout<<endl;
    // }

    ll m; cin>>m;
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        if (st[x].size()==0)
        {
            cout<<-1<<" ";
            continue;
        }
        ll it=*st[x].begin();
        cout<<it<<" ";
        for (ll i=1; i<=3; i++) if (st[i].find(it)!=st[i].end())
        {
            st[i].erase(it);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}