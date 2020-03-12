#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char> > ans;
void e() {
	cout << "YES" << '\n';
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); ++i) {
		auto [p, c] = ans[i];
		cout << p << ' ' << c << '\n';
	}
	exit(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	if(k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO" << '\n';
		return 0;
	}
	for(int i = 1; i < m; ++i) {
		if(k <= n - 1 && n > 1) {
			ans.emplace_back(k, 'D');
			e();
		}
		if(n > 1) {
			ans.emplace_back(n - 1, 'D');
		}
		k -= n - 1;
		if(k <= n - 1 && n > 1) {
			ans.emplace_back(k, 'U');
			e();
		}
		if(n > 1) {
			ans.emplace_back(n - 1, 'U');
		}
		k -= n - 1;
		--k;
		ans.emplace_back(1, 'R');
		if(k == 0) {
			e();
		}
	}
	for(int i = 1; i < n; ++i) {
		--k;
		ans.emplace_back(1, 'D');
		if(!k) {
			e();
		}
		if(m > 1 && k <= m - 1) {
			ans.emplace_back(k, 'L');
			e();
		}
		k -= m - 1;
		if(m > 1) {
			ans.emplace_back(m - 1, 'L');
		}
		if(m > 1 && k <= m - 1) {
			ans.emplace_back(k, 'R');
			e();
		}
		if(m > 1) {
			ans.emplace_back(m - 1, 'R');
		}
		k -= m - 1;
	}
	if(k <= n - 1 && n > 1) {
		ans.emplace_back(k, 'U');
		e();
	}
	k -= n - 1;
	if(n > 1) {
		ans.emplace_back(n - 1, 'U');
	}
	if(!k) {
		e();
	}
	ans.emplace_back(k, 'L');
	e();
	return 0;
}
