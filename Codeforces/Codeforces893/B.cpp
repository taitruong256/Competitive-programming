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
                                         Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e18;

void solve()
{
    ll n, m, d; cin>>n>>m>>d;
    deque<ll> a;
    bool check=0;
    for (ll i=1; i<=m; i++)
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    if (a.front()!=1) a.push_front(1), check=1;
    a.push_front(0); //bien
    a.push_back(n+1);
    ll sum=m+check, res;
    for (ll i=1; i<=a.size()-2; i++) sum+=(a[i+1]-a[i]-1)/d;
    ll mn=1e18, cnt=0;
    for (ll i=2; i<=a.size()-2; i++)
    {
        res=-1;
        res+=sum-(a[i]-a[i-1]-1)/d-(a[i+1]-a[i]-1)/d;
        res+=(a[i+1]-a[i-1]-1)/d;
        if (res<mn) mn=res, cnt=1;
        else if (res==mn) cnt+=1;
    }
    if (mn>=sum)
    {
        cout<<sum<<" "<<1<<endl;
        return;
    }
    cout<<mn<<" "<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}