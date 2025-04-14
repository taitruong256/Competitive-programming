/*=====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
int minPrime[1000005];

void phantich_tu(int n, map<int, int> &tu) {
    while (n > 1) {
        ++tu[minPrime[n]];
        n /= minPrime[n];
    }
}

void phantich_mau(int n, map<int, int> &mau) {
    while (n > 1) {
        ++mau[minPrime[n]];
        n /= minPrime[n];
    }
}

void solve()
{
    int n; cin>>n;
    map<int, int> tu, mau;
    
    for (int i=0; i<n; i++) 
    {
        int x; cin>>x;
        phantich_tu(x, tu);
    }
    for (int i=0; i<n; i++) 
    {
        int x; cin>>x;
        phantich_mau(x, mau);
    }
    // tu.erase(2);
    // tu.erase(5);
    // mau.erase(2);
    // mau.erase(5);

    // for (auto it: tu) cout<<it.first<<" "<<it.second<<endl;cout<<endl;
    // for (auto it: mau) cout<<it.first<<" "<<it.second<<endl; cout<<endl<<endl;

    for (auto it: mau) if (it.first!=2 && it.first!=5 && it.second-tu[it.first]>0)
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
   
    int n=1000000;
    minPrime[0]=1;
    for (int i = 2; i * i <= n; ++i) if (minPrime[i] == 0)  //if i is prime
        for (int j = i * i; j <= n; j += i) if (minPrime[j] == 0) 
            minPrime[j] = i;
    for (int i = 2; i <= n; ++i) if (minPrime[i] == 0) minPrime[i] = i;

    int tc=1; cin>>tc;
    for (int t=1; t<=tc; t++) solve();
    return 0;
}