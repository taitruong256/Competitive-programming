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
                                       Where is the bug, delete it there
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
ll n, a[200005], q, ans[200005];
vector<ll> adj[200005];
vector<pair<ll, ll>> query[200005];
vector<ll> vi;




struct Trie 
{
    struct node 
    {
        ll cnt, isEnd; //so tien to va so luong xau ket thuc 
        node *child[2];

        node()
        {
            cnt=0;
            isEnd=false;
            for (ll i=0; i<2; i++) child[i]=NULL;
        }
    };
    node *root=new node();

    Trie() {}

    void insert(ll &x)
    {
        node *p=root;
        root->cnt+=1;
        for (ll i=31; i>=0; i--)
        {
            ll nxt=(x&(1LL<<i))!=0;
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            p=p->child[nxt];
            p->cnt+=1;
        }
        p->isEnd+=1;
    }

    ll query(ll &x)
    {
        ll res=0;
        node *p=root;
        for (ll i=31; i>=0; i--)
        {
            ll nxt=(x&(1LL<<i))!=0;
            if (p->child[1-nxt]!=NULL) res+=1LL<<i, p=p->child[1-nxt];
            else p=p->child[nxt];
        }
        return res;
    }

    void travel(node *p, ll x, ll depth)
    {
        if (p==NULL) return;
        if (p->isEnd!=0)
            for (ll i=0; i<p->isEnd; i++) vi.push_back(x);
        for (ll i=0; i<2; i++) if (p->child[i]!=NULL) travel(p->child[i], x+(1LL<<(31-depth))*i, depth+1);
        delete p;
    }

    void debug() { travel(root, 0, 0); }
};

Trie trie[200005];
string s;

void dfs(ll u, ll par)
{
    trie[u].insert(a[u]);
    for (ll v: adj[u]) if (v!=par) 
    {
        dfs(v, u);
        if (trie[u].root->cnt<trie[v].root->cnt) 
        {
            swap(trie[u], trie[v]);
        }
        trie[v].debug();
        for (auto i: vi)
        {
            trie[u].insert(i);
        }
        vi.clear();
    }
    for (auto [v, id]: query[u]) 
    {
        ans[id]=trie[u].query(a[v]);
    }
}

void solve()
{
    cin>>n;  
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n-1; i++)
    {
        ll u, v; cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cin>>q;
    for (ll i=1; i<=q; i++)
    {
        ll u, v; cin>>u>>v;
        query[v].push_back({u, i});
    }
    dfs(1, -1);
    for (ll i=1; i<=q; i++) cout<<ans[i]<<" ";
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