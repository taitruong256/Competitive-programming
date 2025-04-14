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
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    if (n==1 && k>0)
    {
        cout<<-1;
        return;
    }
    if (n==1 && k==0)
    {
        cout<<1;
        return;
    }
    if (k<n/2)
    {
        cout<<-1;
        return;
    }
    vector<ll> v;
    ll x=k-(n-2)/2;
    map<ll, ll> cnt;
    v.push_back(x);
    v.push_back(2*x);
    ++cnt[x];
    ++cnt[2*x];
    ll i=1;
    while (v.size()<n)
    {
        while (cnt[i]!=0) ++i;
        ++cnt[i];
        v.push_back(i);
    }
    for (auto it: v) cout<<it<<" ";
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