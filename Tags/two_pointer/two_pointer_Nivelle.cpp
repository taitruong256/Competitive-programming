/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
string s; 
pair<ll, ll> kq;
double ans=1000000000;

void xuli(ll x)
{
    map<char, ll> mp;
    ll sl=0;
    ll l=1;
    for (ll r=1; r<=n; r++)
    {       
        if (mp[s[r]]==0) ++sl;
        ++mp[s[r]];
        while (l<r && sl>x)
        {
            --mp[s[l]];
            if (mp[s[l]]==0) --sl;
            ++l;
        }
        if ((sl*1.0)/(r-l+1)<ans)
        {
            ans=(sl*1.0)/(r-l+1);
            kq.first=l;
            kq.second=r;
        }//  cout<<l<<" "<<r<<" "<<sl<<endl;
        // for (auto it: mp) cout<<it.first<<" "<<it.second<<endl; cout<<endl;
    }
}

void solve()
{
    cin>>n;
    cin>>s;
    s="@"+s+"$";
    for (ll i=1; i<=26; i++) xuli(i);
    cout<<kq.first<<" "<<kq.second;
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