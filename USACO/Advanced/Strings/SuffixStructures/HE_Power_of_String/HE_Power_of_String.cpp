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
ll res=0;

struct SuffixAutomaton
{
    struct state
    {
        ll len, link, cnt, firstpos;
        map<char, ll> next;
    };
    vector<state> st;
    vector<ll> dp;
    ll sz, last, maxn;
    string ans;
 
    SuffixAutomaton(){}
    void init(ll _n)
    {
        ans="";
        maxn=_n;
        st.resize(4*maxn+10);
        dp.resize(4*maxn+10);
        st[0].len=0;
        st[0].link=-1;
        st[0].cnt=0;
        sz=1;
        last=0;
    }
 
    void extend(char c)
    {
        ll cur=sz++;
        st[cur].len=st[last].len+1;
        st[cur].cnt=1;
        st[cur].firstpos=st[last].len;
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
                st[clone].cnt=0;
                st[clone].firstpos=st[q].firstpos;
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
    void update_cnt()
    {
        vector<ll> states_by_len[sz+5];
        for (ll i=0; i<sz; i++) states_by_len[st[i].len].push_back(i);
        for (ll i=sz-1; i>=0; i--) 
            for (auto u: states_by_len[i]) if (st[u].link!=-1)
        st[st[u].link].cnt+=st[u].cnt;
    }
 
    void dfs(ll u, ll len, ll &k)
    {
        if (st[u].cnt>=k) res=max(res, len);
        for (auto [c, v]: st[u].next) 
            dfs(v, len+1, k);
    }
} sa;

void solve()
{
    ll k, n; cin>>k>>n;
    string s; cin>>s;
    sa.init(n);
    for (auto c: s) sa.extend(c);
    sa.update_cnt();
    sa.dfs(0, 0, k);
    cout<<res;
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