/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
map<char, char> nxt, pre;
map<char, bool> vis;

void dfs(char c)
{
    if (c<=0) return;
    vis[c]=false;
    cout<<c;
    dfs(nxt[c]);
}

void solve()
{
    ll n; cin>>n;          
    string s;
    for (ll i=0; i<n; i++)
    {
        cin>>s;
        for (ll j=0; j<s.size(); j++)
        {
            if (j<s.size()-1) 
            {
                nxt[s[j]]=s[j+1];
                pre[s[j+1]]=s[j];
            }
            vis[s[j]]=true;
        }
    }

    for (char c='a'; c<='z'; c++) if (vis[c]==true && (int)pre[c]==0) dfs(c);
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