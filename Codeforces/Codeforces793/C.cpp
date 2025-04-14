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

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];
    if (n==1)
    {
        cout<<1<<endl;
        return;
    }
    sort(a, a+n);
    vector<ll> truoc, sau;
    for (ll i=0; i<n; i++)
    {
        bool check=true;
        if (sau.size()<truoc.size()) check=false;
        if (check==true)
        {
            if (truoc.empty()) truoc.push_back(a[i]);
            else if (truoc.back()<a[i]) truoc.push_back(a[i]);
            else if (sau.back()<a[i]) sau.push_back(a[i]);
            // else truoc.push_back(a[i]);
        }
        else
        {
            if (sau.empty()) sau.push_back(a[i]);
            else if (sau.back()<a[i]) sau.push_back(a[i]);
            else if (truoc.back()<a[i]) truoc.push_back(a[i]);
            // else sau.push_back(a[i]);
        }
    }
    vector<ll> v;
    for (auto i: truoc) v.push_back(i);
    for (ll i=sau.size()-1; i>=0; i--) v.push_back(sau[i]);
    // for (ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
    ll t1=0, t2=0, mx=0;
    for (ll i=0; i<v.size(); i++) if (v[i]>mx) mx=v[i], t1++;
    mx=0;
    for (ll i=v.size()-1; i>=0; i--) if (v[i]>mx) mx=v[i], t2++;
    cout<<min(t1, t2)<<endl;
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