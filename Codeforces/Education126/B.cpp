/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=32768;

ll uoc2(ll n)
{
    ll cnt=0;
    while (n%2==0) n/=2, ++cnt; 
    return cnt; 
}

ll tinh(ll n)
{
    ll mx=0, toiuu=n;
    for (ll i=1; i<16; i++)
    {
        if (uoc2(n+i)-uoc2(i)-i>mx) mx=uoc2(n+i)-uoc2(i)-i, toiuu=n+i;
    }
    return toiuu;
}

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];

    for (ll i=0; i<n; i++)
    {
        ll ans=0;
        while (a[i]%mod!=0)
        {
            if (tinh(a[i])==a[i]) ++ans, a[i]*=2;
            else ans+=tinh(a[i])-a[i], a[i]=tinh(a[i]);
            cout<<a[i]<<endl;
        }
        cout<<ans<<" ";
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