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
    ll n; cin >> n;
    string s; cin >> s;
    ll l = 0, count = 0;
    while(l < n){
        stack<char> calc;
        ll temp;
        calc.push(s[l]);
        for(temp = l + 1; temp < n; temp++)
        {
            if(s[temp] == s[l])
            {
                count++;
                l = temp + 1;
                break;
            }
            else
            {
                  if(calc.top() == '(' && s[temp] == ')')
                  {
                      calc.pop();
                      if(calc.empty())
                      {
                          count++;
                          l = temp + 1;
                          break;
                      }
                  }
                  else
                  {
                      calc.push(s[temp]);
                  }
              }
          }
          if(temp == n)
          {
              break;
          }
      }
      cout << count <<" "<<n-l<<"\n";

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