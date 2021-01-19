#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long Max = -1000000000000000000;
	for (int i = 0; i < n; ++i) {
		long long cur = 0;
		for (int j = i; j < n; j += 2) {
			cur += max(0LL, a[j]);	
			Max = max(Max, cur);
		}
	}

	if (Max == 0) {
		int p = max_element(a.begin(), a.end()) - a.begin();
		cout << a[p] << '\n';
		vector<int> ans;
		for (int i = n - 1; i > p; --i) {
			ans.emplace_back(i);
		}
		for (int i = 0; i < p; ++i) {
			ans.emplace_back(0);
		}
		cout << ans.size() << '\n';
		for (int i : ans) {
			cout << i + 1 << '\n';
		}
		exit(0);
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			long long cur = 0;
			vector<int> tmp;
			for (int j = i; j < n; j += 2) {
				cur += max(0LL, a[j]);	
				if (a[j] < 0) {
					tmp.emplace_back(j);	
				}
				if (cur == Max) {
					vector<int> ans;
					for (int k = n - 1; k > j; --k) {
						ans.emplace_back(k);
					}
					for (int k = i + 2; k <= j; k += 2) {
						if (a[k] > 0) {
							ans.emplace_back(i + 1);
						} else {
							ans.emplace_back(i + 2);
						} 
						/* 1 0 0 0 0 0 1
						 * 1 0 0 0 1
						 *
						*/
					}
					for (int k = 0; k < i; ++k) {
						ans.emplace_back(0);
					} 
					cout << Max << '\n';
					cout << ans.size() << '\n';
					for (int i : ans) {
						cout << i + 1 << '\n';
					}
					exit(0);
				}
				tmp.emplace_back(i + 1);
			}
		}
	}

	return 0;
}
