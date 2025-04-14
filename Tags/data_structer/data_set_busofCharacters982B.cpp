#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;
    ll a[n+1];
    map<ll, ll> index;
    stack<ll> st;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        index[a[i]]=i;
    }
    sort(a+1, a+n+1);
    ll l=1;
    string s; cin>>s;
    for (ll i=0; i<s.size(); i++)
    {  
        if (s[i]=='0') 
        {
            cout<<index[a[l]]<<" ";
            st.push(a[l]);
            ++l;
        }
        else
        {
            if (!st.empty())
            {     
                cout<<index[st.top()]<<" ";
                st.pop();
            }
        }
    }

}

int main() {                   
    FAST;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
