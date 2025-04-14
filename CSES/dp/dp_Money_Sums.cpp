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
    ll a[n+5];
    bool d[100005];
    memset(d, false, sizeof(d));
    ll sum=0;
    for (ll i=0; i<n; i++) cin>>a[i], sum+=a[i];
    d[0]=true;
    for (ll i=0; i<n; i++)
        for (ll j=sum; j>=a[i]; j--) if (d[j-a[i]]==true) d[j]=true;
    // for (ll i=1; i<=sum; i++) cout<<d[i]<<" "; cout<<endl;
    vector<ll> ans;
    for (ll i=1; i<=sum; i++) if (d[i]==true) ans.push_back(i);
    cout<<(ll)ans.size()<<endl;
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