/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m; cin>>n;
    m=(ll)log2(n);
    ll a[n+5], sparse[n+5][20];
    memset(sparse, 1e9,sizeof(sparse));
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        sparse[i][0]=a[i];
    }
    for (ll j=1; j<=m; j++)
        for (ll i=1; i+(1<<j)-1<=n; i++)
            sparse[i][j]=min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
    
    for (ll j=0; j<=m; j++)
    {
        for (ll i=1; i<=n; i++) cout<<sparse[i][j]<<" "; cout<<endl;
    }

    ll q; cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll l, r; cin>>l>>r;   
        ++l, ++r;      // cout<<l<<" "<<r<<endl;
        ll length=r-l+1;
        ll k=(ll)log2(length);
        cout<<min(sparse[l][k], sparse[r-(1<<k)+1][k])<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}