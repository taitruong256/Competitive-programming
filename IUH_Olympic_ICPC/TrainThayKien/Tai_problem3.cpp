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
map<ll, ll> dp;
map<ll, bool> visited;

ll number(string s)
{
    ll num=0;
    for (ll i=0; i<s.size(); i++) num=num*10+(s[i]-'0');
    return num;
}

string trai(string s)
{
    string t; s=" "+s;
    t.push_back(s[8]); 
    t.push_back(s[1]); 
    t.push_back(s[3]); 
    t.push_back(s[7]); 
    t.push_back(s[0]); 
    t.push_back(s[2]); 
    t.push_back(s[4]); 
    t.push_back(s[6]); 
    t.push_back(s[0]); 
    t.push_back(s[5]); 
    return t;
}

string phai(string s)
{
    string t; s=" "+s;
    t.push_back(s[1]); 
    t.push_back(s[0]); 
    t.push_back(s[2]); 
    t.push_back(s[8]); 
    t.push_back(s[6]); 
    t.push_back(s[0]); 
    t.push_back(s[3]); 
    t.push_back(s[7]); 
    t.push_back(s[4]); 
    t.push_back(s[5]); 
    return t;
}

void solve()
{
    char c; 
    for (ll i=0; i<10; i++) cin>>c, batdau.push_back(c);
    ketthuc="1238004765";
    
    queue<ll> q;
    q.push(bd);
    while (!q.empty())
    {
        ll s=q.front(); q.pop();
        if (s==kt) break;
        if (visited[number(trai(to_string(s)))]==false)
        {
            visited[number(trai(to_string(s)))]=true;
            q.push(number(trai(to_string(s))));
            dp[number(trai(s))]=dp[s]+1;
        }
        if (visited[number(phai(s))]==false)
        {
            visited[number(phai(s))]=true;
            q.push(number(phai(s)));
            dp[number(phai(s))]=dp[s]+1;
        }
    }
    cout<<dp[kt];
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