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
    ll l1, l2, l3; cin>>l1>>l2>>l3;
    if (l1==l2+l3 || l2==l1+l3 || l3==l1+l2)
    {
        cout<<"YES\n";
        return;
    }
    if (l1==l2 && l3%2==0)
    {
        cout<<"YES\n";
        return;
    }
    if (l2==l3 && l1%2==0)
    {
        cout<<"YES\n";
        return;
    }
    if (l1==l3 && l2%2==0)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif  
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}