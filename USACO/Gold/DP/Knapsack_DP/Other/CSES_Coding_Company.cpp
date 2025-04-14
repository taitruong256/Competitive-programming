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
const ll mod = 1e9+7;
ll dp[105][105][5005], N, K, a[105];

void solve()
{
    cin>>N>>K;
    for (ll i=0; i<N; i++) cin>>a[i];
    sort(a, a+N);
    a[N]=a[N-1];
    
    dp[0][0][0]=1;
    for (ll i=0; i<=N; i++)
        for (ll j=0; j<=N; j++)
            for (ll k=0; k<=K; k++)
            {
                ll new_k;
                //tao mot group moi chi co mot minh i
                new_k=k+j*(a[i+1]-a[i]);
                if (new_k<=K) dp[i+1][j][new_k]+=dp[i][j][k], dp[i+1][j][new_k]%=mod;
                
                //tao mot group moi va de i mo
                new_k=k+(j+1)*(a[i+1]-a[i]);
                if (new_k<=K) dp[i+1][j+1][new_k]+=dp[i][j][k], dp[i+1][j+1][new_k]%=mod;

                //them i vao group co san va de i dong 
                new_k=k+(j-1)*(a[i+1]-a[i]);
                if (j>=1 && new_k<=K) dp[i+1][j-1][new_k]+=j*dp[i][j][k], dp[i+1][j-1][new_k]%=mod;

                //them i vao group co san va de i mo 
                new_k=k+j*(a[i+1]-a[i]);
                if (new_k<=K) dp[i+1][j][new_k]+=j*dp[i][j][k], dp[i+1][j][new_k]%=mod;
            }
    ll ans=0;
    for (ll i=0; i<=K; i++) ans=(ans+dp[N][0][i])%mod;
    cout<<ans;
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