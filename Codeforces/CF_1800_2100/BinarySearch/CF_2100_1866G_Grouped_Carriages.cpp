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
Ban dau co n toa tau, moi toa co a[i] hang khach, hang khach toa thu i co the di chuyen trong doan [i-d[i], i+d[i]]
Goi Z la so luong hang khach lon nhat trong 1 toa tau
Tim Z nho nhat.

Test
Input
7
7 4 2 0 5 8 3
4 0 0 1 3 1 3
Output
5

Note
One strategy that is optimal is as follows:

5 people in carriage 1 move to carriage 4 (going through 3 doors).
3 people in carriage 5 move to carriage 3 (going through 2 doors).
2 people in carriage 6 move to carriage 5 (going through 1 door).
1 person in carriage 6 moves to carriage 7 (going through 1 door).
The number of passengers in each carriage becomes [2,4,5,5,4,5,4]
.

Y tuong: 
Neu tim ra chien luot de hang khach toi da tren moi toa tau la z thi co the chat nhi phan tim z nho nhat
Chien luoc:
    -Ban dau cho tat ca hang khach toa thu i o vi tri trai nhat max(1LL, i-d[i])
    -Sau do lan luot chuyen hang khach tu toa thu i sang toa thu i+1 neu last<=i 
    -Dung priority queue de uu tien nhung khach co gioi han phai min(n, i+d[i]) nho nhat truoc.
*/

ll n, a[200005], d[200005];
vector<pair<ll, ll>> seg[200005];

bool check(ll z)
{
    vector<ll> b(n+5, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i=1; i<=n; i++)
    {
        for (pair<ll, ll> j: seg[i]) pq.push(j);
        while (!pq.empty() && b[i]<z)
        {
            auto [lst, rem]=pq.top(); pq.pop();
            ll cnt=min(z-b[i], rem);
            b[i]+=cnt;
            rem-=cnt;
            if (rem>0) pq.push({lst, rem});
        }
        if (!pq.empty() && pq.top().first<=i) return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) cin>>d[i];
    for (ll i=1; i<=n; i++) if (a[i]!=0) seg[max(1LL, i-d[i])].push_back({min(n, i+d[i]), a[i]});
    ll l=0, r=1e9, ans=-1;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)==true) ans=mid, r=mid-1;
        else l=mid+1;
    }
    assert(ans!=-1);
    cout<<ans;
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