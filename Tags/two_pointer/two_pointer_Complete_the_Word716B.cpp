#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll d[27];
string s; 

void output(ll k)
{
    ll j=0;
    for (ll i=k; i<k+26; i++) if (s[i]=='?')
    {
        while (j<26 && d[j]>0) ++j;
        s[i]='A'+j; 
        ++j;  
    }
}

void fill()
{
    for (ll i=0; i<s.size(); i++) if (s[i]=='?') s[i]='A';
}

void solve()
{  
    cin>>s;
    if (s.size()<26)
    {
        cout<<-1;
        return;
    }

    ll sl=0;
    for (ll i=0; i<26; i++)
    {
        if (s[i]=='?') ++sl;
        else {++d[s[i]-'A']; if (d[s[i]-'A']==1) ++sl;}
    }

    if (sl==26) 
    {
        output(0);
        fill();
        cout<<s;
        return;
    }
    else
    {
        for (ll i=26; i<s.size(); i++)
        {
            if (s[i]=='?') ++sl;
            if (s[i-26]=='?') --sl;
            if (s[i]!='?') { ++d[s[i]-'A']; if (d[s[i]-'A']==1) ++sl;}
            if (s[i-26!='?']) { --d[s[i-26]-'A']; if (d[s[i-26]-'A']==0) --sl;}

            if (sl==26) 
            {
                output(i-25);
                fill();
                cout<<s;
                return;
            }
        }
    }
    cout<<-1;
    return;
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("a_input.txt","r",stdin);
    freopen("a_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}