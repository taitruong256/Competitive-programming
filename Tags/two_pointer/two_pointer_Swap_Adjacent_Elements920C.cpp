#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n; cin>>n; 
    ll a[n+1];
    for (ll i=1; i<=n; i++) cin>>a[i];
    string s; cin>>s;

    ll j=0;
    for (ll i=0; i<n-1; i++)
    {
        j=i;
        while (s[j]=='1') ++j;
        sort(a+i, a+j+1);
        i=j;
    }
    if (is_sorted(a, a+n)) cout<<"YES"; else cout<<"NO";
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}