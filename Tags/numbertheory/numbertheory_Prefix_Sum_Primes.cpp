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
    map<ll, ll> cnt;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x; 
        ++cnt[x];
    }
    if (cnt[1]==0)
        for (ll i=1; i<=n; i++) cout<<2<<" ";
    else if (cnt[2]==0)
        for (ll i=1; i<=n; i++) cout<<1<<" ";
    else 
    {
        cout<<"2 1 ";
        --cnt[2];
        --cnt[1];
        for (ll i=0; i<cnt[2]; i++) cout<<2<<" ";
        for (ll i=0; i<cnt[1]; i++) cout<<1<<" ";
    }
    cout<<endl;
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