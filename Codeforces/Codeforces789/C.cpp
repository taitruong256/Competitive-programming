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
int truoc[5001][5001], sau[5001][5001];

void solve()
{
    int n; cin>>n;
    int a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) truoc[i][j]=sau[i][j]=0;

    for (int i=1; i<=n; i++)
    {
        int cnt=0;
        for (int j=1; j<i; j++)
        {
            if (a[j]<a[i]) ++cnt;
            truoc[a[i]][j]=cnt;
        }
    }

    for (int i=n; i>=1; i--)
    {
        int cnt=0;
        for (int j=n; j>i; j--)
        {
            if (a[j]<a[i]) ++cnt;
            sau[a[i]][j]=cnt;
        }
    }

    ll ans=0;
    for (int i=2; i<=n-1; i++)
        for (int j=i+1; j<=n-1; j++) 
        {
            ans+=truoc[a[j]][i-1]*sau[a[i]][j+1];
        }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while (t--) solve();
    return 0;
}