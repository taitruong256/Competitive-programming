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
#define ll int

void solve()
{
    ll n, m; cin>>n>>m;
    ll a[n+5][m+5], b[m+5];
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) cin>>a[i][j];

    vector<ll> ans, v;
    for (ll i=1; i<=n; i++)
    {
        v.clear();
        for (ll j=1; j<=m; j++) b[j]=a[i][j];
        sort(b+1, b+m+1);
        for (ll j=1; j<=m; j++) if (b[j]!=a[i][j]) v.push_back(j);
        if (v.size()==0) continue;
        if (v.size()>2)
        {                      //   cout<<"bbbbbbbb"<<endl;
            cout<<-1<<endl;
            return;
        }
        if (ans.size()==0)
            for (auto it: v) ans.push_back(it);
        else if (v.size()==ans.size())
            for (ll j=0; j<ans.size(); j++) if (v[j]!=ans[j]) 
            {                                       //  cout<<"eeeeee"<<endl;
                cout<<-1<<endl;
                return;
            }
    }

    
    if (ans.size()==0)
    {
        cout<<1<<" "<<1<<endl;
        return;
    }
    else
    {
        ll x=v[0], y=v[1];
        for (ll i=1; i<=n; i++) swap(a[i][x], a[i][y]);
        for (ll i=1; i<=n; i++) if (!is_sorted(a[i]+1, a[i]+m+1))
        {                     //  cout<<"dddddd"<<endl;
            cout<<-1<<endl;
            return;
        }               
        cout<<x<<" "<<y<<endl;
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