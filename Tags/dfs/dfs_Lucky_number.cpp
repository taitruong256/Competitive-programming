/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll sz, n, inf=0;
set<ll> s;

ll size(ll n)
{
    ll d=0;
    while (n>0) d++, n/=10;
    return d;
}

void dfs(ll x, ll count)
{         //  cout<<x<<" ---- "<<count<<endl;
    if (x<=inf)
    {
        if (x>=n && count==0) 
        {
            s.insert(x);
            return;
        }
        else
        {
            dfs(x*10+4, count+1);
            dfs(x*10+7, count-1);
        }
        
    }
}

void solve()
{
    cin>>n;
    sz=size(n);
    if (sz%2==1) ++sz;
    for (ll i=0; i<sz+2; i++) inf=inf*10+7;
    dfs(0, 0);    
    cout<<*s.begin();
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}