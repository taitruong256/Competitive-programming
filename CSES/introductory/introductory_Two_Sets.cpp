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
    bool d[n+5];
    memset(d, false, sizeof(d));
    ll s=n*(n+1)/2;
    if (s%2==1)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    s/=2;
    vector<ll> ans;
    for (ll i=n; i>=1; i--) if (s>=i) 
    {
        d[i]=true;
        s-=i;
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for (ll i=0; i<ans.size(); i++) cout<<ans[i]<<" "; cout<<endl;
    cout<<n-ans.size()<<endl;
    for (ll i=1; i<=n; i++) if (d[i]==false) cout<<i<<" "; 
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