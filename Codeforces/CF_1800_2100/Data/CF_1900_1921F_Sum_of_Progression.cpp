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
Cho mảng a có n phần tử.
Có q truy vấn, mỗi truy vấn gồm (s, d, k). Tính tổng a[s]+a[s+d]*2+a[s+2*d]*3+...+a[2*(k-1)*d]*k.

Input
5
3 3
1 1 2
1 2 2
2 2 1
1 1 2
3 1
-100000000 -100000000 -100000000
1 1 3
5 3
1 2 3 4 5
1 2 3
2 3 2
1 1 5
3 1
100000000 100000000 100000000
1 1 3
7 7
34 87 5 42 -44 66 -32
2 2 2
4 3 1
1 3 2
6 2 1
5 2 2
2 5 2
6 1 2
5 1 3 
-600000000 
22 12 55 
600000000 
171 42 118 66 -108 23 2 

Ý tưởng:
Nếu d>sqrt(n):
    Duyệt trâu độ phức tạp O(sqrt(n))
Nếu d<=sqrt(n):
    Dùng mảng tiền tố đã tiền xử lý trước trong O(n.sqrt(n)). Lấy kết quả trong O(1).
*/

ll sum[355][100405], pref[355][100405], n, q, a[100005];

void solve()
{
    cin>>n>>q;
    for (ll i=1; i<=n; i++) cin>>a[i];
    ll block=sqrt(n);
    for (ll d=1; d<=block; d++)
        for (ll i=n; i>=1; i--)
        {
            sum[d][i]=sum[d][i+d]+a[i];
            pref[d][i]=pref[d][i+d]+sum[d][i];
        }

    for (ll i=1; i<=q; i++)
    {
        ll s, d, k; cin>>s>>d>>k;
        if (d>block)
        {
            ll ans=0;
            for (ll i=s; i<=s+d*(k-1); i+=d) ans+=a[i]*((i-s)/d+1);
            cout<<ans<<" ";
        }
        else 
        {
            ll ans=0;
            if (s+k*d>n) ans=pref[d][s];
            else  ans=pref[d][s]-pref[d][s+k*d]-k*sum[d][s+k*d];
            cout<<ans<<" ";
        }
    }
    for (ll i=1; i<=block; i++)
        for (ll j=1; j<=n+i; j++)
            sum[i][j]=pref[i][j]=0;
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