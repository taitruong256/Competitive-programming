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
    int n, k; cin>>n>>k;
    int a[k];
    for (int i=0; i<k; i++) 
    {
        cin>>a[i];
        a[i]=abs(n-a[i]);
    }
    sort(a, a+k); 
    ll ans=0;
    for (int i=0; i<k; i++) if (a[i]<n) 
    {
        n-=a[i];
        ++ans;
    }
    cout<<ans<<endl;
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