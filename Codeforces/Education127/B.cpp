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
    ll n; cin>>n;
    ll a[n+5], b[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];

    if (n==1)
    {
        cout<<"YES\n";
        return;
    }
    if (n==2 && a[2]-a[1]>3)
    {
        cout<<"NO\n";
        return;
    }
    ll cnt=0;
    for (ll i=2; i<=n-1; i++)
    {
        if (i==2)
        {
            if (a[i]-a[i-1]>3)
            {
                cout<<"NO\n";
                return;
            }
            else if (a[i]-a[i-1]==3) ++cnt;
        }
        else if (a[i]-a[i-1]==2) ++cnt;
        else if (a[i]-a[i-1]>2)
        {
            cout<<"NO\n";
            return;
        }
    }
    if (a[n]-a[n-1]>3)
    {
        cout<<"NO\n";
        return;
    }
    else if 
    if (cnt<=2)
    {
        cout<<"YES\n";
        return;
    }

    cnt=0;
    for (ll i=n-1; i>=1; i--)
    {
        if (i==n-1)
        {
            if (a[i+1]-a[i]>3)
            {
                cout<<"NO\n";
                return;
            }
            else if (a[i+1]-a[i]==3) ++cnt;
        }
        else if (a[i+1]-a[i]==2) ++cnt;
        else if (a[i+1]-a[i]>2)
        {
            cout<<"NO\n";
            return;
        }
    }
    if (cnt<=2)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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