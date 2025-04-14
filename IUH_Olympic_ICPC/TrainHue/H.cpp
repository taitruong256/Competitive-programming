/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first+a.second>b.first+b.second;
}

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> a[n];
    for (ll i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a, a+n, comp);

    string ans="";
    ll nho=0;
    for (ll i=n-1; i>=0; i--)
    {
        ans=to_string((a[i].first+a[i].second+nho)%10)+ans;    //  cout<<a[i].first<<" "<<a[i].second<<endl;
        nho=(a[i].first+a[i].second+nho)/10;         
    }
    if (nho>0) ans=to_string(nho)+ans;
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