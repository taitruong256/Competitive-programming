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
    ll a, b; cin>>a>>b;
    string s; cin>>s;
    ll n=s.size();
    s=" "+s;
    map<char, ll> cnt;
    for (ll i=1; i<=n/2; i++)
    {
        char c1=s[i], c2=s[n-i+1];
        if (c1=='?' && c2=='?') continue;
        if (c1!='?' && c2!='?' && c1!=c2)
        {
            cout<<-1<<endl;
            return;
        }
        if (c1=='?') 
        {
            s[i]=s[n-i+1];
            if (s[n-i+1]=='0') a-=2;
            else b-=2;
        }
        else if (c2=='?')
        {
            s[n-i+1]=s[i];
            if (s[i]=='0') a-=2;
            else b-=2;
        }
        else 
        {
            if (c1==c2 && c1=='0') a-=2;
            else b-=2;
        }
    }


    for (ll i=1; i<=n/2; i++) if (s[i]=='?' && s[n-i+1]=='?')
    {
        if (a>1) 
        {
            s[i]=s[n-i+1]='0';
            a-=2;
        }
        else if (b>1)
        {
            s[i]=s[n-i+1]='1';
            b-=2;
        }
    }


    if (n%2==1)
    {
        if (a>0 && s[n/2+1]=='0') --a, s[n/2+1]='0';
        else if (b>0 && s[n/2+1]=='1') --b, s[n/2+1]='1';
        if (a>0 && s[n/2+1]=='?') --a, s[n/2+1]='0';
        else if (b>0 && s[n/2+1]=='?') --b, s[n/2+1]='1';
    }
    
    if (a==0 && b==0) for (ll i=1; i<=n; i++) cout<<s[i];
    else cout<<-1;
    cout<<endl;
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