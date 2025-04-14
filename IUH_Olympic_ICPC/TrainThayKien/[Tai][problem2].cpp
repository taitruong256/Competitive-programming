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
map<string, ll> dp;
map<string, bool> visited;

string trai(string s)
{
    string t; s=" "+s;
    t.push_back(s[4]); 
    t.push_back(s[1]); 
    t.push_back(s[3]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[6]); 
    return t;
}

string phai(string s)
{
    string t; s=" "+s;
    t.push_back(s[1]); 
    t.push_back(s[5]); 
    t.push_back(s[2]); 
    t.push_back(s[4]); 
    t.push_back(s[6]); 
    t.push_back(s[3]); 
    return t;
}

void solve()
{
    char c; 
    for (ll i=0; i<6; i++) cin>>c, batdau.push_back(c);
    for (ll i=0; i<6; i++) cin>>c, ketthuc.push_back(c);
    
    queue<string> q;
    q.push(batdau);
    while (!q.empty())
    {
        string s=q.front(); q.pop();
        if (s==ketthuc) break;;
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
    cout<<dp[ketthuc];
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