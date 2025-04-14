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

void solve()
{
    ll q; cin>>q;
    ll cnt1[30], cnt2[30];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    cnt1[0]=1;
    cnt2[0]=1;
    while (q--)
    {
        ll type, k; string s;
        cin>>type>>k>>s; 
        ll cnts[30];
        memset(cnts, 0, sizeof(cnts));
        for (auto i: s) ++cnts[i-'a'];
        for (ll i=0; i<26; i++) cnts[i]*=k;
        if (type==1)
            for (ll i=0; i<26; i++) cnt1[i]+=cnts[i];
        else 
            for (ll i=0; i<26; i++) cnt2[i]+=cnts[i];
        for (ll i=0; i<26; i++) cout<<cnt1[i]<<" "; cout<<endl;
        for (ll i=0; i<26; i++) cout<<cnt2[i]<<" "; cout<<endl; cout<<endl;
        

        ll i=0, j=25;
        while (i<26 && j>=0)
        {
            while (i<26 && cnt1[i]==0) ++i;
            if (cnt2[j]==0) --j;

        }
    }
    cout<<endl;
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