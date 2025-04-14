/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    ll a=0, b=0, l=0, ans=0;
    for (ll r=0; r<s.size(); r++)
    {
        if (s[r]=='a') ++a; else ++b;
        while (min(a, b)>k && l<r)
        {
            if (s[l]=='a') --a; else --b; 
            ++l;
        }
        ans=max(ans, a+b);
    }
    cout<<ans;
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