#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int t;
	cin >> t;
	while (t--){
		cin >> n;
			string x = to_string(n);
            int sz = x.size();
			int count(0);
			for(int i = 0; i < sz; i++)
			{
				count++;
			}
			cout << count << endl;
			while(sz){
			 cout << n / (int)pow(10, sz);
			 n = n % sz;
			}
	}
	return 0;
	}
