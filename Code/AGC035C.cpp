#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if(n == 1) {
		cout << "No" << '\n';
		exit(0);
	}

	int t = 1;
	while(t * 2 <= n + 1) {
		t = t * 2;
	}

	int Xor = 0;
	for(int i = t; i <= n; ++i) {
		Xor ^= i;
	}

	int cnt = 0;
	for(int i = t; i <= n; ++i) {
		if(i & t) {
			cnt += 1;
		}
	}

	if(cnt % 2 == 0) {
		cout << "Yes" << '\n';
		for(int i = 1; i < t - 1; ++i) {
			cout << i << ' ' << i + 1 << '\n';
		}

		cout << t - 1 << ' ' << 1 + n << '\n';
	
		for(int i = 1; i < t - 1; ++i) {
			cout << i + n << ' ' << i + n + 1 << '\n';
		}

		for(int i = t; i < n; ++i) {
			cout << i << ' ' << i + 1 << '\n';
		}

		if(Xor != 0) {
			cout << n << ' ' << Xor << '\n';
			cout << Xor << ' ' << t + n << '\n';
		} else if(n > t) {
			cout << n << ' ' << 1 << '\n';
			cout << n << ' ' << t + n << '\n';
		}
	
		for(int i = t; i < n; ++i) {
			cout << i + n << ' ' << i + n + 1 << '\n';
		}
	} else {
		if(cnt == 1) {
			cout << "No" << '\n';
		} else {
			cout << "Yes" << '\n';
			int Xor = 0;
			for(int i = t; i < n; ++i) {
				Xor ^= i;
			}
			if(Xor == 0) {
				for(int i = t; i < n - 1; ++i) {
					cout << i << ' ' << i + 1 << '\n';
					cout << i + n << ' ' << i + 1 + n << '\n';
				}
				cout << n - 1 << ' ' << t + n << '\n';
				for(int i = 1; i < t - 1; ++i) {
					cout << i << ' ' << i + 1 << '\n';
					cout << i + n << ' ' << i + 1 + n << '\n';
				}
				cout << t - 1 << ' ' << 1 + n << '\n';
				int v = n ^ t;
				cout << n << ' ' << t << '\n';
				cout << t << ' ' << v << '\n';
				cout << v << ' ' << n + n << '\n';
			} else {
				for(int i = t; i < n - 1; ++i) {
					cout << i << ' ' << i + 1 << '\n';
					cout << i + n << ' ' << i + 1 + n << '\n';
				}	
				cout << n - 1 << ' ' << Xor << '\n';
				cout << Xor << ' ' << t + n << '\n';
				int v = n ^ t ^ Xor;
				cout << n << ' ' << t + n << '\n';
				cout << v << ' ' << n + n << '\n';
				vector<int> node;
				node.emplace_back(Xor);
				node.emplace_back(v);
				for(int i = 1; i < t; ++i) {
					if(i != Xor && i != v) {
						node.emplace_back(i);
					}	
				}
				for(int i = 0; i + 1 < node.size(); ++i) {
					cout << node[i] << ' ' << node[i + 1] << '\n';
					cout << node[i] + n << ' ' << node[i + 1] + n << '\n';
				}
				cout << node.back() << ' ' << node[0] + n << '\n';
			}
		}
	}

	return 0;
}
