/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a chacntion.' - Mohamed Ali 
                  You may not be the best, but must be the most effort
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll cnt[1000005], check[1000005], a[1000005], res[1000005];

void solve() {
    ll n; cin>>n;
    for(ll i=0; i<n; i++) cin>>a[i], ++cnt[a[i]];
    int max_val=*max_element(a, a+n);
    for(ll i=0; i<n; i++) 
    {
        if(check[a[i]]==0) 
        {
            ll now=a[i]*2;
            ll tam=0;
            for(ll j=now; j<=max_val; j+=now) if(cnt[j]>0) tam+=cnt[j];
            res[i]=(tam*(tam-1))/2;
            check[a[i]]=res[i];
        }
        else res[i]=check[a[i]];
    }

    for(int i=0; i<n; i++) cout<<res[i]<<" ";
    cout<<endl;
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