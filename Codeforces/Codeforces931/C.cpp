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
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;

void solve()
{
    ll n, m; cin>>n>>m;
    ll a, b, c, d, x, y; 
    cout<<"? "<<1<<" "<<1<<endl;
    cin>>a;
    if (a==0)
    {
        cout<<"! "<<1<<" "<<1<<endl;
        return;
    }
    cout<<"? "<<1<<" "<<m<<endl;
    cin>>b;
    if (b==0)
    {
        cout<<"! "<<1<<" "<<m<<endl;
        return;
    }
    //(x-1)+(y-1)=a    =>     x+y=a+2
    //(x-1)+(m-y)=b    =>     x-y=b-m+1
    //                 =>     x=(a+2+b-m+1)/2
    //                 =>     y=a+2-x
    assert((a+2+b-m+1)%2==0);
    x=(a+2+b-m+1)/2;
    y=a+2-x;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>c;
    if (c==0)
    {
        cout<<"! "<<x<<" "<<y<<endl;
        return;
    }
    //(x-1)+(y-1)=a    =>     x+y=a+2
    //(x-1)+(m-y)=b+c  =>     x-y=b+c-m+1
    //
                     
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