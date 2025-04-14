/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000000;

ll luythua(ll a, ll n)
{
    if (n==1) return a;
    ll temp=luythua(a, n/2);
    if (n%2==0) return ((temp%mod)*(temp%mod))%mod;
    else return (((a%mod)*(temp%mod))%mod*(temp%mod))%mod;
}

void solve()
{
    ll n; cin>>n;  
    //cout<<luythua(2, n);       
    cout<<((n+1)%mod)*(luythua(2, n-2))%mod;
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