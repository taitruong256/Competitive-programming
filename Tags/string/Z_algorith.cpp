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
    string s; cin>>s;
    string t; cin>>t;
    string st=t+"#"+s;
    ll n=st.size();
    ll z[n+5];
    ll left=0, right=0;
    z[0]=0;
    for (ll i=1; i<n; i++)
    {
        if (i>right) 
        {
            left=right=i;
            while (right<n && st[right-left]==st[right]) ++right;
            z[i]=right-left;
            --right;
        }
        else
        {
            ll k=i-left;
            if (z[k]<right-i+1) z[i]=z[k];
            else 
            {
                left=i;
                while (right<n && st[right-left]==st[right]) ++right;
                z[i]=right-left;
                --right;
            }
        }
    }

    // cout<<st<<endl;
    // for (int i=0; i<n; i++) cout<<z[i]<<" "; cout<<endl;
    for (int i=0; i<n; i++) if (z[i]==(ll)t.size()) cout<<i-t.size()<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}