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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
vector<ll> comp;

struct line 
{
    ll a, b;
    ll get(ll x) {return a*x+b;}
};

line tree[3000005];

void insert(ll id, ll l, ll r, line newL)
{
    if (l==r)
    {
        if (newL.get(comp[l])>tree[id].get(comp[l])) tree[id]=newL;
        return;
    }
    ll m=(l+r)/2;
    bool lef=newL.get(comp[l])>tree[id].get(comp[l]);
    bool mid=newL.get(comp[m])>tree[id].get(comp[m]);
    if (mid==true) swap(newL, tree[id]);
    if (lef!=mid) insert(id*2, l, m, newL);
    else insert(id*2+1, m+1, r, newL);
}

ll getpos(ll val)
{
    return lower_bound(comp.begin(), comp.end(), val)-comp.begin();
}

void insert(line newL, ll n)
{
    insert(1, 0, n-1, newL);
}

ll query(ll id, ll l, ll r, ll x)
{
    if (l==r) return tree[id].get(comp[x]);
    ll m=(l+r)/2;
    if (x<m) return max(tree[id].get(comp[x]), query(id*2, l, m, x));
    return max(tree[id].get(comp[x]), query(id*2+1, m+1, r, x)); 
}

ll query(ll x, ll n)
{
    ll pos=getpos(x);
    return query(1, 0, n-1, pos);
}

ll n, A, B, C, ans, pref, maxdp;
int a[1000005];

void solve()
{
    cin>>n;
    cin>>A>>B>>C;
    for (ll i=1; i<=n; i++) 
    {
        cin>>a[i];
        pref+=a[i];
        comp.push_back(pref);
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end())-comp.begin());
    n=comp.size();
    insert({0, 0}, n);
    pref=0;
    for (ll i=1; i<=n; i++)
    {
        pref+=a[i];
        maxdp=query(pref, n)+A*pref*pref+B*pref+C;
        ans=max(ans, maxdp);
        insert({-2*A*pref, maxdp+A*pref*pref-B*pref}, n);
    }      
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}