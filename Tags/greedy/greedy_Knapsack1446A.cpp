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
    ll n, w; cin>>n>>w;
    pair<ll, ll> a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i].first;
    for (ll i=0; i<n; i++) a[i].second=i+1;
    sort(a, a+n);   
    reverse(a, a+n);              
    ll s=0;
    vector<ll> ans;
    for (ll i=0; i<n; i++)
    {
        if (s+a[i].first<=w)
        {
            s+=a[i].first;     
            ans.push_back(a[i].second);
        }
        //else continue;
    }
    if (s>=(w+1)/2 && s<=w)
    {
        cout<<ans.size()<<endl;
        for (ll i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    else
    {
        cout<<-1<<endl;
        return;    
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}