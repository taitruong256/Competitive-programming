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

string pref(string s)
{
    ll n=s.size();
    vector<ll> truoc(n+5, 0);
    ll j=0;
    for (ll i=1; i<n; i++)
    {
        while (j>0 && s[i]!=s[j]) j=truoc[j-1];
        if (s[i]==s[j]) ++j;
        truoc[i]=j;
    }
    return s.substr(0, j);
}

void solve()
{
    string s; cin>>s;           
    ll l=0, r=s.size()-1;
    while (l<r && s[l]==s[r]) ++l, --r;
    string t=s.substr(l, r-l+1);
    string x=t;
    reverse(x.begin(), x.end());
    string a=pref(t+"#"+x);
    string b=pref(x+"#"+t);
    if (a.size()<b.size()) a=b;
    cout<<s.substr(0, l)+a+s.substr(r+1)<<endl;
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