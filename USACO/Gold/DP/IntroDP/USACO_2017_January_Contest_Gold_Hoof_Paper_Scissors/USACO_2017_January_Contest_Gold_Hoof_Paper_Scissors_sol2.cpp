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
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
ll dp[100005][25][5], N, K, val[100005], ans;

ll isWin(ll i, ll j)
{
    // 0 wins 1
    // 1 wins 2
    // 2 wins 0 
    if ((i+1)%3==j) return 1;
    return 0;
}

ll calc(ll idx, ll cnt, ll cur)
{     
    if (idx==N+1 || cnt==K+1) return 0;       
    if (dp[idx][cnt][cur]!=-1) return dp[idx][cnt][cur];  
    if (idx==0)
    {                      
        ll t1=calc(idx+1, cnt, 0);
        ll t2=calc(idx+1, cnt, 1);
        ll t3=calc(idx+1, cnt, 2);
        return dp[idx][cnt][cur]=max({t1, t2, t3});
    }
    ll t1=isWin(cur, val[idx])+calc(idx+1, cnt+(cur!=0), 0);
    ll t2=isWin(cur, val[idx])+calc(idx+1, cnt+(cur!=1), 1);
    ll t3=isWin(cur, val[idx])+calc(idx+1, cnt+(cur!=2), 2);
    return dp[idx][cnt][cur]=max({t1, t2, t3});
}

void solve()
{
    setIO("hps");
    cin>>N>>K;
    for (ll i=1; i<=N; i++)
    {
        char c; cin>>c;
        if (c=='P') val[i]=0;
        else if (c=='H') val[i]=1;
        else val[i]=2;
    }
    for (ll i=0; i<=N+1; i++)   
        for (ll j=0; j<=K+1; j++)
            for (ll k=0; k<3; k++) dp[i][j][k]=-1;
    cout<<calc(0, 0, 0);
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