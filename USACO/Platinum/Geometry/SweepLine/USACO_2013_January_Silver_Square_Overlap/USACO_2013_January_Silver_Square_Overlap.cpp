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
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define point pair<ll, ll>
#define X first 
#define Y second 
const ll inf = 1e18;
const ll mod = 1e9+7;

void setIO(string s)
{
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}

void solve()
{
    setIO("squares");
    ll n, k; cin>>n>>k;
    point p[n+5];
    for (ll i=1; i<=n; i++) cin>>p[i].X>>p[i].Y;
    sort(p+1, p+n+1);
    set<point> st;
    st.insert({p[1].Y, 1});
    vector<point> ans;
    for (ll l=1, r=2; r<=n; r++)
    {
        while (l<r && p[l].X+k<=p[r].X) st.erase({p[l].Y, l}), ++l;
        st.insert({p[r].Y, r});
        auto low=st.lower_bound({p[r].Y, r});
        auto high=st.lower_bound({p[r].Y, r});
        if (low!=st.begin() && abs((*--low).X-p[r].Y)<=k-1) ans.push_back({(*low).Y, r});
        if (++high!=st.end() && abs((*high).X-p[r].Y)<=k-1) ans.push_back({(*high).Y, r});
    }
    if (ans.size()==0) cout<<0;
    else if (ans.size()>1) cout<<-1;
    else 
    {
        ll id1=ans[0].first, id2=ans[0].second;
        ll x1=max(p[id1].X-k/2, p[id2].X-k/2);
        ll x2=min(p[id1].X+k/2, p[id2].X+k/2);
        ll y1=max(p[id1].Y-k/2, p[id2].Y-k/2);
        ll y2=min(p[id1].Y+k/2, p[id2].Y+k/2);   
        cout<<abs(x1-x2)*abs(y1-y2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}