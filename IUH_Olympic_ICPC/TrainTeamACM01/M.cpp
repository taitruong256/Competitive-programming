/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    ll mx=-1e18, mn=1e18, sum=0;
    for (ll i=0; i<n; i++) cin>>a[i];

    if (n==1)
    {
        cout<<a[0]<<endl;
        return;
    }

    for (ll i=0; i<n; i++)
    {
        mx=max(mx, a[i]);
        mn=min(mn, a[i]);
        sum+=abs(a[i]);
    }

    if (mn>0) sum-=2*mn;
    else if (mx<0) sum+=2*mx;
    cout<<sum<<endl;
}

bool cmp(pair<int, int> a, pair<ll, ll> b)
{
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

bool cmp(const pair<string,int>&c ,const pair<string,int>&b){
    return (c.second > b.second);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}