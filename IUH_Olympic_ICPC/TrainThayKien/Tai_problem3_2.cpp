/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
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
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
string batdau, ketthuc;
map<string, ll> dp, dp2;
map<string, bool> visited, visited2;

string trai(string s)
{
    string t; s=" "+s;
    t.push_back(s[4]); 
    t.push_back(s[1]); 
    t.push_back(s[3]); 
    t.push_back(s[8]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[7]); 
    t.push_back(s[9]); 
    t.push_back(s[6]); 
    t.push_back(s[10]); 
    return t;
}

string phai(string s)
{
    string t; s=" "+s;
    t.push_back(s[1]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[4]); 
    t.push_back(s[9]); 
    t.push_back(s[6]); 
    t.push_back(s[3]); 
    t.push_back(s[8]); 
    t.push_back(s[10]); 
    t.push_back(s[7]); 
    return t;
}

string trai_nguoc(string s)
{
    string t; s=" "+s;
    t.push_back(s[2]); 
    t.push_back(s[6]); 
    t.push_back(s[3]); 
    t.push_back(s[1]); 
    t.push_back(s[5]); 
    t.push_back(s[9]); 
    t.push_back(s[7]); 
    t.push_back(s[4]); 
    t.push_back(s[8]); 
    t.push_back(s[10]); 
    return t;
}

string phai_nguoc(string s)
{
    string t; s=" "+s;
    t.push_back(s[1]); 
    t.push_back(s[3]); 
    t.push_back(s[7]); 
    t.push_back(s[4]); 
    t.push_back(s[2]); 
    t.push_back(s[6]); 
    t.push_back(s[10]); 
    t.push_back(s[8]); 
    t.push_back(s[5]); 
    t.push_back(s[9]); 
    return t;
}

void solve()
{
    char c; 
    for (ll i=0; i<10; i++) cin>>c, batdau.push_back(c);
    ketthuc="1238004765";
    // cout<<phai_nguoc(batdau);
    
    queue<string> q;
    q.push(batdau);
    while (!q.empty())
    {
        string s=q.front(); q.pop();//  cout<<s<<endl;
        if (s==ketthuc || dp[s]>14) break;;
        if (visited[trai(s)]==false)
        {
            visited[trai(s)]=true;
            q.push(trai(s));
            dp[trai(s)]=dp[s]+1;
        }
        if (visited[phai(s)]==false)
        {
            visited[phai(s)]=true;
            q.push(phai(s));
            dp[phai(s)]=dp[s]+1;
        }
    }

    while (!q.empty()) q.pop();
    q.push(ketthuc);
    while (!q.empty())
    {
        string s=q.front(); q.pop();//  cout<<s<<endl;
        if (s==batdau || dp2[s]>14) break;;
        if (visited2[trai_nguoc(s)]==false)
        {
            visited2[trai_nguoc(s)]=true;
            q.push(trai_nguoc(s));
            dp2[trai_nguoc(s)]=dp2[s]+1;
        }
        if (visited2[phai_nguoc(s)]==false)
        {
            visited2[phai_nguoc(s)]=true;
            q.push(phai_nguoc(s));
            dp2[phai_nguoc(s)]=dp2[s]+1;
        }
    }
    ll ans=inf;
    if (visited[ketthuc]==true) ans=dp[ketthuc];
    else if (visited2[batdau]==true) ans=dp[batdau];
    else
    {
        for (auto it: dp) if (visited2[it.first]==true) ans=min(ans, it.second+dp2[it.first]);
    }
    cout<<ans;
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