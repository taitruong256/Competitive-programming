/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
string s, x;
ll f[10005][10005];

void truyvet(ll i, ll j)
{                          //cout<<i<<" "<<j<<" "<<s[i]<<" "<<x[j]<<endl;
    if (f[i][j]==0)  return;
    if (s[i]==x[j])
    {           
        truyvet(i-1, j-1);
        cout<<s[i];
    }
    else if (f[i][j]==f[i-1][j]) truyvet(i-1, j);
    else if (f[i][j]==f[i][j-1]) truyvet(i, j-1);
}

void solve()
{
    cin>>s>>x;
    s=" "+s;
    x=" "+x;
    ll n=s.size()-1, m=x.size()-1;
    for (ll i=0; i<=n; i++) f[i][0]=0;
    for (ll i=0; i<=m; i++) f[0][i]=0;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++) 
            if (s[i]==x[j]) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j], f[i][j-1]);

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=m; j++) cout<<f[i][j]<<" ";
    //     cout<<endl;
    // }
    
    cout<<f[n][m]<<endl;
    truyvet(n, m);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}