/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector<pair<ll, ll>> ans;

void hanoi(ll n, ll nguon, ll trunggian, ll dich)
{
    if (n==1) 
    {
        ans.push_back({nguon, dich});
        return;
    }
    hanoi(n-1, nguon, dich, trunggian);
    hanoi(1, nguon, trunggian, dich);
    hanoi(n-1, trunggian, nguon, dich);
}

void solve()
{
    ll n; cin>>n;
    hanoi(n, 1, 2, 3);
    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.first<<" "<<it.second<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}