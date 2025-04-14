/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll giaithua[1000];

void solve()
{
    ll n; cin>>n;
    if (n%2==1) cout<<0<<endl;
    else
    {
        n/=2;
        cout<<((giaithua[n]%mod)*(giaithua[n]%mod))%mod<<endl;    
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    giaithua[0]=1;
    for (ll i=1; i<=1000; i++) giaithua[i]=((giaithua[i-1])%mod*(i%mod))%mod;
    //for (ll i=1; i<=500; i++) cout<<giaithua[i]<<" ";
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}