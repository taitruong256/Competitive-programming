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
Cho mảng a có n phần tử. Nhiệm vụ là xóa một số vị trí sao cho chi phí là nhỏ nhất.
Chi phí xóa một số phần tử p1, p2, ...pk là max của:
    -sum(a[p1], a[p2], ..., a[pk])
    -max(sum(a[1..p1]), sum(a[p1+1...p2]), ... sum(a[p[k-1]+1..p[k]])) giá trị lớn nhất của tổng từng subarray

Input
3
6
1 4 5 3 3 2
5
1 2 3 4 5
6
4 1 6 3 10 7
Output

The first test case matches with the array from the statement. To obtain a cost of 7, you need to block the elements at positions 2 and 4. In this case, the cost of the array is calculated as the maximum of:
    -the sum of the blocked elements, which is a2+a4=7
    -the maximum sum of the segments into which the array is divided when the blocked elements are removed, i.e., the maximum of a1, a3, a5+a6=max(1,5,5)=5
So the cost is max(7,5)=7

In the second test case, you can block the elements at positions 1 and 4.

In the third test case, to obtain the answer 11, you can block the elements at positions 2 and 5. There are other ways to get this answer, for example, blocking positions 4 and 6

Ý tưởng:
-Chiến lược chặt nhị phân, việc còn lại là tìm chiến lượt để kiểm tra xem mid có phù hợp hay không
    -Gọi dp[i] là giá trị nhỏ nhất của tổng a[p1], a[p2], ... a[pk] mà pk kết thúc tại i, tổng mỗi subarray <= mid
    -dp[i]=a[i]+min(dp[j]) với j là vị trí sao cho tổng của subarray a[j..i-1] <=mid 
    -Kiểm tra xem giá trị dp[i] nhỏ nhất sao cho dp[i]<=mid và sum[i+1..n]<=mid có nhỏ hơn hoặc bằng mid hay không?
    -Dùng segment tree hoặc siling window để tìm dp[j] nhỏ nhất.
*/

ll n, a[100005], dp[100005], pref[100005];

struct segment_tree
{
    vector<ll> tree;
    ll n;

    segment_tree(){}
    void init(ll _n)
    {
        n=_n;
        tree.resize(0);
        tree.resize(4*n+5, 1e18);
    }

    ll opt(ll x, ll y)
    {
        return min(x, y);
    }

    ll query(ll id, ll l, ll r, ll u, ll v)
    {
        if (u>v || l>v || r<u) return 1e18;
        if (u<=l && r<=v) return tree[id];
        ll mid=(l+r)/2;
        return opt(query(id*2, l, mid, u, v), query(id*2+1, mid+1, r, u, v));
    }

    void update(ll id, ll l, ll r, ll pos, ll v)
    {
        if (l>pos || r<pos) return;
        if (pos<=l && r<=pos) 
        {
            tree[id]=v;
            return;
        }
        ll mid=(l+r)/2;
        update(id*2, l, mid, pos, v);
        update(id*2+1, mid+1, r, pos, v);
        tree[id]=opt(tree[id*2], tree[id*2+1]);
    }
};
segment_tree seg;



bool check(ll mid)
{
    seg.init(n+1);
    seg.update(1, 0, n, 0, 0);
    for (ll i=1; i<=n; i++)
    {
        ll pos=lower_bound(pref, pref+n+1, pref[i-1]-mid)-pref;
        dp[i]=seg.query(1, 0, n, pos, i-1)+a[i];
        seg.update(1, 0, n, i, dp[i]);
        // cout<<mid<<" "<<i<<" "<<pos<<" "<<dp[i]<<endl;
    }   
    ll sum=0;
    for (ll i=n; i>=1; i--) 
    {
        if (sum<=mid && dp[i]<=mid) return true;
        sum+=a[i];
    }
    return false;
}

void solve()
{
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=1; i<=n; i++) pref[i]=pref[i-1]+a[i];
    ll l=1, r=1e15, ans=pref[n];             
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
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