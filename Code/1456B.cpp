#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> bit(31);
	for(int i = 0; i < n; ++i) {
		for(int j = 30; j >= 0; --j) {
			if(a[i] >> j & 1) {
				bit[j] += 1;
				break;
			}
		}	
	}

	if(*max_element(bit.begin(), bit.end()) > 2) {
		cout << 1 << '\n';
		exit(0);
	} 

	if(*max_element(bit.begin(), bit.end()) == 1) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<int> pre(n + 1);
	for(int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] ^ a[i];
	}

	int ans = inf;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			for(int k = j + 1; k <= n; ++k) {
				if((pre[j] ^ pre[i - 1]) > (pre[k] ^ pre[j])) {
					ans = min(ans, k - i - 1);
				}
			}
		}
	}

	cout << (ans == inf ? -1 : ans) << '\n';

	return 0;
}
