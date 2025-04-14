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

struct SuffixAutomaton
{
    struct state
    {
        ll len, link;
        map<char, ll> next;
    };
    vector<state> st;
    ll sz, last, maxn;

    SuffixAutomaton(){}
    SuffixAutomaton(ll _n)
    {
        maxn=_n;
        st.resize(2*maxn+10);
        st[0].len=0;
        st[0].link=-1;
        sz=1;
        last=0;
    }

    void extend(char c)
    {
        ll cur=sz++;
        st[cur].len=st[last].len+1;
        ll p=last;
        while (p!=-1 && !st[p].next.count(c))
        {
            st[p].next[c]=cur;
            p=st[p].link;
        }
        if (p==-1) st[cur].link=0;
        else 
        {
            ll q=st[p].next[c];
            if (st[p].len+1==st[q].len) st[cur].link=q;
            else 
            {
                ll clone=sz++;
                st[clone].len=st[p].len+1;
                st[clone].next=st[q].next;
                st[clone].link=st[q].link;
                while (p!=-1 && st[p].next[c]==q)
                {
                    st[p].next[c]=clone;
                    p=st[p].link;
                }
                st[q].link=st[cur].link=clone;
            } 
        }
        last=cur;
    }

    void bfs(ll s)
    {
        queue<ll> q;
        vector<bool> vis(sz+5, false);
        vector<ll> dist(sz+5, 0);
        vector<ll> ans(sz+5, 0);

        q.push(s);
        vis[s]=true;
        dist[s]=0;
        while (!q.empty())
        {
            ll u=q.front(); q.pop();
            ++ans[dist[u]];
            --ans[st[u].len+1];
            for (auto [c, v]: st[u].next) if (vis[v]==false)
            {
                q.push(v);
                vis[v]=true;
                dist[v]=dist[u]+1;
            }
        }

        for (ll i=1; i<=maxn; i++) ans[i]+=ans[i-1];
        for (ll i=1; i<=maxn; i++) cout<<ans[i]<<" ";
    }
};

void solve()
{
    string s; cin>>s;
    ll k; cin>>k;
    ll n=s.size();
    SuffixAutomaton sa(n);
    for (ll i=0; i<n; i++) sa.extend(s[i]);
    sa.bfs(0);
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