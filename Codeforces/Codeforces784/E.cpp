/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    map<string, ll> cnt; 
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        string s; cin>>s;
        string t="";
        for (char a='a'; a<='k'; a++)
            for (char b='a'; b<='k'; b++) 
            {
                t=char(a);
                t=t+char(b);
                if (t!=s && cnt[t]>0 && (t[0]==s[0] || t[1]==s[1])) ans+=cnt[t];
            }
        ++cnt[s];
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
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}