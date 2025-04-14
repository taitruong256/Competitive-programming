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
    string s, t; cin>>s>>t;
    ll cnt_s[26], cnt_t[26];
    memset(cnt_s, 0, sizeof(cnt_s));
    memset(cnt_t, 0, sizeof(cnt_t));
    for (auto c: t) cnt_t[c-'a']++;
    ll ans=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]!='?') ++cnt_s[s[i]-'a'];
        // for (ll i=0; i<26; i++) cout<<cnt_s[i]<<" "; cout<<endl;
        if (i<t.size()-1) continue;
        --cnt_s[s[i-t.size()]-'a'];
        bool check=true;
        for (ll i=0; i<26; i++) if (cnt_s[i]>cnt_t[i])
        {
            check=false;
            break;
        }

        if (check==true) ++ans;
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