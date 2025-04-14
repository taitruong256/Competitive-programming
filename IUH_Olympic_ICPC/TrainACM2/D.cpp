/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    string s; cin>>s;
    stack<char> st;
    ll cnt=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (st.size()==0)
        {
            st.push(s[i]);
            continue;
        }
        if (s[i]==st.top())
        {
            ++cnt;
            st.pop();
        }
        else st.push(s[i]);
    }                 
    if (cnt%2==1) cout<<"Yes"; else cout<<"No";
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