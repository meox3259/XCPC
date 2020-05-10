#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, a, b, c;
	cin >> a >> b >> c >> k;

	int ans = 0;
	ans += min(k, a);
	k -= min(k, a);
	k -= min(k, b);
	ans -= min(k, c);

	cout << ans << '\n';

	return 0;
}
