/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.'  
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    n*=2;
    ll ans=0, num=1;
    stack<ll> st;
    while(n--){
        string s ;
        ll x;
        cin >> s;;
        if(s == "add"){
            cin >> x;
            st.push(x);
        }
        else{
            if(!st.empty()){
                if(st.top()==num) st.pop();
                else{
                    ans++;
                    while(!st.empty()) st.pop();
                }
            } 
            num++;
        }
    }
    cout << ans;
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