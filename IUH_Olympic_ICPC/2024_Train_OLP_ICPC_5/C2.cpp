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

ll n, k;
pair<ll, ll> a[100005];

struct fenwick
{
    ll n; 
    vector<ll> bit;

    fenwick(){}
    fenwick(ll _n)
    {
        n=_n;
        bit.resize(n+5);
    }

    void update(ll idx, ll val)
    {
        for (ll i=idx; i<=n; i+=-i&i) bit[i]+=val;
    }

    ll query(ll idx)
    {
        ll sum=0;
        for (ll i=idx; i>0; i-=-i&i) sum+=bit[i];
        return sum;
    }

    ll query(ll l, ll r)
    {
        if (l>r) return 0;
        return query(r)-query(l-1);
    }
};

bool check(ll mid)
{
    ll cnt1=0, cnt2=0, cnt3=0;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<i; j++)
        {
            ll d1=abs(a[i].first-a[j].first);
            ll d2=abs(a[i].second-a[j].second);
            if (d1<=mid) ++cnt1;
            if (d2<=mid) ++cnt2;
            if (d1<=mid && d2<=mid) ++cnt3;
        }
    cout<<cnt1+cnt2-cnt3<<"    "<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    return cnt1+cnt2-cnt3>=k;
}

void solve()
{
    cin>>n>>k;
    for (ll i=1; i<=n; i++) cin>>a[i].first>>a[i].second;
    sort(a+1, a+n+1);
    for (ll i=1; i<=10; i++) check(i);
    // ll l=0, r=1e6, ans=-1;
    // while (l<=r)
    // {
    //     ll mid=(l+r)/2;
    //     if (check(mid)==true) ans=mid, r=mid-1;
    //     else l=mid+1;
    // }
    // cout<<ans;
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