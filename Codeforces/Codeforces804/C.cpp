/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n; cin>>n;
    ll a[n+5], b[n+5], cnta[n+5], cntb[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) b[i]=i;
    ll mexa=0, mexb=0;
    do 
    {
        bool check=true;
        for (ll x=0; x<n-1; x++)
            for (ll y=x+1; y<n; y++)
            {
                for (ll i=x; i<=y; i++)
                {
                    memset(cnta, 0, sizeof(cnta));
                    memset(cntb, 0, sizeof(cntb));
                    for (ll j=x; j<=y; j++) ++cnta[a[i]], ++cntb[b[i]];
                    for (ll j=0; j<n; j++) if (cnta[j]==0)
                    {
                        mexa=j;
                        break;
                    }
                    for (ll j=0; j<n; j++) if (cntb[j]==0)
                    {
                        mexb=j;
                        break;
                    }
                    if (mexa!=mexb) check=false;
                }
                if (check==true)
                {
                    for (ll i=0; i<n; i++) cout<<b[i]<<" "; cout<<endl;
                }
            }
    }
    while (next_permutation(b, b+n));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}