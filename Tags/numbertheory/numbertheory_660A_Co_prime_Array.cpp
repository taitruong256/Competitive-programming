/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll cnt=0;
    vector<ll> ans;
    for (ll i=1; i<=n-1; i++) 
    if (__gcd(a[i],a[i+1])>1)
        {
            ++cnt;
            ans.push_back(a[i]);
            ans.push_back(1);
        }
    else 
        {
            ans.push_back(a[i]);
        }
    ans.push_back(a[n]);
    cout<<cnt<<endl;
    for (auto it: ans) cout<<it<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}