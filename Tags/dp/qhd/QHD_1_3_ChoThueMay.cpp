/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second<b.second;
}

void solve()
{
    ll n; cin>>n;
    vector<pair<ll, ll>> v;
    ll c[n+5];
    for (ll i=0; i<n; i++)
    {
        ll st, fi; cin>>st>>fi;
        v.emplace_back(st, fi);
        cin>>c[i];
    }
    sort(v.begin(), v.end(), cmp);
    //for (auto it: v) cout<<it.first<<" "<<it.second<<endl;
    ll f[n+5];
    for (ll i=0; i<n; i++) f[i]=c[i];
    for (ll i=0; i<n; i++)
    {
        for (ll j=0; j<i; j++) if (v[j].second<=v[i].first && f[i]<f[j]+1) f[i]=f[j]+c[i];
    }

    //for (ll i=0; i<n; i++) cout<<f[i]<<" "; cout<<endl;
    cout<<*max_element(f, f+n); 
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