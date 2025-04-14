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

void solve()
{
    ll n, m, q; cin>>n>>m>>q;
    string s; cin>>s;
    s=" "+s;
    vector<vector<ll>> ds(m+5, vector<ll> (4, 0));
    ds[0]={1, n, 1, n};
    ll last=n+1;
    for (ll i=1; i<=m; i++)
    {
        ll l, r; cin>>l>>r;
        ds[i]={last, last+r-l, l, r};
        last+=r-l+1;
    }

    while (q--)
    {
        ll x; cin>>x;
        ll ans=0;
        while (x>n)
        {
            ll l=0, r=m;
            while (l<=r)
            {
                ll mid=(l+r)/2;
                if (x>=ds[mid][0]) ans=mid, l=mid+1;
                else r=mid-1;
            }           
            x=ds[ans][2]+x-ds[ans][0];
        }
        cout<<s[x]<<endl;
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