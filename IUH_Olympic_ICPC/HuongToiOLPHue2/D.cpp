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

bool doixung[5005][5005];
ll pref[5005], suff[5005];

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    string t=s;
    reverse(t.begin(), t.end());
    s=" "+s;
    t=" "+t;
    for (ll i=1; i<=n; i++) 
        for (ll j=i; j<=n; j++)
            if (s.substr(i, j-i+1)==t.substr(n-j+1, j-i+1)) 
                doixung[i][j]=1;

    // for (ll i=1; i<=n; i++)
    // {
    //     for (ll j=1; j<=n; j++) cout<<doixung[i][j]<<" ";
    //     cout<<endl;
    // }

    ll ans=0;
    for (ll i=1; i<=n-1; i++)
        for (ll j=i+1; j<=n; j+=2)
        {
            ll k=i+(j-i+1)/2;
            if (doixung[i][k-1]==1 && doixung[k][j]==1) ++ans; //cout<<i<<" "<<k<<" "<<j<<" "<<doixung[i][k]<<" "<<doixung[k+1][j]<<endl;
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