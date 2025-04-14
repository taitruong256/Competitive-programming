#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{           
    ll n; cin>>n;
    bool prime[1000001];
    for (ll i=0; i<=1000000; i++) prime[i]=true;
    prime[0]=prime[1]=false;
    for (ll i=2; i<=1000000; i++) if (prime[i]==true)
        for (ll j=i+i; j<=1000000; j+=i) prime[j]=false;
    
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        ll t=sqrt(x);
        if (prime[t] && t*t==x) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}