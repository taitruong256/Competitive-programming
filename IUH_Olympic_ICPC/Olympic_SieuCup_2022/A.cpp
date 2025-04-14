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
                                Hãy hoàn thành công việc một cách cẩu thả nhất
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll mod = 1e9+7;
ll n, k, t; 
set<ll> st;

void query(ll l, ll r)
{
    ll l_mid=(l+r)/2, r_mid=(l+r)/2;
    cout<<"QUERY "<<l_mid<<" "<<0<<endl;
    for (ll i=0; i<k; i++)
    {
        ll x, y; cin>>x>>y;
        st.insert(x);
        l_mid=min(l_mid, x);
        r_mid=max(r_mid, x);
    }
    if (st.size()==n) return;
    if (l==r) return;
    if (l<=l_mid) query(l, l_mid);
    if (r_mid<=r) query(r_mid, r);
}

void solve()
{
    cin>>n>>k>>t;
    assert(k!=1);
    ll l=-1e9, r=1e9;
    cout<<"QUERY "<<l<<" "<<0<<endl;
    for (ll i=0; i<k; i++)
    {
        ll x, y; cin>>x>>y;
        st.insert(x);
        l=max(l, x);
    }
    if (st.size()==n)
    {
        cout<<"ANSWER"<<endl;
        for (auto i: st) cout<<i<<" "<<0<<endl;
        return;
    }
    cout<<"QUERY "<<r<<" "<<0<<endl;
    for (ll i=0; i<k; i++)
    {
        ll x, y; cin>>x>>y;
        st.insert(x);
        r=min(r, x);
    }
    if (st.size()==n)
    {
        cout<<"ANSWER"<<endl;
        for (auto i: st) cout<<i<<" "<<0<<endl;
        return;
    }
    query(l, r);
    cout<<"ANSWER"<<endl;
    for (auto i: st) cout<<i<<" "<<0<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}