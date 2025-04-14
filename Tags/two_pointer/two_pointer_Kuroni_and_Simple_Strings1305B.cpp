#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    ll i=0, j=n-1;
    vector<ll> a, b;
    while (i<j)
    {
        while (i<j && s[i]==')') ++i;
        while (i<j && s[j]=='(') --j;
        if (i<j)
        {
            a.push_back(i+1);
            b.push_back(j+1);
            ++i; --j;
        }
    }
    if (a.size()==0) cout<<0<<endl;
    else 
    {
        cout<<1<<endl;
        cout<<a.size()*2<<endl;
        reverse(b.begin(), b.end());
        for (auto x: a) cout<<x<<" ";
        for (auto x: b) cout<<x<<" ";
    }
}

int main() 
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
