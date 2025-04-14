/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    bool prime[100005];
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=false;
    for (ll i=2; i<100005; i++) if (prime[i]) if (prime[i]==true)
        for (ll j=i*i; j<100005; j+=i) prime[j]=false;
    
    ll n, m; cin>>n>>m;
    ll row[n+5], col[m+5];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<m; j++) 
        {
            ll x; cin>>x;
            while (!prime[x])
            {
                ++x;
                ++row[i];
                ++col[j];
            }
        }
    }
    cout<<min(*min_element(row, row+n), *min_element(col, col+m));
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}