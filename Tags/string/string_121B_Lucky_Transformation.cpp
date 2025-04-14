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
    ll n, k; 
    string s; 
    cin>>n>>k>>s;
    s=" "+s;
    for (ll i=1; i<n && k>0; i++) if (s[i]=='4' && s[i+1]=='7')
    {  
        --k;
        if (i%2==0)
        {
            s[i]=s[i+1]='7';
            i-=2;
            if (s[i+1]=='4') k%=2;
        }
        else 
            s[i]=s[i+1]='4';
    }
    for (ll i=1; i<=n; i++) cout<<s[i];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}