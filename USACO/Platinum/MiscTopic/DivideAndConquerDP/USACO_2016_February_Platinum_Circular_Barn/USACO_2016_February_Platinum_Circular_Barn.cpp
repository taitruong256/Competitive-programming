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

int N, K, a[1001], rot;
ll ans=inf, dp[1001][1001], dist[1001][1001];

ll cost(int l, int r)
{
    return dist[(l+rot)%N][r-l+1];
}

void calc(int l, int r, int optl, int optr, int k)
{
    if (l>r) return;
    int mid=(l+r)/2;
    pair<ll, int> best={inf, -1};
    for (int i=optl; i<=min(mid, optr); i++) best=min(best, {dp[k-1][i-1]+cost(i, mid), i});
    dp[k][mid]=best.first;
    calc(l, mid-1, optl, best.second, k);
    calc(mid+1, r, best.second, optr, k);
}

void solve()
{
    setIO("cbarn");
    cin>>N>>K;
    for (int i=0; i<N; i++) cin>>a[i];
    for (int i=0; i<N; i++)
        for (int j=1; j<=N; j++)    
            dist[i][j]=dist[i][j-1]+a[(i+j-1)%N]*(j-1);
    
    for (rot=0; rot<N; rot++)
    {
        for (int i=0; i<N; i++) dp[0][i]=cost(0, i);
        for (int k=1; k<=K-1; k++) calc(k, N-1, k, N-1, k);
        ans=min(ans, dp[K-1][N-1]);  
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}