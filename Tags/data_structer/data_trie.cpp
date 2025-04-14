/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
struct trie 
{
    ll cnt, endOfWord; 
    trie *child[26];
    trie()
    {
        cnt=0;
        endOfWord=0;
        for (ll i=0; i<26; i++) child[i]=NULL;
    }
};

void insert_trie(trie *root, string s)
{
    ll n=s.size();
    trie *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        if (p->child[next]==NULL) p->child[next]=new trie();
        p=p->child[next];
        p->cnt++;
    }
    ++p->endOfWord;
}

bool check_trie(trie *root, string s)
{
    ll n=s.size();
    trie *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        if (p->child[next]==NULL) return false;
        p=p->child[next];
    }
    if (p->endOfWord==0) return false;
    return true;
}

ll count_trie(trie *root, string s)
{
    ll n=s.size();
    trie *p=root;
    for (ll i=0; i<n; i++) 
    {
        ll next=s[i]-'a';
        if (p->child[next]==NULL) return 0;
        p=p->child[next];
    }
    if (p->cnt==0 || p==NULL) return 0;
    return p->cnt;
}

void sort_trie(trie *root, string s)
{
    if (root->endOfWord>0)
        for (ll i=0; i<root->endOfWord; i++) cout<<s<<endl;
    for (ll i=0; i<26; i++) if (root->child[i]!=NULL) sort_trie(root->child[i], s+char(i+'a'));
}

void solve()
{
    trie *root=new trie();
    ll n; cin>>n;
    for (ll i=0; i<n; i++)
    {
        string t; cin>>t;
        insert_trie(root, t);
    }
    cout<<count_trie(root, "bc");
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}