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

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    a[0]=a[n+1]=1e9;
    ll ans1=1e9;
    for (ll i=1; i<n; i++) ans1=min(ans1, (a[i]+a[i+1]+2)/3);
    ll ans2=1e9;
    for (ll i=1; i<=n; i++)
    {
        ll tam=0;
        tam=(a[i]+1)/2; 
        tam+=(max(min(a[i-1], a[i+1])-tam, 0LL)+1)/2;
        tam=min(tam, max(a[i-1], a[i+1]));
        ans2=min(ans2, tam);             //cout<<i<<" "<<tam<<endl;
    }
    ll ans3=1e9;
    sort(a+1, a+n+1);
    ans3=min(ans3, (a[1]+1)/2+(a[2]+1)/2);
    // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    cout<<min({ans1, ans2, ans3});
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