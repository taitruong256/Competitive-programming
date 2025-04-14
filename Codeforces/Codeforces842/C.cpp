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
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    pair<ll, ll> a[n+5]; 
    for (ll i=1; i<=n; i++) cin>>a[i].first, a[i].second=i;
    sort(a+1, a+n+1, greater<pair<ll, ll>>());

    ll p[n+5], q[n+5];
    for (ll i=1; i<=n; i++) p[i]=q[i]=0;

    set<ll> use_p, use_q;
    for (ll i=1; i<=n; i++) use_p.insert(i), use_q.insert(i);

    for (ll i=1; i<=n; i++)
    {
        if (use_p.find(a[i].first)!=use_p.end())
        {
            p[a[i].second]=a[i].first;
            use_p.erase(a[i].first);
        }
        else 
        {
            if (use_q.find(a[i].first)!=use_q.end())
            {
                q[a[i].second]=a[i].first;
                use_q.erase(a[i].first);
            }
            else 
            {
                cout<<"NO\n";
                return;
            }
        }
    }

    for (ll i=1; i<=n; i++) 
    {
        if (p[i]==0)
        {
            auto it=use_p.upper_bound(q[i]);
            if (it==use_p.begin())
            {
                cout<<"NO\n";
                return;
            }
            it=prev(it);
            p[i]=*it;
            use_p.erase(*it);
        }
        else 
        {
            auto it=use_q.upper_bound(p[i]);
            if (it==use_q.begin())
            {
                cout<<"NO\n";
                return;
            }
            it=prev(it);
            q[i]=*it;
            use_q.erase(*it);
        }
    }
    cout<<"YES\n";
    for (ll i=1; i<=n; i++) cout<<p[i]<<" "; cout<<endl;
    for (ll i=1; i<=n; i++) cout<<q[i]<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}