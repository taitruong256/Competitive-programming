/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    if (n==1)
    {
        cout<<1;
        return;
    }
    set<ll> st;
    for (ll i=2; i*i<=n; i++) if (n%i==0)
    {
        st.insert(i);
        while (n%i==0) n/=i;
    }
    if (n>1) st.insert(n);
    if (st.size()>1) cout<<1;
    else cout<<*st.begin();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}