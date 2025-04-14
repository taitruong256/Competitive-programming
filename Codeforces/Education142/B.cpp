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

void solve()
{
    ll a1, a2, a3, a4; cin>>a1>>a2>>a3>>a4;
    if (a1==0)
    {
        cout<<1<<endl;
        return;
    }




    //ke chuyen a1
    ll ans=a1, x=a1, y=a1;
    if (a2>a3)
    {
        //ke chuyen a2
        ll t=min(a1, a2);
        ans+=t;
        a2-=t;
        x+=t;
        y-=t;

        //ke chuyen lan luot a3 va a2
        t=min(a2/(2*a1), a3/(2*a1));
        a2-=2*a1*t;
        a3-=2*a1*t;
        ans+=4*a1*t;

        //ke chuyen a3
        ans+=a3;
        x-=a3;
        y+=a3;
        a3=0;

        //ke chuyen a2
        t=min(a2, y);
        ans+=t;
        x+=t;
        y-=t;

        //ke chuyen a4
        ans+=min({x+1, y+1, a4});
        cout<<ans<<endl;
        return;
    }
    else 
    {
        //ke chuyen a3
        ll t=min(a1, a3);
        ans+=t;
        a3-=t;
        x-=t;
        y+=t;

        //ke chuyen lan luot a3 va a2
        t=min(a2/(2*a1), a3/(2*a1));
        a2-=2*a1*t;
        a3-=2*a1*t;
        ans+=4*a1*t;

        //ke chuyen a2
        ans+=a2;
        x+=a2;
        y-=a2;
        a2=0;

        //ke chuyen a3
        t=min(a3, x);
        ans+=t;
        x-=t;
        y+=t;

        //ke chuyen a4
        ans+=min({x+1, y+1, a4});
        cout<<ans<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}