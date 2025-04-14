/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    ll cach1=0, cach3=-1;
    double cach2=0;
    for (ll i=0; i<n; i++)
    {
        cin>>a[i];
        cach1+=abs(a[i]);
        cach2+=a[i]*a[i];
        cach3=max(cach3, abs(a[i]));
    }
    cach2=sqrt(cach2);
    printf("%ld\n", cach1);
    printf("%.15lf\n", cach2);
    printf("%ld\n", cach3);
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