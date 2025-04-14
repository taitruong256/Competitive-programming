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
    ll n; cin>>n;
    stack<string> st;
    map<string, ll> mp;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        st.push(s);
    }
    while (st.size()>0)
    {
        if (mp[st.top()]==0) 
        {
            cout<<st.top()<<endl;
            mp[st.top()]=1;
        }
        st.pop();
    }
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