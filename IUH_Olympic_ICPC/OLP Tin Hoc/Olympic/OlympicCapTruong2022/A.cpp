/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    string s; cin>>s;
    char dau[1000];
    string giatri[1000];
    ll cnt=0;
    string t="";
    s=s+"-";
    for (ll i=0; i<s.size(); i++) 
    {         
        if (s[i]=='+' || s[i]=='-') 
        {
            dau[++cnt]=s[i];
            giatri[cnt-1]=t;
            t="";
        }
        else t+=s[i];
    }
    ll sum=0;
    for (ll i=1; i<=cnt-1; i++)
    {
        ll x=0;
        string st=giatri[i];
        for (ll i=0; i<st.size(); i++) x=x*10+(st[i]-'0');
        if (dau[i]=='+') sum+=x;
        else if (dau[i]=='-') sum-=x;
    }
    cout<<sum;
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