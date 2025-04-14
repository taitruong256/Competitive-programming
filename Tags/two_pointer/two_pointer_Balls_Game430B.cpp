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
    ll n, k, x; cin>>n>>k>>x;
    ll a[n];
    for (ll i=0; i<n; i++) cin>>a[i];
    ll ans=0;
    for (ll i=0; i<n-1; i++)
    {
        ll l=i, r=i+1, now=x, count=1, s=0;
        while (true)
        {
            while (l>=0 && a[l]==now) 
            {                          
                --l;  
                ++count;
            }
            while (r<n && a[r]==now) 
            {
                ++r;
                ++count;
            }                             // cout<<"====  "<<l<<" "<<r<<" "<<count<<endl;
            if (count<=2) break;
            s+=count;
            ans=max(ans, s);
            if (l<0 || r>=n) break;
            now=a[l]; 
            count=0;
        }
        
                            //cout<<"------i, ans = "<<i<<" "<<ans<<endl;
    }
    cout<<max(0LL, ans-1);
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}