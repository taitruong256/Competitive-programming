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
ll ans=0;
ll n, k;
map<ll, vector<ll>> ban;

void check(ll x)
{           
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    for (ll p=0; p<n; p++) if (x&(1<<p)) visited[p+1]=true;
    bool kt=true;
    for (auto i: ban)
    {
        bool ok=false;
        for (auto j: i.second)
        {
            if (j>0 && visited[j]==true) ok=true;
            else if (j<0 && visited[-j]==false) ok=true;
        }
        if (ok==false) kt=false;
    }
    if (kt==true) 
    {
        ++ans;
        // for (ll i=n-1; i>=0; i--) if (x&(1<<i)) cout<<1; else cout<<0;
        // cout<<endl;
    }
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=k; i++)
    {
        ll sz; cin>>sz;
        for (ll j=0; j<sz; j++)
        {
            ll x; cin>>x;
            ban[i].push_back(x);
        }
    }
    for (ll i=0; i<(1<<n); i++) check(i);
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}