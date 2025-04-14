// /*==============================================================================================================
//          __                    __                                             _____     ______    _______
//         |  |                  |  |                                           /  __ \   / _____|  / ______|     
//       __|  |__              __|  |__                                         |_|  | |  | |       | |  
//      |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
//         |  |    _____   _     |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
//         |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
//         |  |_  | |_| | | |    |  |_  | |   | |_| | | |_| | | |  | | | |_| |    / /___   ____| |  | |___| |
//         \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  |_| \____ |   |______| |______/  \_______/
//                                                                         | |
//                                                                       __/ |
//                                                                      |___/  
//                               Nothing is impossible, only you think it is impossible                 
//                                      Try, try, try again until you succeed     
//                                         Pratice, practice, and practice
//                                        Where is your bug, delete it there
// I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
//                               You may not be the best, but must be the most effort
//                  Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
//  I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
// ==============================================================================================================*/
// #include <bits/stdc++.h>
// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// //using namespace __gnu_pbds;
// #define ll long long
// //tree<ll, null_type, less<ll>, rb_tree_tag,
// //tree_order_statistics_node_update> T;             //find_by_order            order_of_key
// #define endl '\n'
// const ll mod = 1e9+7, inf = 1e16;

// void solve()
// {
//     ll n, x; cin>>n>>x;
//     map<ll, ll> dis;
//     queue<ll> q;
//     dis[x]=0;
//     q.push(x);
//     ll ans=-1;
//     while (!q.empty())
//     {
//         ll y=q.front(); q.pop(); 
//         string s=to_string(y);
//         if (s.size()==n) 
//         {
//             ans=dis[y];
//             break;
//         }
//         for (auto c: s) if (c!='0' && c!='1')
//         {
//             ll nxt=y*(c-'0');
//             if (nxt!=0 && dis.find(nxt)==dis.end())
//             {
//                 dis[nxt]=dis[y]+1;
//                 q.push(nxt);
//             }
//         } 
//     }
//     cout<<ans;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//     freopen("_input.txt", "r", stdin);
//     freopen("_output.txt", "w", stdout);
//     #endif
//     clock_t start = clock();
//     solve();
//     clock_t end = clock();
//     cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
//     return 0;
// }









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
                              Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
                 Don't pray for an easy life, pray for the strength to endure a difficult one - Bruce Lee
 I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced 1 kick 10,000 times - Bruce Lee
==============================================================================================================*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
//tree<ll, null_type, less<ll>, rb_tree_tag,
//tree_order_statistics_node_update> T;             //find_by_order            order_of_key
#define endl '\n'
const ll mod = 1e9+7, inf = 1e16;
map<ll, ll> dp;
ll n, x;

ll calc(ll x)
{
    string s=to_string(x);
    if (s.size()==n) return 0;
    if (dp.find(x)!=dp.end()) return dp[x];
    ll ans=inf;
    for (auto c: s) if (c!='0' && c!='1') ans=min(ans, 1+calc(x*(c-'0')));
    return dp[x]=ans;
}

void solve()
{
    cin>>n>>x;
    ll ans=calc(x);
    if (ans==inf) cout<<-1;
    else cout<<calc(x);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<< double(end-start)/ double(CLOCKS_PER_SEC)<<endl;
    return 0;
}