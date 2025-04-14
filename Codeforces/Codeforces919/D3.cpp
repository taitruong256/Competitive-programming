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

ll n, q, ans[100005], lst[100005], len[100005];

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++)
    {
        ll type, x; cin>>type>>x;
        if (type==1) lst[i]=x, len[i]=len[i-1]+1;
        else 
        {
            lst[i]=lst[i-1];
            if (len[i-1]>2e18/(x+1)) len[i]=2e18;
            else len[i]=len[i-1]*(x+1);
        }
    }

    for (ll i=1; i<=q; i++)
    {
        ll k; cin>>k;
        while (true)
        {
            ll pos=lower_bound(len+1, len+n+1, k)-len;
            if (len[pos]==k) 
            {
                cout<<lst[pos]<<" ";
                break;
            }
            if (k%len[pos-1]==0)
            {
                cout<<lst[pos-1]<<" ";
                break;
            }
            k%=len[pos-1];
        }
    }

    for (ll i=1; i<=n; i++) lst[i]=len[i]=0;
    cout<<endl;
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