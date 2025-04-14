/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define mod 1000000007
#define ll int
ll cnt[200005];
ll n, k, q; 

void solve()
{
    cin>>n>>k>>q;
    
    //memset(cnt, 0, sizeof(cnt));
    for (ll i=0; i<n; i++)
    {
        ll l, r; cin>>l>>r;
        ++cnt[l];
        --cnt[r+1];
    }
    for (ll i=1; i<=200005; i++) cnt[i]+=cnt[i-1];
    for (ll i=1; i<=200005; i++) cnt[i]=cnt[i-1]+(cnt[i]>=k);

    for (ll i=0; i<q; i++)
    {
        ll l, r; cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}