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
    
    cout<<n<<endl;
    for (ll i=1; i<=n; i++)
        for (ll j=i; j<=n; j++) if (i*i+i*(2*j+1)+1==n)
            cout<<i<<" "<<j<<endl;
    cout<<endl;

    // if (n<=4 || n%2==0) cout<<"NO";
    // else cout<<1<<" "<<(n-3)/2;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--)
    solve();
    return 0;
}