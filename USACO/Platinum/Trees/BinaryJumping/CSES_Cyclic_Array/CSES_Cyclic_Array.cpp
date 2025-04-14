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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
ll n, k, sum, l, r, ans, a[200005], nxt[200005][25], len[200005][25];

bool check(ll mid)
{
    for (ll i=0; i<n; i++)
    {
        ll total=0, x=i;
        for (ll j=0; j<20; j++) if (mid&(1LL<<j)) 
        {
            total+=len[x][j];  
            x=nxt[x][j];
        }                          
        if (total>=n) return true;
    }
    return false;
}

void solve()
{
    cin>>n>>k;
    for (ll i=0; i<n; i++) cin>>a[i], sum+=a[i];
    if (sum<=k)
    {
        cout<<1;
        return;
    }
    sum=0;
    for (l=0; l<n; l++)
    {
        while (sum+a[r%n]<=k) sum+=a[r%n], ++r; 
        nxt[l][0]=r%n;
        len[l][0]=r-l;
        sum-=a[l];
    }
    for (ll j=1; j<=20; j++)
        for (ll i=0; i<n; i++)
        {
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
            len[i][j]=len[i][j-1]+len[nxt[i][j-1]][j-1];   // luu y khong phai len[i][j]=len[i][j-1]+len[i][j-1];
        }
    
    l=1, r=n, ans=1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
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