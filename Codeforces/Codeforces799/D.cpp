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
    ll hh=(s[0]-'0')*10+(s[1]-'0');
    ll mm=(s[3]-'0')*10+(s[4]-'0');
    vector<string> v;
    string st=to_string(hh);
    string tt=to_string(mm);
    if (st.size()<2) st="0"+st;
    if (tt.size()<2) tt="0"+tt;
    v.push_back(st+":"+tt);
    x=hh+t/60;
    y=mm+t%60;
    set<string> set_str;
    while (x!=hh || y!=mm)
    {
        string st=to_string(x);
        string tt=to_string(y);
        if (st.size()<2) st="0"+st;
        if (tt.size()<2) tt="0"+tt;
        set_str.insert(st+":"+tt);
        x+=t/60;
        y+=t%60;
        dinhdang();
    }  
    ll ans=0;
    for (auto it: set_str)
    {              
        string t=it;
        string dt=t;
        reverse(dt.begin(), dt.end());
        if (dt==t) ++ans;
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