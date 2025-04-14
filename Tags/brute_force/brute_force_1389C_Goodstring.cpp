/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s, t, kq; cin>>s;     
    ll n=s.size(), ans=1e9;
    for (char a='0'; a<='9'; a++)
    {
        for (char b='0'; b<='9'; b++)
        {
            t="";
            t=t+a+b;            //cout<<t<<endl;
            ll i=0, cnt=0;
            for (auto c: s) 
                if (c!=t[i]) ++cnt; 
                else i^=1;
            if (a!=b && (n-cnt)%2==1) ++cnt;
            if (cnt<ans) ans=cnt, kq=t;
        }
    }
    cout<<ans<<endl;  //cout<<kq<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll tc=1; cin>>tc;
    for (ll t=1; t<=tc; t++) solve();
    return 0;
}