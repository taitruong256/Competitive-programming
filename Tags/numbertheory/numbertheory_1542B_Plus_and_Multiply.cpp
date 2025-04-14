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
    ll n, a, b; cin>>n>>a>>b;
    if (a==1)
    {
        if ((n-1)%b==0)
        {
            cout<<"YES\n";
            return;
        }
        else 
        {
            cout<<"NO\n";
            return;
        }
    }
    else
    {
        ll t=1; 
        while (t<=n)
        {
            if (t%b==n%b)
            {
                cout<<"YES\n";
                return;
            }
            t*=a;
        }
        cout<<"NO\n";
    }
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