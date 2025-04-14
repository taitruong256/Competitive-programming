/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll a, b; cin>>a>>b;
    if (b<a)
    {
        cout<<"NO";
        return;
    }
    vector<ll> ans;
    while (b>a)
    {   cout<<b<<endl;
        ans.push_back(b);
        if (b%2==0) b/=2;
        else if (b%10==1) b/=10;
        else 
        {
            cout<<"NO";
            return;
        }
    }
    ans.push_back(b);
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for (ll i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
}
 
int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; 
    while (t--) solve();
    return 0;
}
