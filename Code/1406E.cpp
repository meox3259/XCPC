#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	auto query = [&] (char type, int mul) {
		cout << type << ' ' << mul << '\n';
		fflush(stdout);
		int ret;
		cin >> ret;
		return ret;
	};

	vector<int> p;
	vector<bool> mark(n + 1);
	for(int i = 2; i <= n; ++i) {
		if(!mark[i]) {
			p.emplace_back(i);
		}
		for(int j = 0; j < p.size() && i * p[j] <= n; ++j) {
			mark[i * p[j]] = true;
			if(i % p[j] == 0) {
				break;
			}
		}
	}

	char A = 'A';
	char B = 'B';
	char C = 'C';

	int ans = 1;
	vector<int> small;
	vector<int> big;
	for(int i : p) {
		if(1LL * i * i <= n) {
			small.emplace_back(i);
		} else {
			big.emplace_back(i);
		}
	}

	vector<bool> vis(n + 1);

	int tot = n;
	function<void(int)> del = [&] (int x) {
		for(int i = x; i <= n; i += x) {
			if(!vis[i]) {
				tot -= 1;
			}
			vis[i] = true;
		}
	};

	int m = big.size();
	int block = (int)ceil(sqrt(m));

	int last = 0;
	for(int i = 0; i < m; ++i) {
		int tmp = query(B, big[i]);
		del(big[i]);
		if((i + 1) % block == 0 || i == m - 1) {
			int cnt = query(A, 1);	
			if(cnt != tot) {
				for(int j = last; j <= i; ++j) {
					if(query(B, big[j]) > 0) {
						ans = ans * big[j];
						break;
					}
				}
				break;
			}
			last = i + 1;
		}
	}

	for(int v : small) {
		int cur = v;	
		int tmp = query(B, v);
		int mul = 1;
		while(cur <= n) {
			int cnt = query(B, cur);
			if(cnt > 0) {
				mul = cur;
			} else {
				break;
			}
			cur = cur * v;
		}
		del(v);
		ans = ans * mul;
	}

	query(C, ans);

	return 0;
}
