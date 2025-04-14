/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    ll n, k; cin>>n>>k;   
    if (k>(n+1)/2)
    {
      cout<<-1<<endl;
      return;
    }
    char a[100][100];
    ll j=0;
    for (ll i=0; i<n; i++)
      for (ll j=0; j<n; j++) a[i][j]='.';
  
    for (ll i=0; i<k; i++)
    {
      a[j][j]='R';
      j+=2;
    }
    for (ll i=0; i<n; i++)
    {
      for(ll j=0; j<n; j++) cout<<a[i][j];
      cout<<endl;
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}