#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                        Try, try, try again until you succeed     
                          Where is the bug, delete it there                     
 =====================================================================================
*/

void solve()
{
    int n, d;
		cin >> n >> d;
		
		int x, MAG = (int)sqrt(d) + 10;
		for(x = 0; x < MAG; x++) {
			if(x + (d + x) / (x + 1) <= n)
				break;
		}
	cout << (x < MAG ? "YES" : "NO") << endl;
}

int main()
{                   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin); 
    freopen("_output.txt", "w", stdout);
    #endif
    ll t=1; cin>>t;
    while (t--) solve();
    return 0;
}