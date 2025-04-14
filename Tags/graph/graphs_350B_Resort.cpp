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
    ll type[n+5], par[n+5], out[n+5];
    memset(par, 0, sizeof(par));
    memset(out, 0, sizeof(out));
    for (ll i=1; i<=n; i++) cin>>type[i];
    for (ll i=1; i<=n; i++)
    {
        cin>>par[i];
        ++out[par[i]];
    }
    vector<ll> ans, now;
    for (ll i=1; i<=n; i++) if (type[i]==1)
    {
        now.clear();
        for (ll j=i; j!=0; j=par[j])
        {
            if (out[j]>1) break;
            now.push_back(j);
        }
        if (now.size()>ans.size()) ans=now;
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    for (auto it: ans) cout<<it<<" ";
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