#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second-a.first<b.second-b.first;
}

void solve()
{               
    ll n; cin>>n; 
    set<ll> s;
    vector<pair<ll, ll>> v;
    for (ll i=1; i<=n; i++) s.insert(i);
    for (ll i=1; i<=n; i++)
    {
        ll l, r; cin>>l>>r; 
        if (l==r) 
        {
            cout<<l<<" "<<r<<" "<<l<<endl;
            s.erase(s.find(l));
        }
        else 
        {
            v.push_back({l, r});
        }
    }
    sort(v.begin(), v.end(), comp);
    //for (auto it: v) cout<<it.first<<" "<<it.second<<endl;

    for (auto it: v)
    {
        auto p=s.lower_bound(it.first);
        cout<<it.first<<" "<<it.second<<" "<<*p<<endl;
        s.erase(p);
    }
    cout<<endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;              //   cin>>t;
    while (t--) solve();
    return 0;
}