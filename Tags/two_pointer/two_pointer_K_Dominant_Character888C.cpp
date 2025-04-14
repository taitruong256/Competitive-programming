#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{  
    string s; cin>>s;
    ll ans=1e9;
    set<char> st;
    for (ll i=0; i<s.size(); i++) st.insert(s[i]);

    for (auto c:st)
    {
        ll last=-1, mx=0;
        s=s+c; 
        for (ll i=0; i<s.size(); i++) if (s[i]==c)
        {
            mx=max(mx, i-last);  
            last=i;
        }
        ans=min(ans, mx);
        s.erase(s.size()-1, 1); 
    }
    cout<<ans;
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