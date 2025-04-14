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
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
 
    ll i=0;
    vector<ll> ans;
    map<ll, ll> cnt;
    for (ll i=0; i<n; i++) cnt[a[i]]++;
    ll k;
    bool visited[n+5];
    for (i=0; i<n; i=k+1)
    {    
        ll mex=0;  
        k=n-1;
        memset(visited, false, sizeof(visited));
        for (ll j=i; j<n; j++)
        {
            --cnt[a[j]];      //for (auto it: cnt) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
            visited[a[j]]=true;
            while (visited[mex]==true) ++mex;
            if (cnt[mex]==0) 
            {
                k=j;      
                break;
            }
        }
        
        ans.push_back(mex);
    }
 
    cout<<ans.size()<<endl;
    for (ll j: ans) cout<<j<<" "; cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_<<endl;
        solve();
    }
    return 0;
}
