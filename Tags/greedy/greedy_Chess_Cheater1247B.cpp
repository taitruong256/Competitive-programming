/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, k; cin>>n>>k;
    string s; cin>>s;
    s+="$";  //linh canh

    ll win=0, lost=0, cnt=0;
    vector<ll> streak;
    for (ll i=0; i<n; i++) 
    {
        if (s[i]=='W') 
        {
            ++win;
            if (s[i+1]=='L' || s[i+1]=='$') ++cnt;
        }
        else if (s[i]=='L')
        {
            ++lost;
            if (s[i+1]=='W' || s[i+1]=='$') 
            {
                streak.push_back(lost);
                lost=0;
            }
        }
    }                                

    if (k>=n-win) 
    {
        cout<<2*n-1<<endl;
        return;
    }
    if (win==0)
    {
        if (k==0) cout<<0<<endl;
        else cout<<2*k-1<<endl;
        return;
    }

    if (s[0]=='L') streak[0]=1e9;
    if (s[n-1]=='L') streak.back()=1e9;
    sort(streak.begin(), streak.end());
    win+=k;
    for (ll i=0; i<streak.size(); i++)
    {
        if (streak[i]>k) break;
        k-=streak[i];
        --cnt;
    }
    cout<<2*win-cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;  cin>>t;
    while (t--) solve();
    return 0;
}