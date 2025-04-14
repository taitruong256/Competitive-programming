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
    string s; cin>>s;
    ll n=s.size();
    ll sum=0;
    for (ll i=0; i<n; i++) sum+=s[i]-'a'+1;
    if (n%2==0)
    {
        cout<<"Alice "<<sum<<endl;
        return;
    }
    else
    {
        if (n==1)
        {
            cout<<"Bob "<<sum<<endl;
            return;
        }
        else
        {
            ll x=min(s[0], s[n-1])-'a'+1;
            cout<<"Alice "<<sum-x-x<<endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}