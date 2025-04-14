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
    int n, k, min = 0, max = 0;
    cin >> n >> k;
    int a[n+5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < k; i++) {
        min += a[i];
    }
    for (int i = n-1; i >= n -k; i--) 
        max += a[i];
    if (k==0)
    {
        cout<<0<<" "<<0;
        return;
    }
    if (min==1) min=0;
    if (max==1) max=0;
    cout<<min<<" "<<max;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; //cin>>t;
    for (ll tc=1; tc<=t; tc++) solve();
    return 0;
}