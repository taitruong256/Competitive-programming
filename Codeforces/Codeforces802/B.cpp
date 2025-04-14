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

void tinh(string a, string b)
{

}

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    string ans;
    
    if (s[0]=='9') 
    {
        string sum;
        for (ll i=0; i<n+1; i++) sum.push_back('1');
        s="0"+s;
        ll nho=0;
        for (ll i=n; i>=0; i--)
        {
            ll hieu=sum[i]-s[i]-nho;
            if (hieu<0)
            {
                hieu+=10;
                nho=1;
            }
            else nho=0;   //  cout<<hieu<<endl;
            char t=hieu+'0';   
            ans=t+ans;
            // cout<<ans<<endl;
        }
        for (ll i=1; i<n+1; i++) cout<<ans[i]; cout<<endl;
    }
    else 
    {
        for (ll i=0; i<n; i++) ans.push_back('9');
        for (ll i=s.size()-1; i>=0; i--) ans[i]='0'+ans[i]-s[i];
        cout<<ans<<endl;
    }
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