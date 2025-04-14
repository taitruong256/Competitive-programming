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
    vector<ll> le, chan;
    for (ll i=1; i<n-1; i++) if(a[i]%2==0) chan.push_back(a[i]); else le.push_back(a[i]);
    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end());

    // for (auto it: chan) cout<<it<<" ";
    // for (auto it: le) cout<<it<<" "; cout<<endl;

    ll ans=0;
    while(true)
    {
        if (chan.size()>0)
        {
            ll x1=chan.back();
            chan.pop_back();
            if (le.size()>=2)
            {
                ll x2=le.back();
                le.pop_back();
                ll x3=le.back();
                le.pop_back();
                ++ans;
                if (x1-2>0) chan.push_back(x1-2);
                chan.push_back(++x2);
                chan.push_back(++x3);
            }
            else if (le.size()==1)
            {
                ll x2=le.back();
                le.pop_back();
                ++ans;
                if (x1-2>0) chan.push_back(x1-2);
                chan.push_back(++x2);       
            }
            else 
            {
                chan.push_back(x1);
                break;
            }
        }
        else
        {
            if (le.size()<=1)
            {
                ans=-1;
                break;
            }
            else if (le.size()==2)
            {
                ll x1=le.back();
                le.pop_back();
                ll x2=le.back();
                le.pop_back();
                if (x1==1)
                {
                    ans=-1;
                    break;
                }
                ++ans;
                chan.push_back(++x2);
                if (x1-2>0) le.push_back(x1-2);
            }
            else 
            {
                ll x1=le.back();
                le.pop_back();
                ll x2=le.back();
                le.pop_back();
                ll x3=le.back();
                le.pop_back();
                if (x1==1)
                {
                    ans=-1;
                    break;
                }
                ++ans;
                chan.push_back(++x3);
                chan.push_back(++x2);
                if (x1-2>0) le.push_back(x1-2);
            }
        }
    }

    // cout<<"-- "; for(int i=0; i<chan.size(); i++) cout<<chan[i]<<" "; cout<<endl;
    for (ll i=0; i<chan.size(); i++) ans+=chan[i]/2;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}