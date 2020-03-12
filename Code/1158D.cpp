#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a = (n - k) / 2;
	for(int i = 0; i < n; ++i) {
		cout << ((i + 1) % (a + 1) == 0);
	}
	return 0;
}
