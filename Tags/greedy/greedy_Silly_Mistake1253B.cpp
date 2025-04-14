/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    ll a[n+5];
    for (ll i=0; i<n; i++) cin>>a[i];

    map<ll, ll> cnt;
    ll sl=0, k=0;
    vector<ll> ans;
    for (ll i=0; i<n; i++)
    {
        if (a[i]>0)
        {
            if (cnt.count(a[i])>0)
            {                  
                cout<<-1<<endl;
                return;
            }
            else 
            {
                ++cnt[a[i]];
                ++sl;
                ++k;
            }
        }
        else
        {         
            a[i]=abs(a[i]);                   
            if (cnt[a[i]]==0)
            {                   
                cout<<-1<<endl;
                return;
            }
            else 
            {
                --cnt[a[i]];
                --sl;
            }
        }

        if (sl==0) 
        {
            ans.push_back(2*k);
            k=0;
            cnt.clear();
        }
    }

    if (sl!=0)
    {
        cout<<-1<<endl;
        return;
    }

    cout<<ans.size()<<endl;
    for (ll i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}