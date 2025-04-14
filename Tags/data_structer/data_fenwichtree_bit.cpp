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
ll a[100005], bit[100005];

void update(ll index, ll val)
{
    while (index<=n)
    {
        bit[index]+=val;
        index+=index&(-index);
    }
}

ll getSum(ll index)
{
    ll sum=0;
    while (index>0)
    {
        sum+=bit[index];
        index-=index&(-index);
    }
    return sum;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=0; i<=n; i++) bit[i]=0;
    for (ll i=1; i<=n; i++) update(i, a[i]);
}   

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}