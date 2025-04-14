/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |__                                         |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                                        Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll n, a[200005], pref[200005], l, r, ans;

ll query(ll l, ll r)
{
    cout<<"? "<<r-l+1<<" ";
    for (ll i=l; i<=r; i++) cout<<i<<" ";
    cout<<endl;
    ll x; cin>>x;
    return x;
}

ll sum(ll l, ll r)
{
    return pref[r]-pref[l-1];
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    pref[0]=0;
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    l=1, r=n, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (query(l, mid)!=sum(l, mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<"! "<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}