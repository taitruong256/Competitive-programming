/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s; 
ll n; 
map<char, ll> cnt;
 
bool check(ll x)
{
    if (x==0) return true;
    ll sum=0;
    for (auto c: cnt) sum+=(c.second+x-1)/x;         
    return sum>n;
}
 
void solve()
{
    cin>>s>>n;
    for (auto c: s) ++cnt[c];
 
    if (n<cnt.size())
    {
        cout<<-1;
        return;
    }
 
    ll l=0, r=1e9, ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1; 
        if (check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
    }
    ++ans;
    cout<<ans<<endl;
    
    string kq="";
    for (auto c: cnt)
        for (ll i=0; i<(c.second+ans-1)/ans; i++) kq+=c.first;
    while (kq.size()<n)  kq='a'+kq;
    cout<<kq;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;
    while (t--) solve();
    return 0;
}
