/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
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
{            //   cout<<i<<" "<<j<<endl;
    if (f[i][j]==0) return;
    if (f[i][j]==f[i+1][j-1]) truyvet(i+1, j-1);
    else if (f[i][j]==f[i+1][j]+1)
    {
        truyvet(i+1, j);
        cout<<s[i];
    }
    else if (f[i][j]==f[i][j-1]+1)
    {
        truyvet(i, j-1);
        cout<<s[j]<<" ";
    }
}

void solve()
{
    cin>>s;
    s=" "+s;  //cout<<s<<endl;
    ll n=s.size()-1;
    memset(f, 1e9, sizeof(f));
    for (ll i=0; i<=n+1; i++) f[i][i]=0;
    for (ll i=n; i>=1; i--) 
        for (ll j=i+1; j<=n; j++) 
            if (s[i]==s[j]) f[i][j]=f[i+1][j-1];
                else f[i][j]=min(f[i+1][j], f[i][j-1])+1;

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) cout<<f[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<f[1][n]<<endl;
    truyvet(1, n);
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