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

    string to_binary(ll x)
    {
        string s;
        for (ll i=30; i>=0; i--) 
            if (x&(1LL<<i)) s.push_back('1');
            else s.push_back('0');
        return s;
    }

    void insert(ll x)
    {
        if (count(x)!=0) return;
        string s=to_binary(x);
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'0';
            if (p->child[nxt]==NULL) p->child[nxt]=new node();
            p=p->child[nxt];
            p->cnt+=1;
        }
        p->isEnd+=1;
    }

    ll count(ll x)  //dem so luong tien to s trong tap hop
    {
        string s=to_binary(x);
        ll n=s.size();
        node *p=root;
        for (ll i=0; i<n; i++)
        {
            ll nxt=s[i]-'0';
            if (p->child[nxt]==NULL) return 0;
            p=p->child[nxt];
        }
        return p->cnt;
    }

    bool deleteRecursive(node *p, ll index, string &s)
    {
        if (index!=s.size())
        {
            ll nxt=s[index]-'0';  
            if (deleteRecursive(p->child[nxt], index+1, s)==true) p->child[nxt]=NULL;
        }   
        else p->isEnd-=1;
        if (p!=root)
        {
            p->cnt-=1;
            if (p->cnt==0) 
            {
                delete p;
                return true;
            }
        }
        return false;
    }

    bool deleted(ll x)
    {
        if (count(x)==0) return false;
        string s=to_binary(x);
        deleteRecursive(root, 0, s);
        return true;
    }

    ll query(ll x)
    {
        string s=to_binary(x);
        ll ans=0;
        node *p=root;
        for (ll i=0; i<=30; i++) 
        {
            ll nxt=s[i]-'0';
            if (p->child[nxt]!=NULL) p=p->child[nxt];
            else ans+=(1LL<<(30-i)), p=p->child[1-nxt];
        }
        return ans;
    }

    void travel(node *p, string s)
    {
        if (p==NULL) return;
        if (p->isEnd!=0)
            for (ll i=0; i<p->isEnd; i++) cout<<s<<endl;
        for (ll i=0; i<2; i++) if (p->child[i]!=NULL) travel(p->child[i], s+char('0'+i));
    }

    void debug() { travel(root, ""); }
};

void solve()
{
    ll n; cin>>n;
    Trie trie;
    while (n--)
    {
        ll type, x; cin>>type>>x;
        if (type==0) trie.insert(x);
        else if (type==1) trie.deleted(x);
        else cout<<trie.query(x)<<endl;
    }
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