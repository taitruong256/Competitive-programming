/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
                           Pratice, practice, and practice
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pos, temp, ans, sum;
string a, b;
void dfs(int step, int cnt)
{
    if (step == a.length())
    {
        if (cnt == pos)ans++; 
        sum++; return;
    }
    if (b[step] == '+') dfs(step + 1, cnt + 1);
    else if (b[step] == '-') dfs(step + 1, cnt - 1);
    else if(b[step]=='?')
    { 
        dfs(step + 1, cnt + 1); 
        dfs(step + 1, cnt - 1);\
    }
}

void solve()
{
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) 
    {
        if (a[i] == '+')pos++;
        else if (a[i] == '-')pos--;
    }
    dfs(0, 0);
    printf("%.9lf",1.0*ans/sum);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1;// cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}