/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                   You may not be the best, but be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll a, b; cin>>a>>b;
    ll g=__gcd(a, b);
    a/=g;
    b/=g;
    ll ans=0;
    while (a%5==0) a/=5, ++ans;
    while (a%3==0) a/=3, ++ans;
    while (a%2==0) a/=2, ++ans;
    while (b%5==0) b/=5, ++ans;
    while (b%3==0) b/=3, ++ans;
    while (b%2==0) b/=2, ++ans;
    if (a!=1 || b!=1) ans=-1;
    cout<<ans;
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