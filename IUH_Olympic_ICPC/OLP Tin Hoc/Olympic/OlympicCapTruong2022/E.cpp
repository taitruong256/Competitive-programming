/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll n=0;
string cam, s;
char c; 
ll val[266];
char chr[266];

bool check(ll x)
{
    string t=to_string(x);
    for (ll i=0; i<t.size(); i++)
    {
        for (ll j=0; j<cam.size(); j++) if (t[i]==(val[cam[j]]+'0')) return false;
    }
    return true;
}

void solve()
{
    val['a']=0;
    val['z']=1;
    val['e']=2;
    val['g']=3;
    val['i']=4;
    val['m']=5;
    val['t']=6;
    val['u']=7;
    val['c']=8;
    val['h']=9;
    chr['0']='a';
    chr['1']='z';
    chr['2']='e';
    chr['3']='g';
    chr['4']='i';
    chr['5']='m';
    chr['6']='t';
    chr['7']='u';
    chr['8']='c';
    chr['9']='h';
    chr['-']='-';
    cin>>s;
    cin>>c;
    cin>>cam;
    for (ll i=0; i<s.size(); i++) n=n*10+val[s[i]];           //cout<<n<<endl;
    string ans="";
    for (ll i=n; i>=-1e6; i--) if (check(i)==true) 
    {
        ans=to_string(i);
        break;
    }
    
    cout<<ans<<" ";
    for (ll i=0; i<ans.size(); i++) cout<<chr[ans[i]];
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