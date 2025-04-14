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
    string s; cin>>s;
    s=s+"    ";
    set<string> st;
    for (ll i=1; i<=4; i++)
        for (ll j=0; j<s.size(); j++) st.insert(s.substr(j, i));
    // for (auto it: st) cout<<it<<endl; cout<<endl;
    
    for (char a='a'; a<='z'; a++) 
    {
        string t="";
        t=t+a;
        if (st.find(t)==st.end())
        {
            cout<<t<<endl;
            return;
        }
    }

    for (char a='a'; a<='z'; a++) 
        for (char b='a'; b<='z'; b++)
        {
            string t="";
            t=t+a+b;
            if (st.find(t)==st.end())
            {
                cout<<t<<endl;
                return;
            }
        }
    
    for (char a='a'; a<='z'; a++) 
        for (char b='a'; b<='z'; b++)
            for (char c='a'; c<='z'; c++)
            {
                string t="";
                t=t+a+b+c;
                if (st.find(t)==st.end())
                {
                    cout<<t<<endl;
                    return;
                }
            }
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