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
ll x, y;
 
void dinhdang()
{
    if (y>=60)
    {
        x+=y/60;
        y%=60;
    }
    if (x>=24) x%=24;
}
 
void solve()
{
    string s; cin>>s;
    ll t; cin>>t;   
    set<string> set_str;
    ll hh=(s[0]-'0')*10+(s[1]-'0');
    ll mm=(s[3]-'0')*10+(s[4]-'0');
    string ss=to_string(hh);
    string sx=to_string(mm);
    if (ss.size()<2) ss="0"+ss;
    if (sx.size()<2) sx="0"+sx;
    set_str.insert(ss+":"+sx);
    x=hh+t/60;
    y=mm+t%60;
    ll cnt=0;
    
    while (cnt<30000)
    {
        string st=to_string(x);
        string tt=to_string(y);
        if (st.size()<2) st="0"+st;
        if (tt.size()<2) tt="0"+tt;
        set_str.insert(st+":"+tt);
        x+=t/60;
        y+=t%60;
        dinhdang();
        ++cnt;
    }  
    ll ans=0;
    for (auto it: set_str)
    {
        string p=it;
        string q=p;
        reverse(q.begin(), q.end());
        if (p==q) ++ans; 
    }
    cout<<ans<<endl;
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