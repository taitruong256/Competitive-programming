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
#define ll int
#define endl '\n'
const ll maxn = 205;
const ll mod = 1e9+7;
ll N, K, pw2[maxn], pw5[maxn], pre[205][6005], cur[205][6005];
long long a[maxn];

void solve()
{
    cin>>N>>K; 
    for (ll i=1; i<=N; i++) 
    {
        cin>>a[i];
        while (a[i]%2==0) ++pw2[i], a[i]/=2;
        while (a[i]%5==0) ++pw5[i], a[i]/=5;
    }
    for (ll j=0; j<=K+1; j++)
        for (ll k=0; k<=6000; k++) pre[j][k]=-1e9;
    pre[0][0]=0;
    for (ll i=1; i<=N; i++)
    {
        for (ll j=1; j<=K; j++)
        {
            for (ll k=0; k<=6000; k++) 
            {
                cur[j][k]=pre[j][k];
                if (k>=pw5[i]) cur[j][k]=max(cur[j][k], pre[j-1][k-pw5[i]]+pw2[i]);
            }
        }
        for (ll j=1; j<=K; j++)
            for (ll k=0; k<=6000; k++)
            {
                pre[j][k]=cur[j][k];
                cur[j][k]=-1e9;
            }
    }
    ll ans=0;
    for (ll i=0; i<=6000; i++) ans=max(ans, min(i, pre[K][i]));
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