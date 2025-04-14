/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

bool isprime(ll n)
{
    if (n<2) return false;
    for (ll i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}

void solve()
{
    ll n; cin>>n;
    if (n==1)
    {
        cout<<"FastestFinger\n";
        return;
    }
    if (n==2 || n%2==1)
    {
        cout<<"Ashishgup\n";
        return;
    }
    ll cnt=0;
    while (n%2==0) ++cnt, n/=2;
    if ((cnt==1 && isprime(n)==true) || n==1) cout<<"FastestFinger\n";
    else cout<<"Ashishgup\n";

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}