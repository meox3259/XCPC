#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	vector<int> digit(10000000);
	for(int i = 0; i < 10000000; ++i) {
		int x = i;
		while(x) {
			digit[i] += x % 10;
			x /= 10;
		}
	}

	vector<vector<int> > ans(155, vector<int> (11, inf));
	for(int i = 0; i < 10000000; ++i) {
		int sum = 0;
		for(int j = 0; j < 10 && i + j < 10000000; ++j) {
			sum += digit[i + j];
			if(sum < 155) {
				ans[sum][j] = min(ans[sum][j], i);
			}
		}
	}

	while(T--) {
		int n, k;
		cin >> n >> k;

		if(k >= 2) {
			cout << (ans[n][k] == inf ? -1 : ans[n][k]) << '\n';
		} else {
			if(k == 0) {
				vector<int> ans;
				while(n >= 9) {
					ans.emplace_back(9);
					n -= 9;
				}
				if(n != 0) {
					ans.emplace_back(n);
				}
				reverse(ans.begin(), ans.end());
				for(int i : ans) {
					cout << i;
				}
				cout << '\n';
			} else {
				long long Ans = 1000000000000000000;
				if(n == 1) {
					cout << 0 << '\n';
					continue;
				}
				if(n % 2 == 1) {
					int x = n / 2;
					vector<int> ans;
					while(x >= 18) {
						ans.emplace_back(9);
						x -= 9;
					}
					if(x < 10) {
						if(x != 9) {
							ans.emplace_back(x);
						} else {
							ans.emplace_back(8);
							ans.emplace_back(1);
						}
					} else {
						ans.emplace_back(8);
						ans.emplace_back(x - 8);
					}
					reverse(ans.begin(), ans.end());
					for(int i = (int)ans.size() - 1; i >= 0; --i) {
						if(ans[i] != 9) {
							swap(ans[i], ans[(int)ans.size() - 1]);
							break;
						}
					}
					long long v = 0;
					for(int i : ans) {
						v = v * 10 + i;
					}
					Ans = min(Ans, v);
				} else {
					int x = n - 10;
					x /= 2;
					if(x >= 0) {
						vector<int> ans;
						ans.emplace_back(9);
						if(x < 9) {
							ans.emplace_back(x);
						} else {
							ans.emplace_back(8);
							x -= 8;
							while(x >= 9) {
								ans.emplace_back(9);
								x -= 9;
							}
							if(x > 0) {
								ans.emplace_back(x);
							}
						}
						long long v = 0;
						reverse(ans.begin(), ans.end());
						for(int i : ans) {
							v = v * 10 + i;
						}
						Ans = min(Ans, v);
					}
				}

				cout << (Ans == 1000000000000000000 ? -1 : Ans) << '\n';
			}
		}
	}

	return 0;
}
