/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5], l[n+5], r[n+5], ans[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i];

    stack<ll> st;
    ll mx=0, index=1;
    a[0]=l[0]=r[0]=0;
    st.push(0);
    for (ll i=1; i<=n; i++)
    {
        while (!st.empty() && a[st.top()]>a[i]) st.pop();
        ll truoc=st.top();
        l[i]=l[truoc]+a[i]*(i-truoc);
        st.push(i);
    }
    // for (ll i=1; i<=n; i++) cout<<l[i]<<" "; cout<<endl;

    while (!st.empty()) st.pop();
    mx=0, index=n;
    a[n+1]=l[n+1]=r[n+1]=0;
    st.push(n+1);
    for (ll i=n; i>=1; i--)
    {
        while (!st.empty() && a[st.top()]>a[i]) st.pop();
        ll sau=st.top();
        r[i]=r[sau]+a[i]*(sau-i);
        st.push(i);
    }
    // for (ll i=1; i<=n; i++) cout<<r[i]<<" "; cout<<endl;

    ll dinh=1;
    mx=-1;
    for (ll i=1; i<=n; i++) if (l[i]+r[i]-a[i]>mx)
    {
        mx=l[i]+r[i]-a[i];
        dinh=i;
    }
    
    ans[dinh]=a[dinh];  //cout<<dinh<<endl;
    for (ll i=dinh-1; i>=1; i--) ans[i]=min(a[i], ans[i+1]);
    for (ll i=dinh+1; i<=n; i++) ans[i]=min(a[i], ans[i-1]);
    for (ll i=1; i<=n; i++) cout<<ans[i]<<" ";
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