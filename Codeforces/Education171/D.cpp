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

ll n, a[300005], pref[300005], add[300005], cnt[300005], sub[300005], s1=0, s2=0;
set<tuple<ll, ll, ll>> seg;

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) s1+=a[i]*(n-i+1);
    for (ll i=1; i<=n; i++) pref[i]=s1-s2, s2+=a[i]*(n-i+1);
    for (ll i=1; i<=n; i++) add[i]=add[i-1]+pref[i];
    for (ll i=n; i>=1; i--) sub[i]=sub[i+1]+a[i]*(n-i+1);
    for (ll i=1; i<=n; i++) cnt[i]=cnt[i-1]+n-i+1;

    // for (ll i=1; i<=n; i++) cout<<pref[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<add[i]<<" "; cout<<endl;
    // for (ll i=1; i<=n; i++) cout<<sub[i]<<" "; cout<<endl;
    ll st=1, fi=n;
    for (ll i=1; i<=n; i++) 
    {
        seg.insert({fi, st, i});
        st=fi+1;
        fi+=n-i;
    }
    // for (auto [l, r, id]: seg) cout<<l<<" "<<r<<" "<<id<<endl;

    ll q; cin>>q;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        auto [lx, rx, idx]=*seg.lower_bound({l, 0, 0});
        auto [ly, ry, idy]=*seg.lower_bound({r, 0, 0});
        
        ll ans=0;
        if (idx!=idy) 
        {
            ans+=add[idy-1]-add[idx];
            ll start_l=l-cnt[idx-1]+idx-1;
            ll end_l=n;
            ll start_r=idy;
            ll end_r=r-cnt[idy-1]+idy-1;
            ll ans1=(add[idx]-add[idx-1])-(sub[n])+a[idx]*(end_l-start_l+1);
            ll ans2=(add[idy]-add[idy-1]);//-sub[idy-1]+a[idy-1]*(end_r-start_r+1);
            ans+=ans1+ans2;
            // cerr<<"type 2: "<<l<<" "<<r<<"      "<<idx<<" "<<idy<<"       "<<start_l<<" "<<end_l<<" "<<ans1<<"        "<<start_r<<" "<<end_r<<" "<<ans2<<endl;
        }
        else 
        {
            l-=cnt[idx-1];
            r-=cnt[idy-1];
            l=n-l+1;
            r=n-r+1;
            ans+=pref[r]-pref[l-1];
        }
        cout<<ans<<endl;
        
    }
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