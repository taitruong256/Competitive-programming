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
    multiset<ll> chan, le;
    ll ans=0;
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=1; i<n-1; i++) if (a[i]%2==0) chan.insert(a[i]); else le.insert(a[i]);

    if (chan.size()==0)
    {
        if (le.size()<=1)
        {
            cout<<-1<<endl;
            return;
        }
        else if (le.size()==2)
        {
            if (*le.rbegin()==1)
            {
                cout<<-1<<endl;
                return;
            }
            ll sum=0;
            for (auto it: le) sum+=it; 
            sum+=2;
            ans=sum/2;
            cout<<ans<<endl;
            return;
        }
        else
        {
            ll x1, x2, x3;
            x1=*le.rbegin();
            le.erase(le.find(x1));
            x2=*le.rbegin();
            le.erase(le.find(x2));
            x3=*le.rbegin();
            le.erase(le.find(x3));

            //cout<<x1<<" "<<x2<<" "<<x3<<endl;
            if (x1<=1)
            {
                cout<<-1<<endl;
                return;
            }
            chan.insert(x2+1);
            chan.insert(x3+1);
            le.insert(x1-2);
            ans+=1;
        }
    }

    if (chan.size()>0)
    {
        ll tam;
        ll x1, x2;
        if (le.size()>=2)
        {
            tam=*chan.begin();
            chan.erase(chan.find(tam));
            x1=*le.begin();
            le.erase(le.find(x1));
            x2=*le.begin();
            le.erase(le.find(x2));
            chan.insert(x1+1);
            chan.insert(x2+1);
            ans+=1;
            if (tam-2>0) chan.insert(tam-2);
        }
        else if (le.size()==1)
        {
            x1=*le.begin();
            le.erase(le.find(x1));
            tam=*chan.begin();
            chan.erase(chan.find(tam));
            chan.insert(x1+1);
            if (tam-2>0) chan.insert(tam-2);
        }
    }
    for (auto it: chan) ans+=it/2;
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