#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve()
{
     int n, i =1; cin>>n;
    double sum = 0.0;
    do{
        sum += 1.0/(i*(i+1));
        i++;
    }while(i<=n);
    printf("%.9lf", (1-sum)*1000000000.0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    clock_t start = clock();
//    #ifndef ONLINE_JUDGE
//    freopen("_input.txt", "r", stdin);
//    freopen("_output.txt", "w", stdout);
//    #endif
    solve();
    clock_t end = clock();
    cerr<<"Time: "<<fixed<<setprecision(10)<<double(end-start)/double(CLOCKS_PER_SEC)<<"\n";
    return 0;
}
