/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    string ans="";
    for (auto c: s)
    {
        if (!(ans.size()%2==1 && c==ans.back())) ans.push_back(c);
    }
    if (ans.size()%2==1) ans.pop_back();
    cout<<n-ans.size()<<endl;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; // cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_+1<<endl;
        solve();
    }
    return 0;
}

//taitruong256