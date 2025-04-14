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
        ll cnt[2], isEnd, level, win; //so tien to va so luong xau ket thuc 
        node *child[26];

        node()
        {
            cnt[0]=cnt[1]=0;
            isEnd=false;
            level=0;
            win=-1;
            for (ll i=0; i<26; i++) child[i]=NULL;
        }
    };
    node *root=new node();
    string tmp;

    Trie() {}

    void insert(string s, ll type)
    {
        ll n=s.size(), l=0;
        node *p=root;
        p->cnt[type]+=1;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'a';
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            p=p->child[nxt];
            p->cnt[type]+=1;
            p->level=++l;
        }
        p->isEnd+=1;
    }

    bool dp(node *p)
    {
        ll turn=p->level%2;
        if (p->cnt[turn]==0) return 0;
        p->win=0;
        for (ll i=0; i<26; i++) if (p->child[i]!=NULL)
        {
            if (dp(p->child[i])==0) p->win=1;
        }
        return p->win;
    }

    void travel(node *p, string s)
    {
        if (p==NULL) return;
        cout<<s<<" "<<p->cnt[0]<<" "<<p->cnt[1]<<endl;
        for (ll i=0; i<26; i++) if (p->child[i]!=NULL) travel(p->child[i], s+char('a'+i));
    }

    void debug() { travel(root, ""); }
};

void solve()
{
    Trie trie;
    ll n; cin>>n;
    for (ll i=0; i<n; i++)
    {
        string s; cin>>s;
        trie.insert(s, 0);
    }
    ll m; cin>>m;
    for (ll i=0; i<m; i++)
    {
        string s; cin>>s;
        trie.insert(s, 1);
    }
    if (trie.dp(trie.root)==1) cout<<"Nina";
    else cout<<"Emilija";
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