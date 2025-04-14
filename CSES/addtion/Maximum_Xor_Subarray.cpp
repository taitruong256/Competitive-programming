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

struct trie
{
    trie *child[2];
};

void update(trie *root, ll pre_xor)
{
    trie *cur=root;
    for (ll i=30; i>=0; i--)
    {
        if (pre_xor&(1<<i))
        {
            if (cur->child[1]==NULL) cur->child[1]=new trie();
            cur=cur->child[1];
        }
        else 
        {
            if (cur->child[0]==NULL) cur->child[0]=new trie();
            cur=cur->child[0];
        }
    }
}

ll query(trie *root, ll pre_xor)
{
    trie *cur=root;
    ll ans=0;
    for (ll i=30; i>=0; i--)
    {
        if (pre_xor&(1<<i))
        {
            if (cur->child[0]!=NULL)
            {
                ans+=(1<<i);
                cur=cur->child[0];
            }
            else cur=cur->child[1];
        }
        else 
        {
            if (cur->child[1]!=NULL)
            {
                ans+=(1<<i);
                cur=cur->child[1];
            }
            else cur=cur->child[0];
        }
    }
    return ans;
}
string s="";

void dfs(trie *root)
{
    if (root->child[0]==NULL && root->child[1]==NULL)
    {
        cout<<s<<endl;
        return;
    }
    if (root->child[0]!=NULL)
    {
        s.push_back('0');
        dfs(root->child[0]);
        s.pop_back();
    }
    if (root->child[1]!=NULL)
    {
        s.push_back('1');
        dfs(root->child[1]);
        s.pop_back();
    }
}

void solve()
{
    ll n; cin>>n;
    trie *root=new trie();
    update(root, 0);
    ll ans=0, pre_xor=0;
    for (ll i=1; i<=n; i++)
    {
        ll x; cin>>x;
        pre_xor^=x;
        update(root, pre_xor);
        ans=max(ans, query(root, pre_xor));
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