/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m; 
ll a[105];
map<ll, ll> cnt;

bool check(ll x)
{
    if (x==0) return true;
    ll sum=0;
    for (auto it: cnt)  sum+=it.second/x;
    return sum>=n;
}

void solve()
{
    cin>>n>>m;
    
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        cnt[x]++;
    }
    ll l=0, r=1e9, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1; //cout<<l<<" "<<r<<endl;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}