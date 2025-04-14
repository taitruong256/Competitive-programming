/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
int minPrime[1000001], cnt[1000001];

void phantich_tu(int n) {
    while (n > 1) {
        --cnt[minPrime[n]];
        n /= minPrime[n];
    }
}

void phantich_mau(int n) {
    while (n > 1) {
        ++cnt[minPrime[n]];
        n /= minPrime[n];
    }
}

void solve()
{
    int n; cin>>n;
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n; i++) 
    {
        int x; cin>>x;
        phantich_tu(x);
    }                 
    for (int i=0; i<n; i++) 
    {
        int x; cin>>x;
        phantich_mau(x);
    }                  

    for (int i=1; i<=1000000; i++) if (i!=2 && i!=5 && cnt[i]>0)
    {
        cout<<"repeating\n";
        return;
    }
    cout<<"finite\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
   
    int n=1000005;
    minPrime[0]=1;
    for (int i = 2; i * i <= n; ++i) if (minPrime[i] == 0)  //if i is prime
        for (int j = i * i; j <= n; j += i) if (minPrime[j] == 0) 
            minPrime[j] = i;
    for (int i = 2; i <= n; ++i) if (minPrime[i] == 0) minPrime[i] = i;

    int tc=1; cin>>tc;
    for (int t=1; t<=tc; t++) solve();
    return 0;
}