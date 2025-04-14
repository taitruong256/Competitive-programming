/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;       //  cout<<"---"<<n;
    ll s=n*(n+1)/2; 
    if (s%2==1)
    {
        cout<<"NO";          
    }
    else
    {
        cout<<"YES\n";
        vector<ll> ans;
        s/=2;
        bool dau[n+5];
        for (ll i=1 ;i<=n; i++) dau[i]=true;
        for (ll i=n; i>=1; i--) if (s>=i)
        {
            ans.push_back(i);
            dau[i]=false;
            s-=i;
        }
        reverse(ans.begin(), ans.end());
        cout<<n-ans.size()<<endl;
        for (ll i=1; i<=n; i++) if (dau[i]==true) cout<<i<<" ";cout<<endl;
        cout<<ans.size()<<endl;
        for (auto it: ans) cout<<it<<" "; cout<<endl;
        
    }             
     //   cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    // ll t; cin>>t;
    // while (t--)
    solve();
    return 0;
}