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
        ll len, link, cnt, firstpos;
        map<char, ll> next;
    };
    vector<state> st;
    vector<ll> dp;
    ll sz, last, maxn;
    string ans;

    SuffixAutomaton(){}
    SuffixAutomaton(ll _n)
    {
        ans="";
        maxn=_n;
        st.resize(2*maxn+10);
        dp.resize(2*maxn+10);
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
        vector<ll> states_by_len[sz];
        for (ll i=0; i<sz; i++) states_by_len[st[i].len].push_back(i);
        for (ll i=sz-1; i>=0; i--) 
            for (auto u: states_by_len[i]) if (st[u].link!=-1)
                st[st[u].link].cnt+=st[u].cnt;
    }

    void dfs(ll u)
    {
        dp[u]=st[u].cnt;
        for (auto [c, v]: st[u].next)
        {
            if (dp[v]==0) dfs(v);
            dp[u]+=dp[v];
        }
    }

    void dfs2(ll u, ll k)
    {      
        if (k<0) return;
        for (auto [c, v]: st[u].next) 
            if (k>=dp[v]) k-=dp[v];
            else 
            {
                ans.push_back(c);
                dfs2(v, k-st[v].cnt);
                return;
            }
    }

    string kth_substr(ll k)
    {
        ans="";
        dfs2(0, k-1);
        return ans;
    }
};

void solve()
{
    string s; cin>>s;
    ll k; cin>>k;
    ll n=s.size();
    SuffixAutomaton sa(n);
    for (ll i=0; i<n; i++) sa.extend(s[i]);
    sa.update_cnt();
    sa.dfs(0);
    cout<<sa.kth_substr(k);
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