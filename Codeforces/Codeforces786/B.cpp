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
map<string, ll> index;

void solve()
{
    string s; cin>>s;
    cout<<index[s]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll cnt=0;
    for (char a='a'; a<='z'; a++)
        for (char b='a'; b<='z'; b++) if (a!=b)
        {
            string t="";
            t=t+a;
            t=t+b;
            ++cnt;
            index[t]=cnt;
        }
    ll t; cin>>t;
    while (t--) solve();
    return 0;
}