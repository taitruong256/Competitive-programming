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
ll inf=1e18;
ll t[10005];

void solve()
{
    ll a, b, c, d; cin>>a>>b>>c>>d;
    for (ll i=0; i<=10000; i++)
    {
        ll t=a*i+b;
        if (t-d>=0 && (t-d)%c==0) 
        {
            cout<<t;
            return;
        }
    }
    cout<<-1;
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