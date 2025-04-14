#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define ld long double
#define endl '\n'
#define sz(x) (ll)(x.size())
const ll mod = 1e9+7;


// const int maxn = 1e3+5;
// const int N = 2e4+5;
// char board[maxn][20];
// int cnt[N], dem[N];
// int n, m; 

// namespace sol1 {
//     int solve() {
//         // cin >> n >> m;
//         // for(int i=1; i<=n; i++) {
//         //     for(int j=1; j<=m; j++) cin >> board[i][j];
//         // }
//         vector<vector<int>> ans(n+5, vector<int>(m+5));
//         vector<vector<int>> ans2(n+5, vector<int>(m+5));
//         int color = 1;
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=m; j++) {
//                 if(ans[i][j]!=0) continue;
//                 if(board[i][j] == '#') {
//                     int k = j; 
//                     while(k<=m && board[i][k] == '#') {
//                         ans[i][k] = color; 
//                         k++;
//                         cnt[color]++;
//                     }
//                     color++;
//                 }
//             }
//         }
//         int fin = color -1;
//         // cout<<fin <<'\n';
//         for(int i=1; i<=m; i++) {
//             for(int j=1; j<=n; j++) {
//                 if(ans[j][i]==0) continue;
//                 int c = ans[j][i];
//                 if(cnt[c]!=1) continue;
//                 int k = j+1;

//                 if(k<=n&&ans[k][i] !=0 && cnt[ans[k][i]]==1) {
//                     // cout<< k <<" "<<i<<'\n';
//                     fin--; 
//                 }
            
//             }
//         }

//         color = 1;
//         for(int j=1; j<=m; j++) {
//             for(int i=1; i<=n; i++) {
//                 if(ans2[i][j]!=0) continue;
//                 if(board[i][j] == '#') {
//                     int k = i; 
//                     while(k<=n && board[k][j] == '#') {
//                         ans2[k][j] = color; 
//                         k++;
//                         dem[color]++;
//                     }
//                     color++;
//                 }
//             }
//         }
//         int fin2 = color -1;
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=m; j++) {
//                 if(ans2[i][j]==0) continue;
//                 int c = ans2[i][j];
//                 if(dem[c]!=1) continue;
//                 int k = j+1;
//                 if(k<=m && ans2[i][k]!=0 && dem[ans2[i][k]]==1) fin2--; 
            
//             }
//         }
//         // cout<<fin <<" "<<fin2 <<'\n';
//         // for(int i=1; i<=n; i++) {
//         //     for(int j=1; j<=m; j++) {
//         //         cout<<ans2[i][j]<<" ";
//         //     }
//         //     cout<<'\n';
//         // }
//         return min(fin, fin2);
//     }
// }




namespace sol2 {
    ll n, m, hang[1005], cot[15];
char c[1005][105];

tuple<ll, ll, ll> max_bien(ll x1, ll y1, ll x2, ll y2)
{
    tuple<ll, ll, ll> ans={0, 0, 0};


    ll len1=0;
    for (ll i=x1; i<=x2+1; i++)
    {
        if (c[i][y1]=='#') ++len1;
        else 
        {
            ans=max(ans, {len1, i-len1, 1});
            len1=0;
        }
    }


    ll len2=0;
    for (ll i=x1; i<=x2+1; i++)
    {
        if (c[i][y2]=='#') ++len2;
        else 
        {
            ans=max(ans, {len2, i-len2, 2});
            len2=0;
        }
    }


    ll len3=0;
    for (ll i=y1; i<=y2+1; i++)
    {
        if (c[x1][i]=='#') ++len3;
        else 
        {
            ans=max(ans, {len3, i-len3, 3});
            len3=0;
        }
    }


    ll len4=0;
    for (ll i=y1; i<=y2+1; i++)
    {
        if (c[x2][i]=='#') ++len4;
        else 
        {
            ans=max(ans, {len4, i-len4, 4});
            len4=0;
        }
    }


    return ans;
}

pair<ll, ll> min_bien(ll x1, ll y1, ll x2, ll y2)
{
    pair<ll, ll> ans={1e18, 0};
    
    ll len1=0;
    for (ll i=x1; i<=x2; i++)
        if (c[i][y1]=='#') ++len1;
    ans=min(ans, {len1, 1});

    ll len2=0;
    for (ll i=x1; i<=x2; i++)
        if (c[i][y2]=='#') ++len2;
    ans=min(ans, {len2, 2});

    ll len3=0;
    for (ll i=y1; i<=y2; i++)
        if (c[x1][i]=='#') ++len3;
    ans=min(ans, {len3, 3});

    ll len4=0;
    for (ll i=y1; i<=y2; i++)
        if (c[x2][i]=='#') ++len4;
    ans=min(ans, {len4, 4});

    return ans;
}

int solve()
{
    cin>>n>>m;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=m; j++)
        {
            cin>>c[i][j];
            hang[i]+=(c[i][j]=='#');
            cot[j]+=(c[i][j]=='#');
        }
    // cout<< n<<" "<<m <<'\n';
    ll x1=1;
    ll x2=n;
    ll y1=1;
    ll y2=m;
    // cout<<x1 <<" "<<x2<<" "<<y1<<" "<<y2<<'\n';
    // return 0;
    while (x1<=x2 && y1<=y2)
    {
        auto [minlen, mingoc]=min_bien(x1, y1, x2, y2);
        if (minlen==0) 
        {
            if (mingoc==1) ++y1;
            else if (mingoc==2) --y2;
            else if (mingoc==3) ++x1;
            else --x2;
        }
        else break;
        // cout<<"min goc: "<<mingoc<<" "<<minlen<<endl;
        // cout<<"toa do min: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }
    ll ans=0;
    // return ans;
    while (x1<=x2 && y1<=y2)
    {
        cout<< x1 <<" "<<x2<<'\n';
        ++ans;
        auto [maxlen, maxpos, maxgoc]=max_bien(x1, y1, x2, y2);
        if (maxgoc==1) 
            for (ll i=maxpos; i<=maxpos+maxlen-1; i++) c[i][y1]='.';
        else if (maxgoc==2) 
            for (ll i=maxpos; i<=maxpos+maxlen-1; i++) c[i][y2]='.';
        else if (maxgoc==3)
            for (ll i=maxpos; i<=maxpos+maxlen-1; i++) c[x1][i]='.';
        else 
            for (ll i=maxpos; i<=maxpos+maxlen-1; i++) c[x2][i]='.';

        // cout<<"maxlen, maxpos va maxgoc: "<<maxlen<<" "<<" "<<maxpos<<" "<<maxgoc<<endl;
        // for (ll i=1; i<=n; i++)
        // {
        //     for (ll j=1; j<=m; j++) cout<<c[i][j];
        //     cout<<endl;
        // }
        while (x1<=x2 && y1<=y2)
        {
            auto [minlen, mingoc]=min_bien(x1, y1, x2, y2);
            if (minlen==0) 
            {
                if (mingoc==1) ++y1;
                else if (mingoc==2) --y2;
                else if (mingoc==3) ++x1;
                else --x2;
            }
            else break;
            // cout<<"min goc: "<<mingoc<<" "<<minlen<<endl;
            // cout<<"toa do min: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }
        // cout<<"end: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl<<endl;
    }
    return ans;
}

}




int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    // int ans = sol1::solve();
    // cin >> n >> m;
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m;j++) cin >> board[i][j];
    // }
    int ans = sol2::solve();
    // int ans1 = sol1::solve();
    cout<<ans<<'\n';
    // cout<<min(ans, ans1)<<'\n';
    // ans = min(ans, sol2::solve());
    // cout<<ans<<'\n';
    return 0;
}