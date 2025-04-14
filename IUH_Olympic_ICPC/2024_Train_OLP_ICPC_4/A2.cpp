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
                                     Try, try, try again until you succeed
I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
     Even the things and people you like, you don't have the courage to take, you are destined to be a failure.
                                           Difficult means more time
                                          Done is better than perfect
                                         Pain + Reflection = Progress 
     Laziness is only temporary comfort. The future will regret that day. Don't fall into the trap of comfort.
                The most beautiful meeting in this world is meeting the best version of yourself.
                          Practice doing things you don't like but are useful to you
                                   Success is born from problem solving
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

ll n, q;
string s[200005];

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>s[i];
    s[n+1]="or";
    while (q--)
    {
        ll l, r; cin>>l>>r;
        assert(l%2==1 && r%2==1);
        string x; cin>>x;
        ll ans=0, tar=0;
        if (x=="true") tar=1;

        bool check=0;
        for (ll j=0; j<2; j++)
        {
            ll now=0, pre=-1;
            for (ll i=1; i<=n+1; i++) 
            {
                if (i==l) 
                {
                    if (pre==-1) pre=j;
                    else pre&=j;
                    i=r;
                }
                if (s[i]=="true" || s[i]=="false") 
                {
                    if (pre==-1) pre=(s[i]=="true");
                    else pre&=(s[i]=="true");
                }
                else if (s[i]=="or") now|=pre, assert(pre!=-1), pre=-1;
                else continue; 
            }
            if (now==tar) check=1;
        }
        if (check==1) cout<<"Y";
        else cout<<"N";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}