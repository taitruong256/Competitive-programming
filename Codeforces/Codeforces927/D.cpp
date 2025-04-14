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
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;

void solve()
{
    ll n; cin>>n;
    char atchubai; cin>>atchubai;
    string s[2*n+5];
    for (ll i=1; i<=2*n; i++) cin>>s[i];


    deque<char> dq[6];
    map<char, ll> idx;
    idx['C']=1;
    idx['D']=2;
    idx['H']=3;
    idx['S']=4;
    for (ll i=1; i<=2*n; i++) dq[idx[s[i][1]]].push_back(s[i][0]);
    ll le=0, at=dq[idx[atchubai]].size();
    for (ll i=1; i<=4; i++) if (i!=idx[atchubai]) le+=dq[i].size()%2;


    if (at<le) 
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }


    for (ll i=1; i<=4; i++) sort(dq[i].begin(), dq[i].end());
    for (auto [x, y]: idx) if (x!=atchubai)
    {
        // cout<<x<<"    "; for (auto i: dq[y]) cout<<i<<" "; cout<<endl;
        while (dq[y].size()>=2)
        {
            char u=dq[y].front(); dq[y].pop_front();
            char v=dq[y].front(); dq[y].pop_front();
            cout<<u<<x<<" "<<v<<x<<endl;
        }
        if (dq[y].size()>0)
        {
            char u=dq[y].front(); dq[y].pop_front();
            char v=dq[idx[atchubai]].front(); dq[idx[atchubai]].pop_front();
            cout<<u<<x<<" "<<v<<atchubai<<endl;
        }
    }
    while (dq[idx[atchubai]].size()>=2)
    {
        char u=dq[idx[atchubai]].front(); dq[idx[atchubai]].pop_front();
        char v=dq[idx[atchubai]].front(); dq[idx[atchubai]].pop_front();
        cout<<u<<atchubai<<" "<<v<<atchubai<<endl;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}