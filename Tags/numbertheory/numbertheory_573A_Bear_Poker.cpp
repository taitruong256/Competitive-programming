/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                   You may not be the best, but be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    set<ll> st;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        while (a[i]%6==0) a[i]/=6;
        while (a[i]%3==0) a[i]/=3;
        while (a[i]%2==0) a[i]/=2;
        st.insert(a[i]);
    }
    if (st.size()==1) cout<<"YES";
    else cout<<"NO";

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