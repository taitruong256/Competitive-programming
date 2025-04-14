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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n;
deque<char> s;
deque<char> dp[105][105];

char opt(char c1, char c2)
{
    if (c1>c2) swap(c1, c2);
    if (c1=='a')
    {
        if (c2=='b') return 'c';
        return 'b';
    }
    return 'a';
}

deque<char> calc(deque<char> s)
{
    while (s.size()>1 && s[0]!=s[1]) 
    {
        char x=s.front(); s.pop_front();
        char y=s.front(); s.pop_front();
        s.push_front(opt(x, y));
    }
    while (s.size()>1 && s[s.size()-2]!=s[s.size()-1]) 
    {
        char x=s.back(); s.pop_back();
        char y=s.back(); s.pop_back();
        s.push_back(opt(x, y));
    }
    return s;
}

void solve()
{
    string t; cin>>t;
    s.push_back(' ');
    for (char c: t) s.push_back(c);
    n=s.size()-1;
    for (ll i=1; i<=n; i++) dp[i][i].push_back(s[i]);
    for (ll len=2; len<=n; len++)
        for (ll i=1; i<=n-len+1; i++)
        {
            ll j=i+len-1;
            deque<char> t1=dp[i+1][j];
            t1.push_front(s[i]);
            t1=calc(t1);
            deque<char> t2=dp[i][j-1];
            t2.push_back(s[j]);
            t2=calc(t2);
            if (t1.size()<t2.size()) dp[i][j]=t1;
            else dp[i][j]=t2;
        }

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=i; j<=n; j++) 
    //     {
    //         for (char c: dp[i][j]) cout<<c;
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[1][n].size()<<endl;

    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=n; j++) dp[i][j].clear();
    s.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}