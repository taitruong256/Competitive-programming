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
    vector<ll> ans;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) cin>>a[i][j];
        for (ll j=1; j<=m; j++) b[j]=a[i][j];
        sort(b+1, b+m+1);
        if (b[1]==b[m]) continue;
        vector<ll> v;
        for (ll j=1; j<=m; j++) if (b[j]!=a[i][j]) v.push_back(j);
        // for (auto it: v) cout<<it<<" "; cout<<endl;
        if (i==1) for (ll i=0; i<v.size(); i++) ans.push_back(v[i]);
        else
        {
            if (ans.size()!=v.size())
            {
                cout<<-1<<endl;
                return;
            }
            else
            {
                for (ll i=0; i<v.size(); i++) if (ans[i]!=v[i])
                {
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    if (ans.size()>2)
    {
        cout<<-1<<endl;
        return;
    }
    else if (ans.size()==2)
    {
        cout<<ans[0]<<" "<<ans[1]<<endl;
        return;
    }
    else if (ans.size()==0)
    {
        cout<<1<<" "<<1<<endl;
        return;
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