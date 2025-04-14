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
                                          Noi dau + Suy ngam = Tien bo 
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;

struct point 
{
    long double x, y;
    bool operator< (const point &other)
    {
        if (y==other.y) return x<other.x;
        return y<other.y;
    }
};

long double dist(point A, point B)
{
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

struct comp
{
    bool operator()(const point &A, const point &B) const 
    {
        if (A.x==B.x) return A.y<B.y;
        return A.x<B.x;
    }
};

void solve()
{
    while (true)
    {
        ll n; cin>>n; 
        pair<point, point> ans;
        if (n==0) return;
        point p[n+5];
        for (ll i=1; i<=n; i++) cin>>p[i].x>>p[i].y;
        sort(p+1, p+n+1);
        set<point, comp> st;
        // for (ll i=1; i<=n; i++) st.insert(p[i]);
        // for (auto i: st) cout<<i.x<<" "<<i.y<<endl;
        st.insert(p[1]);
        ll l=1;
        long double mn=1e18;
        for (ll r=2; r<=n; r++)
        {
            long double d=sqrtl(mn);
            while (l<r && p[l].y<p[r].y-d) st.erase(p[l++]);
            auto low=st.lower_bound({p[r].x-d, -1e18});
            auto high=st.upper_bound({p[r].x+d, -1e18});
            for (auto i=low; i!=high; i++) 
                if (dist(*i, p[r])<mn)
                {
                    mn=dist(*i, p[r]);
                    ans.first=*i;
                    ans.second=p[r];
                }
            st.insert(p[r]);
        }
        cout<<fixed<<setprecision(2)<<ans.first.x<<" "<<ans.first.y<<" "<<ans.second.x<<" "<<ans.second.y<<endl;
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