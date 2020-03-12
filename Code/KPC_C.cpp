#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, k, s;
int main() {
	cin >> n >> k >> s;
	if(s != inf) {
		for(int i = 1; i <= k; ++i) {
			cout << s << " ";
		}
		for(int i = k + 1; i <= n; ++i) {
			cout << inf << " ";
		}
		return 0;
	} else {
		for(int i = 1; i <= k; ++i) {
			cout << s << " ";
		}
		for(int i = k + 1; i <= n; ++i) {
			cout << 1 << " ";
		}
		return 0;
	}
	return 0;
}
