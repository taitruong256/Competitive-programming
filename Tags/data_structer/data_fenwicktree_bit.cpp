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
ll n; 
ll a[100005], pref[100005], value[100005];

void update_bit(ll bit[], ll index, ll val)
{
    while (index<=n)
    {
        bit[index]+=val;
        index+=index&(-index);
    }
}

ll getSum_bit(ll bit[], ll index)
{
    ll sum=0;
    while (index>0)
    {
        sum+=bit[index];
        index-=index&(-index);
    }
    return sum;
}

ll build_bit(ll bit[], ll a[])
{
    for (ll i=0; i<=n; i++) bit[i]=0;
    for (ll i=1; i<=n; i++) update_bit(bit, i, a[i]);
}

void update_range(ll l, ll r, ll val)
{
    update_bit(pref, l, val*(n-l+1));
    update_bit(pref, r+1, -val*(n-r));
    update_bit(value, l, val);
    update_bit(value, r+1, -val);
}

ll prefixSum(ll index) {
    return getSum_bit(pref, index) - (n-index) * getSum_bit(value, index);
}

ll getSum_range(ll l, ll r)
{
    return prefixSum(r)-prefixSum(l-1);
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    build_bit(pref, a);
    build_bit(value, a);

    cout<<endl;
    for (ll i=1; i<=n; i++) cout<<value[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<pref[i]<<" "; cout<<endl;
    // update_range(1, 5, 5);
    for (ll i=1; i<=n; i++) cout<<value[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<pref[i]<<" "; cout<<endl;
    cout<<getSum_bit(pref, 4)<<endl;
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