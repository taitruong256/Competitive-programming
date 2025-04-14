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
    map<char, ll> cnt_doan;
    set<char> st;
    for (auto c: s) st.insert(c);
    if (st.size()==1)
    {
        cout<<"YES\n";
        return;
    }
    for (auto c: st)
    {
        cnt_doan.clear();
        ll l=0, r=n-1;
        while (s[l]!=c && l<n) ++l;
        while (s[r]!=c && r>=0) --r; // cout<<c<<" "<<l<<" "<<r<<endl;
        if (l>r)
        {
            cout<<"NO\n";
            return;
        }
        for (ll i=l; i<=r; i++) ++cnt_doan[s[i]];
        for (auto x: st)
            for (auto y: st)
            {
                ll u=max(cnt_doan[x], cnt_doan[y]);
                ll v=min(cnt_doan[x], cnt_doan[y]);
                if (u-v>1)
                {
                    cout<<"NO\n";
                    return;
                }
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