#include <bits/stdc++.h>
using namespace std;
int h, w, n;
int main() {
	cin >> h >> w >> n;
	int ans = min((n + h - 1) / h, (n + w - 1) / w);
	cout << ans;
	return 0;
}
