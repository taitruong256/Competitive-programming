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
    ll n, k; cin>>n>>k;
    string a, b; cin>>a>>b;
    map<char, ll> da, db;
    for (auto c: a) ++da[c];
    for (auto c: b) ++db[c];

    for (char c='a'; c<='z'; c++) 
    {
        ll use=da[c]-db[c];
        if(use<0 || use%k!=0)
        {
            cout<<"No\n";
            return;
        }
        da[c+1]+=use;
    }
    cout<<"Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}