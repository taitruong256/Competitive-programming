#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 200200

int t, n;
int a[MAXN];
char s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%s", s);

		vector<int> blue, red;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') blue.push_back(a[i]);
			else red.push_back(a[i]);
		}

		sort(blue.begin(), blue.end());
		sort(red.begin(), red.end());
		reverse(red.begin(), red.end());

		bool ok = 1;

		for (int i = 0; i < blue.size(); i++) {
			if (blue[i] < i + 1)
				ok = 0;
		}

		for (int i = 0; i < red.size(); i++) {
			if (red[i] > (n - i))
				ok = 0;
		}

		printf(ok ? "YES\n" : "NO\n");


	}
}
