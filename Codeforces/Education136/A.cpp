#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n, m; cin>>n>>m; 
    if (n>=4 && m>=4)
    {
        cout<<n<<" "<<m<<endl;
        return;
    }
    else if (n==3 && m==3)
    {
        cout<<2<<" "<<2<<endl;
        return;
    }
    else if (n==3)
    {
        cout<<2<<" "<<m<<endl;
        return;
    }
    else if (m==3)
    {
        cout<<n<<" "<<2<<endl;
        return;
    }
    else 
    {
        cout<<n<<" "<<m<<endl;
        return;
    }
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