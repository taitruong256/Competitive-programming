#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
string s;

string or_str(string &a, string &b)
{
    string ans;
    reverse(b.begin(), b.end());
    while (b.size()<s.size()) b.push_back('0');
    reverse(b.begin(), b.end());
    for (ll i=0; i<a.size(); i++) if (a[i]=='0' && b[i]=='0') ans.push_back('0'); else ans.push_back('1');
    return ans;
}

void solve()
{
    cin>>n;
    cin>>s;
    reverse(s.begin(), s.end());
    while (s.size()>1 && s.back()=='0') s.pop_back();
    reverse(s.begin(), s.end());
    n=s.size();

    if (s=="0")
    {
        cout<<0;
        return;
    }

    ll pos=-1;
    for (ll i=0; i<n; i++) if (s[i]=='0')
    {
        pos=i;
        break;
    }
    if (pos==-1)
    {
        cout<<s;
        return;
    }
    ll len=n-pos;
    string ans=s.substr(n-1, 1);
    for (ll i=0; i<n-len+1; i++)
    {
        string t=s.substr(i, len);
        if (or_str(s, t)>or_str(s, ans)) ans=t;
    }
    cout<<or_str(s, ans);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}