#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    ll p[m+5];
    for (ll i=0; i<m; i++) cin>>p[i];   // cin m not n

    ll l=0, count=0, ans=0;  
    while (l<m)
    {
        ll r=l, index=((p[r]-count-1)/k+1)*k+count;  // cout<<"last page: "<<index<<endl;
        while (r<m && p[r]<=index)
        {
            ++count;
            ++r;
        }
        ++ans;
        l=r;
    }
    cout<<ans<<endl;
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