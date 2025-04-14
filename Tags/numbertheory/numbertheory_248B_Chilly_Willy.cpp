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
typedef int ll;

void solve()
{
    ll n; cin>>n;
    if (n<3)
    {
        cout<<-1;
        return;
    }
    if (n==3)
    {
        cout<<210;
        return;
    }
    string ans="1";
    for (ll i=1; i<n; i++) ans+="0";
    ll remain=0;
    for (ll i=0; i<n; i++) remain=(remain*10+ans[i]-'0')%210;
    remain=210-remain;
    ll r=n-1;
    while (remain>0)
    {
        ans[r]=remain%10+'0';
        remain/=10;
        --r;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}