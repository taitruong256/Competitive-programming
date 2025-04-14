#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
 =====================================================================================
                Nothing is impossible, only you think it is impossible                 
                    Try, try, try again until you succeed                          
 =====================================================================================
*/
 
void solve()
{
    int t;
cin >> t;
while (t--) {
	int r, c, r_b, c_b, r_d, c_d;
	cin >> r >> c >> r_b >> c_b >> r_d >> c_d;
	int v_c = 1, v_r = 1;
	int step = 0;
	while (r_b != r_d && c_b != c_d) {
		if (r_b == r) {
			v_r = -v_r;
		}
		if (c_b == c) {
			v_c = -v_c;
		}
		r_b = r_b + v_r;
		c_b = c_b + v_c;
		step++;
	}
	cout << step << '\n';
}
}
 
int main()
{                   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt","r",stdin);
    freopen("_output.txt", "w", stdout);
    #endif
	solve();
    return 0;
}