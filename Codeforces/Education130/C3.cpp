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
    string s, t; cin>>s>>t; 

    ll a[n+5], b[n+5], c[n+5];
    for (ll i=0; i<=n; i++) a[i]=b[i]=c[i]=0;
    for (ll i=1; i<=n; i++)
    {
        if (s[i-1]=='a') a[i]=a[i-1]+1; else a[i]=a[i-1];
        if (s[i-1]=='b') a[i]=a[i-1]+1; else a[i]=a[i-1];
        if (s[i-1]=='b') a[i]=a[i-1]+1; else a[i]=a[i-1];
    }  


    vector<ll> vs, vt;
    for (ll i=0; i<s.size(); i++) if (s[i]=='a') vs.push_back(i);
    for (ll i=0; i<t.size(); i++) if (t[i]=='a') vt.push_back(i);
    if (vs.size()!=vt.size())
    {
        cout<<"NO\n";
        return;
    }
    for (ll i=0; i<vs.size(); i++) if (vs[i]<vt[i])
    {
        for (ll j=vs[i]; j<vt[i]; j++) 
            if (s[j]=='a' && s[j+1]=='b') swap(s[j], s[j+1]);
            else break;
    }


    vector<ll> vs1, vt1;
    for (ll i=0; i<s.size(); i++) if (s[i]=='c') vs1.push_back(i);
    for (ll i=0; i<t.size(); i++) if (t[i]=='c') vt1.push_back(i);
    if (vs1.size()!=vt1.size())
    {
        cout<<"NO\n";
        return;
    }
    for (ll i=0; i<vs1.size(); i++) if (vs1[i]>vt1[i])
    {
        for (ll j=vs1[i]; j>vt1[i]; j--) 
            if (s[j-1]=='b' && s[j]=='c') swap(s[j-1], s[j]);
            else break;
    }


     vector<ll> vs2, vt2;
    for (ll i=0; i<s.size(); i++) if (s[i]=='b') vs2.push_back(i);
    for (ll i=0; i<t.size(); i++) if (t[i]=='b') vt2.push_back(i);
    if (vs2.size()!=vt2.size())
    {
        cout<<"NO\n";
        return;
    }
    for (ll i=0; i<vs2.size(); i++)
    {
        if (vs2[i]<vt2[i])
        {
            for (ll j=vs2[i]; j<vt2[i]; j++) 
                if (s[j]=='b' && s[j+1]=='c') swap(s[j], s[j+1]);
                else break;
        }
        else if (vs2[i]>vt2[i])
        {
            for (ll j=vs2[i]; j>vt2[i]; j--) 
                if (s[j-1]=='a' && s[j]=='b') swap(s[j-1], s[j]);
                else break;
        }
    }


    
    // cout<<s<<endl<<t<<endl;
    if (s==t) cout<<"YES\n";
    else cout<<"NO\n";
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