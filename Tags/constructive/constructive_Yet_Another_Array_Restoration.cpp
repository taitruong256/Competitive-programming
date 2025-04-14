/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve()
{
    ll n, x, y; cin>>n>>x>>y;
    vector<ll> ans;
    ans.push_back(1e9);
    ll mn=1e10;
    for (ll d=1; d<=y-x; d++)
    {
        ll cnt=n, need=y, mx=0;
        vector<ll> now;
        bool check=false;
        while (cnt>0 && need>=1)
        {
            if (need==x) check=true;   
            now.push_back(need);
            mx=max(mx, need);
            need-=d;
            --cnt;
        }
        need=y;
        while (cnt>0)
        {
            need+=d;     
            mx=max(mx, need);
            --cnt;
            now.push_back(need);
        }       
        sort(now.begin(), now.end());
        if (check==1 && now.back()<ans.back())
        {
            ans.clear();
            for (auto it: now) ans.push_back(it);
        }
    }
    for (auto it: ans) cout<<it<<" "; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}