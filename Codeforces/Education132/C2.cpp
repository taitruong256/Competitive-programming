/*==============================================================================================================
         __                    __                                             _____     ______    _______
        |  |                  |  |                                           /  __ \   / _____|  / ______|     
      __|  |__              __|  |_                                          |_|  | |  | |       | |  
     |__|   __|            |__|   __|                                             | |  | |____   | |_____ 
        |  |    _____         |  |    ____  __  __  ____    _____    _____       / /   \ ___  \  |  ___  \
        |  |   /  _  \ | |    |  |   /  _/ | | | | /  _  \ /  __ \  /  _  \     / /         | |  | |   | |
        |  |_  | |_| | | |    |  |_  | |   | \_/ | | |_| | | /  \ | | |_| |    / /___   ____| |  | |___| |
        \____\ \____/| |_|    \____\ |_|   \_____/ \_____/ |_|  | | \__   |   |______| |______/  \_______/
                                                                        | |
                                                                      __/ |
                                                                     |___/  
                             Nothing is impossible, only you think it is impossible                 
                                     Try, try, try again until you succeed     
                                        Pratice, practice, and practice
                                       Where is your bug, delete it there
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll mod = 1e9+7;
const ll inf = 1e9;
ll n;
string s; 
bool thoat=false;
string t;
 
ll dequy(ll index, ll sum)
{
    if (index==n)
    {
        if (sum==0) 
        {
            cout<<t<<endl;
            return 1;
        }
        else return 0;
    }
    if (sum<0 || sum>n/2) return 0;
    if (s[index]=='(') 
    {
        t.push_back('(');
        ll a=dequy(index+1, sum+1);
        t.pop_back();
        return a;
    }
    else if (s[index]==')') 
    {
        t.push_back(')');
        ll a=dequy(index+1, sum-1);
        t.pop_back();
        return a;
    }
    else 
    {
        t.push_back(')');
        ll a=dequy(index+1, sum-1);
        t.pop_back();
        t.push_back('(');
        ll b=dequy(index+1, sum+1);
        t.pop_back();
        return a+b;
    }
}
 
void solve()
{
    cin>>s;
    n=s.size();
    if (n%2==1)
    {
        cout<<"NO\n";
        return;
    }
    ll ans=dequy(0, 0);         cout<<ans<<endl;
    if (ans==1) cout<<"YES\n";
    else cout<<"NO\n";
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