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
    ll ans=1e18;
    ll cach1=(n+5)/6;

    ll cach2=n/8;
    ll m=n%8;
    ll cach2_6=0;
    if (m<=6) ++cach2_6;
    else ++cach2;

    ll cach3=n/10;
    m=n%10;
    ll cach3_6=0, cach3_8=0;
    if (m<=6) ++cach3_6;
    else if (m<=8) ++cach3_8;
    else ++cach3;         

    ans=min(ans, abs(cach1*6-n));
    ans=min(ans, abs(cach2*8+cach2_6*6-n));
    ans=min(ans, abs(cach3*10+cach3_6*6+cach3_8*8-n));

    if (ans==abs(cach1*6-n))
    {
        cout<<15*cach1<<endl;
        return;
    }
    else if (ans==abs(cach2*8+cach2_6*6-n))
    {
        cout<<20*cach2+15*cach2_6<<endl;
        return;
    }
    else if (ans==abs(cach3*10+cach3_6*6+cach3_8*8-n))
    {
        cout<<25*cach3+20*cach3_8+15*cach3_6<<endl;
        return;
    }
    //cout<<cach1<<" "<<cach2+cach2_6<<" "<<cach3+cach3_6+cach3_8<<endl;
    
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