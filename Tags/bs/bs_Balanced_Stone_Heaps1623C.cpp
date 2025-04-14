/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll n;
vector<ll> a;
bool check(ll x)
{
    vector<ll> cur(a.begin(), a.end());
    for (ll i=n-1; i>=2; i--)
    {
        if (cur[i]<x) return false;
        ll d=min(cur[i]-x, a[i])/3;
        cur[i-1]+=d;
        cur[i-2]+=d*2;
        cur[i]-=3*d;
    }  //cout<<"mid = "<<x<<endl; for(ll i=0; i<n; i++) cout<<cur[i]<<" "; cout<<endl;
    return (cur[0]>=x && cur[1]>=x);
}

void solve()
{
    cin>>n;
    a.clear();
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        a.push_back(x);
    } 
    
    ll l=0, r=*max_element(a.begin(), a.end()), ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}