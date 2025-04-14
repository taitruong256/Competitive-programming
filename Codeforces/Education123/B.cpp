/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tong_csc(ll n, ll u, ll d)
{
    return n*u+n*(n-1)*d/2;  
}

void solve()
{
    ll n, b, x, y; cin>>n>>b>>x>>y;
    ll a[n+5];
    a[0]=0;
    ll sum=0;
    for (ll i=1; i<=n; i++)
    {
        if (a[i-1]+x<=b) a[i]=a[i-1]+x;
        else a[i]=a[i-1]-y;
        sum+=a[i];
    }
    cout<<sum<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}