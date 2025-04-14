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
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

struct Trie 
{
    struct node 
    {
        ll cnt, isEnd, mx, lst; //so tien to va so luong xau ket thuc 
        node *child[26];

        node()
        {
            cnt=0;
            isEnd=false;
            mx=-1;
            lst=-1;
            for (ll i=0; i<26; i++) child[i]=NULL;
        }
    };
    node *root=new node();
    string tmp;
    string ans;

    Trie() {}

    void insert(string s)
    {
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'a';
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            if (n-i-1>p->mx)
            {
                p->mx=n-i-1;
                p->lst=nxt;
            }
            p=p->child[nxt];
            p->cnt+=1;
        }
        p->isEnd=1;
    }

    void dfs(node *p)
    {
        if (p->isEnd>0) 
            for (ll i=0; i<p->isEnd; i++) ans.push_back('P');
        for (ll i=0; i<26; i++) if (p->child[i]!=NULL && i!=p->lst) 
        {
            ans.push_back(char(i+'a'));
            dfs(p->child[i]);
        }
        if (p->lst!=-1)
        {
            ans.push_back(char(p->lst+'a'));
            dfs(p->child[p->lst]);
        }
        ans.push_back('-');
    }

    void travel(node *p, string s)
    {
        if (p==NULL) return;
        cout<<s<<" "<<p->lst<<" "<<p->mx<<endl;
        for (ll i=0; i<26; i++) if (p->child[i]!=NULL) travel(p->child[i], s+char('a'+i));
    }

    void debug() { travel(root, ""); }
};

void solve()
{
    ll n; cin>>n;
    Trie trie;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        trie.insert(s);
    }
    trie.dfs(trie.root);
    while (trie.ans.back()=='-') trie.ans.pop_back();
    cout<<trie.ans.size()<<endl;
    for (auto i: trie.ans) cout<<i<<endl;
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