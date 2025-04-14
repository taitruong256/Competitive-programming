#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    string s; cin>>s;
    ll i=0;
    set<char> st;
    s=s;
    while (i<s.size()) 
        if (s[i]==s[i+1]) i+=2;
        else 
        {
            st.insert(s[i]);
            ++i;
        }
    for (auto ch: st) cout<<ch;
    cout<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}
