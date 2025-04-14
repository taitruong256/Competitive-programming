#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed     
                      Where is the bug, delete it there                     
 =====================================================================================
*/


void solve()
{               
    set<pair<ll, ll>> s2, s3;
    ll n, id=0; cin>>n;
    while (n--)
    {
        ll t; cin>>t;
        if (t==1)
        {
            ++id;
            ll m; cin>>m;
            s2.insert({id, -m});
            s3.insert({-m, id});
        }
        else if (t==2)
        {
            auto it=*s2.begin();  //s2{id, m}
            cout<<it.first<<" ";
            s2.erase({it.first, it.second});
            s3.erase({it.second, it.first});
        }
        else
        {
            auto it=*s3.begin();  //s3{m, id}  
            cout<<it.second<<" ";
            s2.erase({it.second, it.first});
            s3.erase({it.first, it.second});
        }
    }
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    while (t--) solve();
    return 0;
}