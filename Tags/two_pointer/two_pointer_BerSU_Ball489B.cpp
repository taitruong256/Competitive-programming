#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
void solve()
{  
    ll n, m; cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    cin>>m;
    ll b[m];
    for (ll i=0; i<m; i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    ll i=0, j=0, ans=0;
    while (i<n && j<m)
    {    
        if (abs(a[i]-b[j])<=1)
        {
            ++ans;
            ++i;
            ++j;
        }
        else if (a[i]<b[j]) ++i;
        else ++j;
    }
    cout<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}