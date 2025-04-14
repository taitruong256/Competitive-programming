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
    map<char, ll> cnt;
    set<char> st;
    ll n; cin>>n;
    string s; cin>>s;
    for (auto c: s) st.insert(c);
    ll now=0, ans=1e9, d=st.size();
    ll l=0;
    for (ll r=0; r<n; r++)
    {
        
        if (cnt[s[r]]==0) ++now;
        ++cnt[s[r]];
        if (now>=d) 
        {
            ans=min(ans, r-l+1);
            while (l<r && now>=d)
            {
                if (cnt[s[l]]==1) --now;
                --cnt[s[l]];
                ++l;
                if (now>=d) ans=min(ans, r-l+1);
            }
        }
        cout<<now<<" "<<ans<<" "<<l<<endl;
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
    solve();
    return 0;
}