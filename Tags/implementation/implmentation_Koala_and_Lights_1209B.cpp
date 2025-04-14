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
    string s; cin>>s;
    ll a[n+5], b[n+5];
    vector<int> ans(5005, 0);
    for (ll i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        ll on=s[i]-'0';
        for (ll j=0; j<5000; j++) 
        {
            if (j>=b[i] && (j-b[i])%a[i]==0) on^=1;
            ans[j]+=on;
        }
    }
    cout<<*max_element(ans.begin(), ans.end());
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