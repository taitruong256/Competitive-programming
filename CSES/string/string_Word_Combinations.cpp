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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
struct TrieNode
{
    TrieNode *child[26];
    int cnt;

    TrieNode()
    {
        for (ll i=0; i<26; i++) child[i]=NULL;
        cnt=0;
    }
};

void Insert(TrieNode *root, string s)
{
    ll n=s.size();
    TrieNode *p=root;
    for (ll i=0; i<n; i++)
    {
        ll nxt=s[i]-'a';
        if (p->child[nxt]==NULL) p->child[nxt]=new TrieNode();
        p=p->child[nxt];
    }
    ++p->cnt;
}

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    ll q; cin>>q;
    s=" "+s;
    ll dp[5005];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    TrieNode *root=new TrieNode();
    for (ll i=0; i<q; i++)
    {
        string t; cin>>t;
        Insert(root, t);
    }

    for (ll i=1; i<=n; i++)
    {
        auto cur=root;
        for (ll j=i; j<=n; j++)
        {
            ll nxt=s[j]-'a';
            if (cur->child[nxt]==NULL) break;
            cur=cur->child[nxt];
            if (cur->cnt>0) dp[j]=(dp[j]+dp[i-1])%mod;
        }
    }
    // for (ll i=1; i<=n; i++) cout<<dp[i]<<" "; cout<<endl;
    cout<<dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}