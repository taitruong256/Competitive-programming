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

void solve()
{
    ll n, m; cin>>n>>m;
    ll x[n+5], t[m+5], review[m+5];
    for (ll i=1; i<=n; i++) cin>>x[i];
    for (ll i=1; i<=m; i++) cin>>t[i], review[i]=0;

    vector<tuple<ll, ll, ll>> v;
    for (ll i=1; i<=n; i++)
        if (i-t[x[i]]>=1) v.push_back({i-t[x[i]], i, x[i]});
    
    sort(v.begin(), v.end());
    deque<ll> order_subject; 
    set<ll> st;
    for (auto [l, r, subject]: v) if (st.find(subject)==st.end()) 
    {
        order_subject.push_back(subject);
        st.insert(subject);
    }
    // for (auto sub: order_subject) cout<<sub<<" "; cout<<endl;

    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        if (order_subject.empty()) break;
        ++ans;
        ll sub=order_subject.front();
        if (review[sub]>=t[sub]) order_subject.pop_front();
        else ++review[sub];
    }
    if (!order_subject.empty()) ans=-1;
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}