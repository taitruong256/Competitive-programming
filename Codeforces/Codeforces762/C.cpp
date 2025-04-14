#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    ll a, s; cin>>a>>s;
    if (s<a)
    {
        cout<<-1<<endl;
        return;
    }
    string ans="";
    while (s>0)
    {
        ll x=a%10, y=s%10;
        a/=10; s/=10;
        if (x>y) 
        {
            y=(s%10)*10+y;
            s/=10;
        }
        if (y-x>=0 && y-x<=9) ans=to_string(y-x)+ans;
        else 
        {
            cout<<-1<<endl;
            return;
        }
    }
    if (a>0)
    {
        cout<<-1<<endl;
        return;
    }
    while (ans[0]=='0') ans.erase(0, 1);
    cout<<ans<<endl;
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
