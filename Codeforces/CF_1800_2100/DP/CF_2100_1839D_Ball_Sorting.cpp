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
Co n vien bi duoc to mau tu 1 den n, va so k.
Co 2 thao tac:
    loai 1: dat vien bi mau 0 vao giua hai vien bi bat ky (thao tac loai 1 khong duoc vuot qua k vi chi co k vien mau 0)
    loai 2: chon 1 vien bi khac 0 ke mau 0, vao di chuyen vien bi den vi tri bat ky, 
    giu nguyen thu tu tuong doi cac vien bi con lai. Ban mat 1 dong.
Hoi so tien it nhat de sap sep cac vien bi tang dan color[i]=i voi moi k=[1..n] (k tu 1 den n)

Input
3
6
2 3 1 4 6 5
3
1 2 3
11
7 3 4 6 8 9 10 2 5 11 1
Output
3 2 2 2 2 2 
0 0 0 
10 5 4 4 4 4 4 4 4 4 4 


In the first test case there are n=6 balls. The colors of the balls from left to right are [2,3,1,4,6,5].
Let's suppose k=1. One of the ways to reorder the balls in the required way for 3 coins:
[2,3,1,4,6,5] −→1 [2,3,1,4,0,6,5] −→2 [2,3,4,1,0,6,5] −→2 [1,2,3,4,0,6,5] −→2 [1,2,3,4,0,5,6]
The number above the arrow is the operation type. Balls inserted on the operations of the first type are highlighted red; balls moved on the operations of second type are highlighted blue.
It can be shown that for k=1
 it is impossible to rearrange balls in correct order for less than 3 coins.

Let's suppose k=2. One of the ways to reorder the balls in the required way for 2 coins:
[2,3,1,4,6,5] −→1 [2,3,1,4,6,0,5] −→2 [2,3,1,4,0,5,6] −→1 [2,3,0,1,4,0,5,6] −→2 [1,2,3,0,4,0,5,6]

Y tuong:
Goi tap S chua nhung vien bi se giu nguyen vi tri tuong doi la nhung vien thoa a[i]+1=a[i+1]. Nhung vien con lai se di chuyen.
=> dap an voi moi k se la min(n-|S|) thoa f(S)<=k
Goi f(S) la so phan doan bi tach boi nhung doan thoa a[i]+1=a[i+1]
Vi du: a=[7, 3, 4, 6, 8, 9, 10, 2, 5, 11, 1], S=[[3, 4], [8, 9, 10]] => tach thanh [7], [6], [2, 5, 11, 1] => f(S)=3

Goi dp[i][k]: gia tri |S| lon nhat trong doan [1..i], i thuoc S, f(S)=k
    dp[i][k]=max(dp[i][k], dp[i-1][k]+1) neu a[i-1]<a[i]   //ket hop mang tang dan o vi tri lien truoc do a[i-1]+1=a[i]
    dp[i][k]=max(dp[i][k], dp[j][k-1]+1)    //i bat dau doan moi
*/

void solve()
{
    ll n; cin>>n;
    ll a[n+5], dp[n+5][n+5];
    for (ll i=1; i<=n; i++) cin>>a[i];


    for (ll i=0; i<=n+1; i++) 
        for (ll j=0; j<=n+1; j++)
            dp[i][j]=-1e2;
    a[0]=0;
    a[n+1]=1e18;
    dp[0][1]=0;
    

    for (ll i=1; i<=n+1; i++)
        if (a[i]>a[i-1]) dp[i][1]=dp[i-1][1]+1;
        else break;


    // for (ll i=0; i<=n+1; i++)
    // {
    //     for (ll j=0; j<=n+1; j++) 
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;


    for (ll k=2; k<=n+1; k++) 
    {
        for (ll i=0; i<=n+1; i++) dp[i][k]=max(dp[i][k], dp[i][k-1]);
        for (ll i=1; i<=n+1; i++)
        {
            for (ll j=0; j<i; j++)
                if (a[j]<a[i]) 
                {
                    if (j+1==i) dp[i][k]=max(dp[i][k], dp[j][k]+1);
                    else dp[i][k]=max(dp[i][k], dp[j][k-1]+1);
                }
        }


        // for (ll i=0; i<=n+1; i++)
        // {
        //     for (ll j=0; j<=n+1; j++) 
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    
    ll ans=dp[1][n+1];
    for (ll k=2; k<=n+1; k++) 
    {
        ans=max(ans, dp[n+1][k]);
        cout<<n-ans+1<<" ";
    }
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