
#include <bits/stdc++.h>
 
using namespace std;
#define show1 cerr << "*\n"
#define show2 cerr << "**\n"
#define show3 cerr << "***\n"
#define hello_i_am_Salmon ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1000000000;

int main()
{
	hello_i_am_Salmon
	int n; cin >> n;
	string x;
	map<string, int> cnt;
	vector<string> a;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		a.push_back(x);
		cnt[x]++;
	}
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		ans = 0;
		while(true)
		{
			a[i] += a[i][a[i].size()-1];
			ans++;
			if(cnt[a[i]] == 0)
			{
				break;
			}
		}
		cout << ans << '\n';
	}

}