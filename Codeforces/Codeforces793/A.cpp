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
    s=" "+s;
    set<char> st; 
    for (ll i=1; i<=n; i++) st.insert(s[i]);
    if (st.size()==1)
    {
        cout<<n<<endl;
        return;
    }
    
    for (ll i=1; i<=n/2; i++)
    {
        if (s[i]!=s[n-i+1])
        {
            cout<<0<<endl;
            return;
        }
    }
    // cout<<"lskdjfkslfjsk"<<endl;

    ll ans=0;
    if (n%2==0)
    {
        for (ll i=n/2; i>=1; i--) if (s[i]==s[n-i+1] && s[i]==s[n/2]) ans+=2;
        else break;
    }
    else
    {
        ans=1;
        for (ll i=n/2; i>=1; i--) if (s[i]==s[n-i] && s[i]==s[n/2]) ans+=2;
        else break;
    }
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