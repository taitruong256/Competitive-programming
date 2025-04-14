/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

double luythua(double a, ll n)
{
    if (n==1) return a;
    double temp=luythua(a, n/2);
    if (n%2==0) return temp*temp;
    else return a*temp*temp;
}

double fibonaci(ll n)
{
    double f=1.0/sqrt(5);   printf("%lf\n", f);
    double a=(1.0+sqrt(5))/2;
    double b=(1.0-sqrt(5))/2;
    f=f*luythua(a, n+1)*luythua(b, n+1);
    return f;
}

void solve()
{
    ll n; cin>>n;
    printf("%lf\n", fibonaci(n));
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