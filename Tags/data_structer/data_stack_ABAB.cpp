#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    ll t; cin>>t;
    while (t--)
    {
        string s; cin>>s;
        stack<char> st;
        for (ll i=0; i<s.size(); i++) 
            if (s[i]=='A') st.push('A');
            else if (s[i]=='B' && !st.empty()) st.pop();
            else st.push(s[i]);
        cout<<st.size()<<"\n";
    }
}
 
int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}