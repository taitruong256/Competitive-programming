#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
set<ll> st;

ll rev(ll x)
{
    ll res=0;
    while (x>0)
    {
        res*=2;
        res+=x&1;
        x/=2;
    }
    return res;
}

ll size(ll x)
{
    ll res=0;
    while (x>0)
    {
        ++res;
        x/=2;
    }
    return res;
}

void dfs(ll u)
{ 
    if (st.count(u) || size(u)>60) return;
    st.insert(u);
    dfs(rev(u*2));
    dfs(rev(u*2+1));
}

void solve()
{
    cin>>a>>b;
    dfs(a);
    for (auto it:st) cout<<it<<endl;
    if (st.count(b)) cout<<"YES";
    else cout<<"NO";
}

int main() {                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
