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

ll tinh(ll n)
{
    ll p=5, cnt=0;
    while (p<=n)
    {
        cnt+=n/p;
        p*=5;
    }
    return cnt;
}

void solve()
{
    ll n; cin>>n;
    ll l=1, r=1e9, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (tinh(mid)>=n) ans=mid, r=mid-1;
        else l=mid+1;
    }
    if (ans==-1) cout<<-1;
    else 
    {
        vector<ll> v;
        while (tinh(ans)==n) v.push_back(ans), ans++;
        cout<<v.size()<<endl;
        for (auto it: v) cout<<it<<" ";
    }
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