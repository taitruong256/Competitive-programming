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

void solve()
{
    ll a, b; cin>>a>>b; 
    if (a==1 && b>2)
    {
        cout<<-1<<endl;
        return;
    }
    if (b==1 && a>2) 
    {
        cout<<-1<<endl;
        return;
    }
    ll ans=0;
    if (a<b) swap(a, b);
    ans+=(b-1)*2;
    if ((a-b)%2==0) ans+=(a-b)*2;
    else ans+=(a-b)*2-1;
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