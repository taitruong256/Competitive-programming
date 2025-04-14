/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    vector<ll> v;
    ll ans=0, cnt=0;
    for (ll i=0; i<n; i++) if (s[i]=='0') ++cnt;
    if (cnt==n) 
    {
        cout<<(cnt+k)/(k+1)<<endl;
        return;
    }

    ans=0, cnt=0;
    s='$'+s+'$';
    for (ll i=1; i<=n; i++) if (s[i]=='0')
    {         
        ll left=i-1;
        ll right=i;
        while (right<=n && s[right]=='0') ++right, ++cnt;
        if (s[left]=='1') cnt-=k;
        if (s[right]=='1') cnt-=k;       
        if (cnt>0) v.push_back(cnt); 
        cnt=0;
        i=right;
    }                     
    for (ll i=0; i<v.size(); i++) ans+=(v[i]+k)/(k+1);
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}