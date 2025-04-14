/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll f[1000005];

void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    memset(f, 0, sizeof(f));
    for (ll i=a; i<=b; i++)
    {
        ++f[i+b];
        --f[i+c+1];
    }
    for (ll i=1; i<1000005; i++) f[i]+=f[i-1];
    for (ll i=1; i<1000005; i++) f[i]+=f[i-1];
    ll sum=0;
    for (ll i=c; i<=d; i++) cout<<f[i]<<" "; cout<<endl;
    cout<<f[1000005-1]<<endl;
    for (ll i=c; i<=d; i++) sum+=f[1000005-1]-f[i];
    cout<<sum;
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