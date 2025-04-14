#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
string s;
vector<ll> pos;
ll first_pos=-1;

string del_str(string s)
{
    reverse(s.begin(), s.end());
    while (s.size()>1 && s.back()=='0') s.pop_back();
    reverse(s.begin(), s.end());
    return s;
}

string add_str(string s, ll len)
{
    reverse(s.begin(), s.end());
    while (s.size()<len) s.push_back('0');
    reverse(s.begin(), s.end());
    return s;
}

ll or_str(ll id, ll ans)
{
    // cout<<id<<" "<<ans<<endl;
    // for (ll i=0; i<pos.size(); i++) cout<<s[id+pos[i]]; cout<<endl;
    // for (ll i=0; i<pos.size(); i++) cout<<s[ans+pos[i]]; cout<<endl<<endl;
    for (ll i=0; i<pos.size(); i++) 
        if (s[id+pos[i]]>s[ans+pos[i]]) return true;
        else if (s[id+pos[i]]<s[ans+pos[i]]) return false;
    return false;
}

void solve()
{
    cin>>n;
    cin>>s;

    s=del_str(s);
    if (s=="0")
    {
        cout<<0;
        return;
    }

    n=s.size();
    for (ll i=0; i<n; i++) if (s[i]=='0') pos.push_back(i);
    if (pos.size()==0)
    {
        cout<<s;
        return;
    }
    ll len=n-pos[0];
    for (ll i=pos.size()-1; i>=0; i--) pos[i]-=pos[0];
    ll ans=0;
    for (ll i=1; i<n-len+1; i++) if (or_str(i, ans)) ans=i;
    string s1=s;
    string s2=s.substr(ans, len);
    s2=add_str(s2, n);
    string res;
    for (ll i=0; i<n; i++) 
        if (s1[i]=='0' && s2[i]=='0') res.push_back('0');
        else res.push_back('1');
    cout<<res;
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