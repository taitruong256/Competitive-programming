/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<string> st;

void dequy(string s, ll k)
{
    if (k==0) return;
    st.insert(s);         //cout<<s<<endl;
    string x=s;
    reverse(x.begin(), x.end());
    dequy(s+x, k-1);
    dequy(x+s, k-1);
}

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    st.clear();
    st.insert(s);
    set<char> cnt;    
    for (auto it: s) cnt.insert(it);      //cout<<cnt.size()<<endl;
    // if (cnt.size()==1)       
    // {        
    //     cout<<1<<endl;
    //     return;
    // }
    // if (k<2) cout<<1<<endl;
    // else cout<<2<<endl;
     dequy(s, k);

    set<string> st2;
    for (auto it: st) if (it.size()==n*pow(2, k-1)) st2.insert(it);
    cout<<st2.size()<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}