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
    string s; cin>>s; 
    int l = 0;
    int ans = 0;
    while(l < s.size())
    {
        map<char,int> cnt;
        int k;
        for(k = l; k < s.size();k++)
        {
            if(cnt[s[k]] == 0)
            {
                ans++;
                cnt[s[k]]++;
            }
            else
            {
                ans--;
                break;
            }
        }
        l = k + 1;

    }
    cout << ans<< endl;
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