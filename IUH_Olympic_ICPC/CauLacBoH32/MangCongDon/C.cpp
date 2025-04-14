/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005], l[100005], r[100005], d[100005], tong1[100005], tong2[100005];

void solve()
{
    ll n, m, k; cin>>n>>m>>k;
    
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=m; i++) cin>>l[i]>>r[i]>>d[i];
    for (ll i=0; i<100005; i++) tong1[i]=0;
    for (ll i=0; i<100005; i++) tong2[i]=0;

    for (ll i=1; i<=k; i++)
    {
        ll x, y; cin>>x>>y;
        tong1[x]++;
        tong1[y+1]--;
    }
    for (ll i=1; i<=m; i++) tong1[i]+=tong1[i-1];
    //for (ll i=1; i<=n; i++) cout<<tong1[i]<<" "; cout<<endl;

    for (ll i=1; i<=m; i++)
    {
        tong2[l[i]]+=tong1[i]*d[i];
        tong2[r[i]+1]-=tong1[i]*d[i];
    }
    for (ll i=1; i<=n; i++) tong2[i]+=tong2[i-1];
    //for (ll i=1; i<=n; i++) cout<<tong2[i]<<" "; cout<<endl;

    for (ll i=1; i<=n; i++) cout<<tong2[i]+a[i]<<" ";
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