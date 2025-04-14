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
    map<char, ll> cnt;
    ll mx=0;
    for (ll i=0; i<n; i++)
    {
        ++cnt[s[i]];
        mx=max(mx, cnt[s[i]]);
    }
    if (cnt.size()==1)
    {
        cout<<"YES\n";
        return;
    }
    if (mx==1)
    {
        cout<<"YES\n";
        return;
    }
    map<char, ll> cnt2;
    ll sl=cnt.size();
    for (char c='a'; c<='z'; c++)
    {
        cnt2.clear();
        for (char d: s)
        {
            if (d==c)
            {
                if (cnt2.size()<sl-1)
                {
                    cout<<"NO\n";
                    return;
                }
                cnt2.clear();
            }
            else ++cnt2[d];
        } 
    }
    cout<<"YES\n";
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