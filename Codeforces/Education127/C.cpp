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
    ll n, x; cin>>n>>x;
    ll a[n+5];
    ll sum=0, cnt=n, ans=0;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for (ll i=1; i<=n; i++) sum+=a[i];
    ll d=0;
    while (sum>0 && cnt>0)
    {
        while (sum>x && cnt>0) ++d, sum-=a[cnt]-d, --cnt;
        cout<<sum<<" "<<cnt<<endl;
        ans+=cnt;
        sum+=cnt;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}