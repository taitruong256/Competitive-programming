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
ll h[1005];
string c[1005];

void solve()
{
    ll n, m; cin>>n>>m;
    for (ll i=1; i<=n; i++) cin>>c[i];

    h[0]=h[m+1]=-1;
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=m; j++) h[j]=(c[i][j-1]=='*')?0:h[j]+1;
        ll l[m+5], r[m+5];
        stack<ll> st;
        st.push(0);
        for (ll j=1; j<=m; j++)
        {
            while (!st.empty() && h[j]<=h[st.top()]) st.pop();
            l[j]=st.top();
            st.push(j);
        }
        while (!st.empty()) st.pop();
        st.push(m+1);
        for (ll j=m; j>=1; j--)
        {
            while (!st.empty() && h[j]<=h[st.top()]) st.pop();
            r[j]=st.top();
            st.push(j);
        }
        for (ll j=1; j<=m; j++) ans=max(ans, h[j]*(r[j]-l[j]-1));
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