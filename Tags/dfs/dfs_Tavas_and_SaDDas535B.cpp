/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d=0, ans=0;
vector<ll> v;

void dfs(ll x)
{ 
    if (x>1e10) return;
    v.push_back(x*10+4);
    dfs(x*10+4);
    v.push_back(x*10+7);
    dfs(x*10+7);
}

void solve()
{
    cin>>n;
    dfs(0);
    sort(v.begin(), v.end());
    //for (auto it: v) cout<<it<<endl;
    cout<<lower_bound(v.begin(), v.end(), n)-v.begin()+1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}