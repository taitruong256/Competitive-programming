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
    ll n, m; cin>>n>>m;
    if (n==m) cout<<n*n-n+1<<endl;
    else if (n>m)
    {
        if (n%2==0) cout<<n*n-m+1<<endl;
        else cout<<(n-1)*(n-1)+m<<endl;
    }
    else
    {
        if (m%2==0) cout<<(m-1)*(m-1)+n<<endl;
        else cout<<m*m-n+1<<endl;
    }
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