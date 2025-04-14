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

struct segment_tree_faster
{
    ll n;
    vector<ll> tree;
    segment_tree_faster(){}
    segment_tree_faster(ll _n)
    {
        n=_n;
        tree.resize(2*n+5);
    }
    ll opt(ll x, ll y)
    {
        return (x+y)%mod;
    }
    ll query(ll l, ll r)
    {
        ll ans=0;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) 
        {
            if (l&1) ans=opt(ans, tree[l++]);
            if (!(r&1)) ans=opt(ans, tree[r--]);
        }
        return ans;
    }
    void update(ll i, ll val)
    {
        tree[i+=n]=val;
        for (i/=2; i>0; i/=2) tree[i]=opt(tree[i*2], tree[i*2+1]);
    }
};

bool is_prime[1000005];
ll n, q, pref[1000005], prime[1000005];

void solve()
{
    cin>>q;
    segment_tree_faster seg(n);
    for (ll i=1; i<=n; i++) seg.update(i, prime[i]*i%mod);
    for (ll i=1; i<=n; i++) pref[i]=(pref[i-1]+prime[i])%mod;
    while (q--)
    {
        ll l, r; cin>>l>>r;
        if (l>r) swap(l, r);
        l=lower_bound(prime+1, prime+n+1, l)-prime;
        r=upper_bound(prime+1, prime+n+1, r)-prime-1;  
        ll sum1=seg.query(l, r);
        ll sum2=(l-1)*(pref[r]-pref[l-1])%mod;
        cout<<(sum1-sum2+mod)%mod<<endl;
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

    for (ll i=2; i<=1e6; i++) is_prime[i]=1;
    for (ll i=2; i*i<=1e6; i++) if (is_prime[i]==1)
        for (ll j=i*i; j<=1e6; j+=i) is_prime[j]=0;

    for (ll i=2; i<=1e6; i++) if (is_prime[i]==1) prime[++n]=i;

    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}