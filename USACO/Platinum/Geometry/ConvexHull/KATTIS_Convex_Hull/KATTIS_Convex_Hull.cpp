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
                                          Pain + Reflection = Progress 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
 
ll cross(pair<ll, ll> A, pair<ll, ll> B)
{
    return A.first*B.second-A.second*B.first;
}
 
bool comp(pair<ll, ll> A, pair<ll, ll> B)
{
    return atan2(A.second, A.first)<atan2(B.second, B.first);
}
 
void solve()
{
    while(true)
    {
        ll n; cin>>n; 
        if (n==0) break;
        vector<pair<ll, ll>> p(n), hull;
        for (ll i=0; i<n; i++) cin>>p[i].first>>p[i].second;
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end())-p.begin());
        if (p.size()<3)
        {
            sort(p.begin(), p.end(), comp);
            cout<<p.size()<<endl;
            for (auto [x, y]: p) cout<<x<<" "<<y<<endl;
            return;
        }
        n=p.size();
        for (ll k=1; k<=2; k++)
        {
            for (ll i=0; i<n; i++) 
            {
                while (hull.size()>=2)
                {
                    pair<ll, ll> A=hull[hull.size()-2], B=hull[hull.size()-1], C=p[i];
                    if (cross({B.first-A.first, B.second-A.second}, {C.first-A.first, C.second-A.second})<0) hull.pop_back();
                    else break;
                }
                hull.push_back(p[i]);
            }
            hull.pop_back();
            reverse(p.begin(), p.end());
        }
        sort(hull.begin(), hull.end(), comp);
        cout<<hull.size()<<endl;
        for (auto [x, y]: hull) cout<<x<<" "<<y<<endl;
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
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}