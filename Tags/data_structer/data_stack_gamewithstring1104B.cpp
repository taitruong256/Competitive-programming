#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    string s; cin>>s;
    stack<char> st;
    bool winner=false;
    for (ll i=0; i<s.size(); i++)
    {
        if (st.empty()) st.push(s[i]);
        else if (st.top()==s[i]) st.pop(), winner=!winner;
        else st.push(s[i]);
    }
    if (winner==false) cout<<"NO"; else cout<<"YES";
}

int main() {                   
    FAST;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
