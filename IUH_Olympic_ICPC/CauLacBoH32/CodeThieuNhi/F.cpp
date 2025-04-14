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
    ll x1, p1, x2, p2; cin>>x1>>p1>>x2>>p2;
    double s1=log10(x1)+p1;
    double s2=log10(x2)+p2;      // cout<<s1<<"  "<<s2<<endl;
    if (s1<s2) cout<<"<"<<endl;
    else if (s1==s2) cout<<"="<<endl;
    else cout<<">"<<endl;
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