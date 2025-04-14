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
    ll a[n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];
    vector<ll> cnt(5);
    for (ll i=1; i<=n; i++) ++cnt[a[i]%3];

    if (n%3==0 && (cnt[0]!=n/3 || cnt[1]!=n/3 || cnt[2]!=n/3))
    {
            cout<<-1;
            return;
    } 
    if (n%3==1 && (cnt[0]!=n/3 || cnt[1]!=n/3+1 || cnt[2]!=n/3))
    {
            cout<<-1;
            return;
    } 
    if (n%3==2 && (cnt[0]!=n/3 || cnt[1]!=n/3+1 || cnt[2]!=n/3+1))
    {
            cout<<-1;
            return;
    } 
    
    deque<ll> dq[5];
    for (ll i=1; i<=n; i++) dq[a[i]%3].push_back(a[i]);
    sort(dq[1].begin(), dq[1].end());
    sort(dq[2].begin(), dq[2].end(), greater<ll>());
    for (ll i=1; i<=n; i++)
    {
        cout<<dq[i%3].front()<<" ";
        dq[i%3].pop_front();
    }
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