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
void solve()
{  
    ll a, b, c, m, ans=0, size=0; cin>>a>>b>>c>>m;
    vector<ll> USB, PS2;
    for (ll i=0; i<m; i++)
    {
        ll x; cin>>x;
        string s; cin>>s;
        if (s=="USB") USB.push_back(x);
        else PS2.push_back(x);
    }
    sort(USB.begin(), USB.end());
    sort(PS2.begin(), PS2.end());

    ll t1=min(a, (ll)USB.size()), t2=min(b, (ll)PS2.size());    
    for (ll i=0; i<t1; i++) ans+=USB[i];
    for (ll i=0; i<t2; i++) ans+=PS2[i];                         
    size=t1+t2;   
    
    while (c>0 && t1<USB.size() && t2<PS2.size())
    {
        --c;
        if (USB[t1]<PS2[t2]) 
        {
            ans+=USB[t1];
            ++size;
            ++t1;                                      
        }
        else
        {
            ans+=PS2[t2];
            ++size;
            ++t2;                                            
        }
    }                                                             

    while (c>0 && t1<USB.size()) 
    {
        --c;
        ans+=USB[t1];
        ++size;
        ++t1;                                              
    }
    while (c>0 && t2<PS2.size()) 
    {
        --c;
        ans+=PS2[t2];
        ++size;
        ++t2;                                     
    }
    cout<<size<<" "<<ans;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}