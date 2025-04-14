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
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

struct TRIE 
{
    ll cnt, endOfWord; 
    TRIE *child[26];
    TRIE() {}
    TRIE()
    {
        cnt=0;
        endOfWord=0;
        for (ll i=0; i<26; i++) child[i]=NULL;
    }
};
ll ans=0;

void insert_TRIE(TRIE *root, string s)
{
    ll n=s.size();
    TRIE *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        
        if (p->child[next]==NULL) p->child[next]=new TRIE();
        p=p->child[next];
        p->cnt++;
    }
    ++p->endOfWord;
}

bool check_TRIE(TRIE *root, string s)
{
    ll n=s.size();
    TRIE *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        if (p->child[next]==NULL) return false;
        p=p->child[next];
    }
    if (p->endOfWord==0) return false;
    return true;
}

ll count_TRIE(TRIE *root, string s)
{
    ll n=s.size();
    TRIE *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        if (p->child[next]==NULL) return 0;
        p=p->child[next];
    }
    if (p->cnt==0 || p==NULL) return 0;
    return p->cnt;
}

void sort_TRIE(TRIE *root, ll d)
{
    if (root->endOfWord>0) ++d, ans=max(ans, d);
    for (ll i=0; i<26; i++) if (root->child[i]!=NULL) sort_TRIE(root->child[i], d);
}

void solve()
{
    
} 

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}