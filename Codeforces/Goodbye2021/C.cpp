#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

void solve()
{               
    ll n; cin>>n;
    string s; cin>>s;
    string x="";
    set<string> st;
    for (ll i=0; i<s.size(); i++)
    {
        x=x+s[i];
        string t=x;
        reverse(t.begin(), t.end());
        st.insert(x+t);
    }
    
    cout<<*st.begin()<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;                 cin>>t;
    while (t--) solve();
    return 0;
}