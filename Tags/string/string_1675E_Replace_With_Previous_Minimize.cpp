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
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    if (k>26)
    {
        for (ll i=0; i<n; i++) cout<<'a';
        cout<<endl;
        return;
    }

    bool check[255];
    memset(check, false, sizeof(check));
    for (ll i=0; i<n; i++)
    {
        char c=s[i];
        while (c>'a' && k>0 && check[c]==false)
        {
            --k;
            check[c]=true;
            --c;
        }
    }
    for (ll i=0; i<n; i++)
    {
        while (s[i]>'a' && check[s[i]]==true) --s[i];
    }
    cout<<s<<endl;
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