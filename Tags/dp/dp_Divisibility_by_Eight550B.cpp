/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s; 
ll n;
bool f[105][10];
ll truoc[105][10];

void solve()
{
    cin>>s;
    n=s.size();
    memset(truoc, -1, sizeof(truoc));
    
    f[0][(s[0]-'0')%8]=true;
    for (ll i=1; i<n; i++) 
    {
        f[i][(s[i]-'0')%8]=true;
        for (ll j=0; j<8; j++) if (f[i-1][j]==true)
        {
            f[i][j]=true;
            truoc[i][j]=j;

            f[i][(j*10+s[i]-'0')%8]=true;
            truoc[i][(j*10+s[i]-'0')%8]=j;
        }
    }
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