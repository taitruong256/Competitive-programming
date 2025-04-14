/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tinh(string s, char c)
{      
    if (s.size()==1) 
    {
        if (c==s[0]) return 0;
        else return 1;
    }
    ll mid=s.size()/2;
    ll left=tinh(s.substr(0, mid), c+1);
    ll cnt1=0;
    for (ll i=mid; i<s.size(); i++) if (s[i]==c) ++cnt1;
    cnt1=s.size()/2-cnt1;
    ll right=tinh(s.substr(mid, s.size()), c+1);
    ll cnt2=0;
    for (ll i=0; i<mid; i++) if (s[i]==c) ++cnt2;
    cnt2=s.size()/2-cnt2;
     // cout<<s<<" "<<c<<" "<<left<<" "<<cnt1<<" "<<right<<" "<<cnt2<<endl;
    return min(left+cnt1, right+cnt2);
}

void solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    cout<<tinh(s, 'a')<<endl;
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