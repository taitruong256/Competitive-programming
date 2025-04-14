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
string s; 
ll n;
ll l[2005], r[2005];

void check(ll x, ll y)
{
    while (x>=0 && y<n)
    {
        if (s[x]==s[y])
        {
            ++r[x];
            ++l[y];
            --x;
            ++y;
        }
        else break;
    }
}

void solve()
{
    cin>>s;
    n=s.size();
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    for (ll i=0; i<n; i++) check(i, i);
    for (ll i=0; i<n-1; i++) check(i, i+1);
    ll ans=0;
    for (ll i=0; i<n-1; i++)
        for (ll j=i+1; j<n ;j++) ans+=l[i]*r[j];
    cout<<ans;

    // for (ll i=0; i<n; i++) cout<<l[i]<<" "; cout<<endl;
    // for (ll i=0; i<n; i++) cout<<r[i]<<" "; cout<<endl;
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