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
    ll n, k; cin>>n;
    string s; cin>>s;
    if (n==1) 
    {
        cout<<s[0]<<s[0]<<endl;
        return;
    }
    else if (s[0]==s[1])
    {
        cout<<s[0]<<s[0]<<endl;
        return;
    }
    k=0;
    for (ll i=1; i<n; i++) if (s[i-1]>=s[i]) k=i; else break;
    for (ll i=0; i<=k; i++) cout<<s[i];
    for (ll i=k; i>=0; i--) cout<<s[i];cout<<endl;
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