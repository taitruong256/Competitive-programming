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
#define ll long long

void solve()
{
    string text, pattern; cin>>text>>pattern;
    ll n=text.size();
    ll m=pattern.size();
    ll lps[m+5];
    memset(lps, 0, sizeof(lps));

    //xay dung day Longest prefix suffix
    ll len=0, i=1, j=0;
    lps[0]=0;
    while (i<m)
    {
        if (pattern[i]==pattern[len])
        {
            lps[i]=len+1;
            ++len;
            ++i;
        }
        else if (len!=0)
            len=lps[len-1];
        else
        {
            lps[i]=0;
            ++i;
        }
    }
    for (ll i=0; i<m; i++) cout<<lps[i]<<" "; cout<<endl;
    
    // KMP search
    i=0; j=0;
    while (i<n)
    {
        if (text[i]==pattern[j])
        {
            ++i;
            ++j;
        }
        else if (j!=0)
            j=lps[j-1];
        else ++i;

        if (j==m)
        {
            cout<<i-j+1<<" ";
            j=lps[j-1];
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