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
==============================================================================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;

void debugg(stack<ll> st)
{
    vector<ll> daytang;
    while (!st.empty())
    {
        daytang.push_back(st.top());
        st.pop();
    }
    reverse(daytang.begin(), daytang.end());
    for (auto it: daytang) cout<<it<<" "; cout<<endl;
}

void solve()
{
    string s; cin>>s;
    ll n=s.size();
    ll a[n+5];
    for (ll i=0; i<n; i++) a[i]=s[i]-'0';
    stack<ll> st;
    st.push(a[0]);   
    for (ll i=1; i<n; i++)
    {
        while (!st.empty() && a[i]<st.top()) st.pop();
        st.push(a[i]);   
    }
    vector<ll> daytang;
    while (!st.empty())
    {
        daytang.push_back(st.top());
        st.pop();
    }
    reverse(daytang.begin(), daytang.end());
    vector<ll> ans=daytang;
    ll i=0, j=0;
    while (i<n && j<daytang.size())
    {
        if (a[i]==daytang[j]) ++i, ++j;
        else 
        {
            ans.push_back(min(9LL, a[i]+1));
            ++i;
        }
    }
    while (i<n)
    {
        ans.push_back(min(9LL, a[i]+1));
        ++i;
    }
    sort(ans.begin(), ans.end());
    for (auto it: ans) cout<<it; cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}