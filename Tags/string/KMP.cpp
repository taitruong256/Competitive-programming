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
    string t; cin>>t;
    ll n=s.size(), m=t.size();
    
    ll p[m+5];
    p[0]=-1;
    ll i=0, j=-1;
    while (i<m)
    {
        while (j>=0 && t[j]!=t[i]) j=p[j];
        ++i; ++j;
        p[i]=j;
    }
    
    i=0; j=0, ans=0;
    while (i<n)
    {
        while (j>=0 && t[j]!=s[i]) j=p[j];
        ++i; ++j;
        if (j==m) 
        {
            cout<<i-j+1<<" ";
            j=p[j];
        }
    }
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