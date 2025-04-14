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

char rev(char c)
{
    if (c=='(') return ')';
    else if (c=='<') return '>';
    else if (c=='[') return ']';
    return '}';
}

void solve()
{               
    string s; cin>>s;
    stack<char> open;
    ll ans=0;
    for (ll i=0; i<s.size(); i++)  
    {       
        if (s[i]=='[' || s[i]=='{' || s[i]=='<' || s[i]=='(') open.push(s[i]);
        else 
        {                   
            if (open.empty())
            {
                cout<<"Impossible";
                return;
            }        
            if (rev(open.top())==s[i])
            {
                open.pop();
                continue;
            }
            ++ans;
            open.pop();    
        }  
    }
    if (!open.empty()) cout<<"Impossible";
    else cout<<ans;
}

int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;              //   cin>>t;
    while (t--) solve();
    return 0;
}