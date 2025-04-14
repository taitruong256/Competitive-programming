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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll area(pair<ll, ll> a, pair<ll, ll> b, ll k)
{
    ll x1=max(a.first-k/2, b.first-k/2);
    ll x2=min(a.first+k/2, b.first+k/2);
    ll y1=max(a.second-k/2, b.second-k/2);
    ll y2=min(a.second+k/2, b.second+k/2);
    ll ans=(x2-x1)*(y2-y1);
    return ans;
}

void solve()
{
    ll n, k; cin>>n>>k;
    pair<ll, ll> a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second, a[i].first+=1e6, a[i].second+=1e6;
    sort(a+1, a+n+1);

    set<pair<ll, ll>> st;
    st.insert({a[1].second, 1});
    ll l=1;
    ll cnt=0, ans=0;
    for (ll r=2; r<=n; r++)
    {
        while (a[r].first-a[l].first>=k)
        {
            st.erase({a[l].second, l});
            ++l;
        }
        auto lo=st.lower_bound({a[r].second-k, 0});
        auto hi=st.upper_bound({a[r].second+k, 0});
        for (auto it=lo; it!=hi; it++)
        {
            auto [y, i]=*it;
            ll res=area(a[r], a[i], k);
            if (res>0) ++cnt, ans=res;
            if (cnt>1) 
            {
                cout<<-1;
                return;
            }
        }
        st.insert({a[r].second, r});
    }
    if (cnt==0) cout<<0;
    else cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}