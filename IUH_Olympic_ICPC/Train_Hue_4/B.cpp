/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tinh(ll n, ll i)
{
    ll mu=(ll)pow(2, i);
    ++n;
    ll cnt=n/mu*(mu/2);
    n=n%mu-mu/2;
    if (n<=0) return cnt; 
    else return cnt+n;
}

void solve()
{
    ll a, b; cin>>a>>b;
    ll ans=0;
    // for (ll i=1; i<=32; i++) cout<<tinh(a-1, i)<<" "; cout<<endl;
    // for (ll i=1; i<=32; i++) cout<<tinh(b, i)<<" "; cout<<endl;

    for (ll i=1; i<=32; i++) if ((tinh(b, i)-tinh(a-1, i))%2==1) ans=ans+(ll)pow(2, i-1);
    cout<<ans<<endl;
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