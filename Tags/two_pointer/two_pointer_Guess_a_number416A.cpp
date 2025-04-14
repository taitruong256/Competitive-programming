#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll l=-2e9, r=2e9;

void solve()
{  
    ll n; cin>>n;
    while (n--)
    {
        string s, t;
        ll x;
        cin>>s>>x>>t; 
        if (t=="Y")
        {
            if (s=="<") r=min(r, x-1);
            else if (s==">") l=max(l, x+1);
            else if (s=="<=") r=min(r, x);
            else if (s==">=") l=max(l, x);
        }
        else
        {
            if (s=="<") l=max(l, x);
            else if (s==">") r=min(r, x);
            else if (s=="<=") l=max(l, x+1);
            else if (s==">=") r=min(r, x-1);
        }
        if (l>r)
        {
            cout<<"Impossible";
            return;
        }
    }    
    cout<<l;
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