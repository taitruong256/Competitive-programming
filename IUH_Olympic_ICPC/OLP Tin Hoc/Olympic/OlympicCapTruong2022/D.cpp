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

void solve()
{
    ll a, b, c; cin>>a>>b>>c;
    ll temp2=0;
    if (a%3==2 && b%3==2 && c>=3)
    {
        temp2=temp2+a/3+b/3+(c-3)/3;
        temp2+=2;
    }
    else if (b%3==2 && c%3==2 && a>=3)
    {
        temp2=temp2+b/3+c/3+(a-3)/3;
        temp2+=2;
    }
    else if (a%3==2 && c%3==2 && b>=3)
    {
        temp2=temp2+a/3+c/3+(b-3)/3;
        temp2+=2;
    }

    ll ans=min(min(a, b), c);
    ll temp=a/3+b/3+c/3;
    a%=3; b%=3; c%=3;
    temp+=min(min(a, b), c);
    ans=max(max(ans, temp2), temp);
    cout<<ans;
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