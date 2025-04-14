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
    ll l, r, k; cin>>l>>r>>k;
    if (l==r && l>1)
    {
        cout<<"YES\n";
        return;
    }
    if (l%2==0) ++l;
    if (r%2==0) --r;
    ll cnt=(r-l)/2+1;
    if (k>=cnt) cout<<"YES\n";
    else cout<<"NO\n";
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