/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    vector<pair<ll, char>> ans;
    deque<ll> dq;
    for (ll i=0; i<n; i++) 
    {
        ll x; cin>>x;
        dq.push_back(x); 
    }

    if (dq.front()<dq.back()) 
    {
       ans.push_back({dq.front(), 'L'});
       dq.pop_front();
    }
    else 
    {
        ans.push_back({dq.back(), 'R'});
        dq.pop_back();
    }     

    bool ok=true;
    while (!dq.empty())
    {     
        ok=false;
        ll x=ans.back().first;
        if (dq.front()>x && dq.back()>x && dq.front()<=dq.back()) 
        {
           ans.push_back({dq.front(), 'L'});
           dq.pop_front();
           ok=true;
        }
        else if (dq.front()>x && dq.back()>x && dq.front()>=dq.back()) 
        {
            ans.push_back({dq.back(), 'R'});
            dq.pop_back();
            ok=true;
        }
        else if (dq.front()>x) 
        {
           ans.push_back({dq.front(), 'L'});
           dq.pop_front();
           ok=true;
        }
        else if (dq.back()>x) 
        {
            ans.push_back({dq.back(), 'R'});
            dq.pop_back();
            ok=true;
        }

        if (ok==false) break;
    }

    cout<<ans.size()<<endl;
    //for (auto it: ans) cout<<it.first; cout<<endl;
    for (auto it: ans) cout<<it.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  //cin>>t;
    for (ll _=0; _<t; _++)
    {
        //cout<<"Test case "<<_<<endl;
        solve();
    }
    return 0;
}