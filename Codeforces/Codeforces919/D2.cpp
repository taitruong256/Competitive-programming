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
int n, q, ans[100005];
ll len=0;
map<ll, int> dp, inserts, copies;
pair<ll, int> qry[100005];

ll calc(ll x)
{
    cerr<<x<<endl;
    if (inserts.find(x)!=inserts.end()) return dp[x]=inserts[x];
    if (dp.find(x)!=dp.end()) return dp[x];
    auto [u, v]=*prev(copies.lower_bound(x));
    return dp[x]=calc(x%(u+1));
}

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
    {
        int type, x; cin>>type>>x;
        if (type==1) len+=1, inserts[len-1]=x;
        else 
        {
            copies[len-1]=(x+1);
            if (len>2e18/(x+1)) len=2e18;
            else len*=(x+1); 
        }
    }   
    
    for (ll i=1; i<=q; i++)
    {
        cin>>qry[i].first;
        qry[i].second=i;
    }
    sort(qry+1, qry+q+1);
    for (ll i=1; i<=q; i++)
    {
        ans[qry[i].second]=calc(qry[i].first-1);
    }
    for (ll i=1; i<=q; i++) cout<<ans[i]<<" ";
    cout<<endl;

    len=0;
    dp.clear();
    copies.clear();
    inserts.clear();
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