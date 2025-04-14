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
    for (ll i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}

void solve()
{
    ll n; cin>>n;
    ll m=n;
    while (!isprime(m)) ++m;
    cout<<m<<endl;
    cout<<1<<" "<<n<<endl;
    for (ll i=1; i<n; i++) cout<<i<<" "<<i+1<<endl;
    for (ll i=1; i<=m-n; i++) cout<<i<<" "<<i+n/2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}