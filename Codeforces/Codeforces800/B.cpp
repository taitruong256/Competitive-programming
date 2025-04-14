/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    s=" "+s+" ";
    ll pref0[n+5], suff0[n+5], pref1[n+5], suff1[n+5];
    for (ll i=0; i<=n+1; i++) pref0[i]=suff0[i]=pref1[i]=suff1[i]=0;
    for (ll i=1; i<=n; i++) 
    {
        if(s[i]=='0') pref0[i]=pref0[i-1]+1;
        else pref0[i]=0;
        if(s[i]=='1') pref1[i]=pref1[i-1]+1;
        else pref1[i]=0;
    }
        
    for (ll i=n; i>=1; i--)
    {
        if (s[i]=='1') suff1[i]=suff1[i+1]+1;
        else suff1[i]=0;
        if (s[i]=='0') suff0[i]=suff0[i+1]+1;
        else suff0[i]=0;
    }
        
    ll ans=n;
    for (ll i=1; i<=n; i++) 
    { 
        if (s[i]=='1') 
        {      
            ans+=pref0[i-1];
            ans+=suff0[i+1];
        }
        // else 
        // {         
        //     ans+=pref1[i-1];
        //     ans+=(suff1[i+1]>0);
        // }
        // cout<<s[i]<<" "<<ans<<endl;
    }
    // for (ll i=1; i<=n; i++) cout<<pref0[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<suff0[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<pref1[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<suff1[i]<<" "; cout<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}