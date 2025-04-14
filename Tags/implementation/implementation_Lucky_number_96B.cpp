/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

ll size(ll n)
{
    ll d=0;
    while (n>0) d++, n/=10;
    return d;
}

void solve()
{
    ll n; cin>>n;
    string s; 
    while (true)
    {
        s+="47";
        sort(s.begin(), s.end());
        do
        {
            if (stoll(s)>=n) 
            {
                cout<<s;
                return;
            }
        }while (next_permutation(s.begin(), s.end()));
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}