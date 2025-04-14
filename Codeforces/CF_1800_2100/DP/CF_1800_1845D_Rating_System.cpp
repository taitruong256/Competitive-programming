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

/*
Ban dau ban co xep hang la 0.
Sau n tran dau, xep hang cua ban tang len a[i] (tang +a[i] neu a[i] duong, giam -a[i] neu a[i] am).
Co mot luat bo sung: neu xep hang cua ban dat den k, no se khong bao gio giam xuong duoi k (neu xep hang nho hon k thi se thay doi bang k).
Tim k de xep hang cao nhat.

Input
4
4
3 -2 1 2
3
-1 -2 -1
2
4 2
7
5 1 -3 2 -1 -2 2
Output
3
0
25
6

Note
In the first example, if k=3, then the rating changes as follows: 0→3→3→4→6.
In the second example, if k=0, then the rating changes as follows: 0→0→0→0.
In the third example, if k=25, then the rating changes as follows: 0→4→6.
In the fourth example, if k=6, then the rating changes as follows: 0→5→6→6→8→7→6→8.

Y tuong:
Goi pref[i]: tong tien to tu [1..i]
Xep hang cao nhat se bang la: pref[n]-min(sum(l, r))
                             =pref[n]-min(pref[r]-pref[l-1])
                             =pref[n]-pref[r]+max(pref[l-1])

                             => k=pref[l-1]
*/

void solve()
{
    ll n; cin>>n;
    vector<ll> a(n+5), pref(n+5);
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    pair<ll, ll> ans={0, 0};
    ll mx=0;
    for (ll i=1; i<=n; i++)
    {
        mx=max(mx, pref[i-1]);
        ans=max(ans, {pref[n]-pref[i]+mx, mx});
    }             
    cout<<ans.second<<endl;
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