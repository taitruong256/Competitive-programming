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
ll n; 
ll a[1005], f[505][505], truoc[505][505];

string truyvet(ll i, ll j)
{        //cout<<i<<" "<<j<<endl;
  if (i==j)
    return 'A'+to_string(i);
  else if (j==i+1)
    return "(A"+to_string(i)+" X A"+to_string(j)+") ";
  else 
  {
    ll k=truoc[i][j];
    string s1=truyvet(i, k);
    string s2=truyvet(k+1, j);
    return "("+s1+ " X "+s2+") ";
  }
}

void solve()
{
    cin>>n;
    for (ll i=0; i<=n; i++) cin>>a[i];

    for (ll i=0; i<=n+1; i++)
      for (ll j=0; j<=n+1; j++) f[i][j]=1e9;

    for (ll i=0; i<=n; i++) f[i][i]=0;
    for (ll i=1; i<=n-1; i++) f[i][i+1]=a[i-1]*a[i]*a[i+1];

    for (ll m=2; m<=n-1; m++)
    {
      for (ll i=1; i<=n-m; i++)
      {
        ll j=i+m; 
        for (ll k=i; k<=j-1; k++) 
        {
          ll tong=f[i][k]+f[k+1][j]+a[i-1]*a[k]*a[j];
          if (tong<f[i][j])
          {
            f[i][j]=tong;
            truoc[i][j]=k;
          }
        }
      }
    }

    cout<<f[1][n]<<endl;
    cout<<truyvet(1, n);
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