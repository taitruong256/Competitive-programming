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
    string a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n-1; i++)
        for (ll j=i+1; j<n; j++) if (a[i].size()>a[j].size())
        {
            string t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    
    // for (ll i=0; i<n; i++) cout<<a[i]<<endl;
    for (ll i=0; i<n; i++)
        for (ll j=0; j<i; j++) if (a[i].find(a[j])>=a[i].size())
        {
            cout<<"NO";
            return;
        }
    cout<<"YES\n";
    for (ll i=0; i<n; i++) cout<<a[i]<<endl;
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