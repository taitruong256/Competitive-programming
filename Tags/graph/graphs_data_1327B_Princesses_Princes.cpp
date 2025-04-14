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
    ll n; cin>>n;
    ll a[n+5];
    bool d[n+5];
    ll u=-1;
    for (ll i=1; i<=n; i++) d[i]=false;
    for (ll i=1; i<=n; i++)
    {
        ll sl; cin>>sl;
        bool check=false;
        for (ll j=0; j<sl; j++) cin>>a[j];
        for (ll j=0; j<sl; j++) if (d[a[j]]==false)
        {
            d[a[j]]=true;
            check=true;
            break;
        }
        if (check==false) u=i;
    }
    if (u==-1) cout<<"OPTIMAL\n";
    else 
    {
        ll v=-1;
        for (ll i=1; i<=n; i++) if (d[i]==false) v=i;
        cout<<"IMPROVE\n";
        cout<<u<<" "<<v<<endl;
    }
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