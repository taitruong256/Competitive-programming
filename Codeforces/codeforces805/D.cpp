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
const ll mod = 1e9+7;
const ll inf = 1e9;

void solve()
{
    ll n; cin>>n;
    string a[n+5];
    map<string, bool> xuathien;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<n; i++) xuathien[a[i]]=true;
    for (ll i=0; i<n; i++)
    {
        bool check=false;// cout<<a[i]<<endl<<endl;;
        for (ll j=0; j<a[i].size()-1; j++) 
        {
            if (xuathien[a[i].substr(0, j+1)]==true && xuathien[a[i].substr(j+1, a[i].size())]==true) check=true;
            // cout<<a[i].substr(0, j+1)<<" "<<a[i].substr(j+1, a[i].size())<<endl;
        }
        cout<<check;
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