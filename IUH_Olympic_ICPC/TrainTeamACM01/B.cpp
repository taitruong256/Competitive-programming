/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> minPrime;
map<ll, ll> tu, mau;

void phantich(ll n, map<ll, ll> &cnt)
{
    while (n>1) 
    {
        ++cnt[minPrime[n]];
        n /= minPrime[n];
    } 
}

void solve()
{
    ll n;
    cin>>n;
    tu.clear(); mau.clear();
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        phantich(x, tu);
    }
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        phantich(x, mau);
    }
    //for (auto it: tu) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
    //for (auto it: mau) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
    
    for (auto it: mau) it.second-=min(it.second, tu[it.first]);
    for (auto it: mau) cout<<it.first<<" "<<it.second<<endl;cout<<endl;
    for (auto it: mau) if ((it.first!=2 && it.first!=5) && it.second>0) 
    {
        cout<<"repeating\n";
        return;
    }
    cout<<"finite\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif

    //memset(minPrime, 0, sizeof(minPrime));
    n=1e6;
    minPrime.resize(n+5, 0);
    for (ll i = 2; i * i <= n; ++i) if (minPrime[i] == 0)
        for (ll j = i * i; j <= n; j += i) if (minPrime[j] == 0) minPrime[j] = i;

    for (ll i = 2; i <= n; ++i) if (minPrime[i] == 0) minPrime[i] = i;
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}