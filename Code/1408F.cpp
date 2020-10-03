#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}

int main() {
	int n;
	cin >> n;

	if(n == 1) {
		cout << 0 << '\n';
		exit(0);
	}

	vector<pair<int, int> > ans;
	function<void(int, int, vector<int>)> cdq = [&] (int l, int r, vector<int> a) {
		if(l == r) {
			return;
		}
		int mid = l + r >> 1;
		cdq(l, mid, a);
		cdq(mid + 1, r, a);
		int len = mid - l + 1;
		for(int i = 0; i < len; ++i) {
			ans.emplace_back(a[l + i], a[mid + 1 + i]);
		}
	};

	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	vector<vector<int> > q;
	for(int i = 22; i >= 0; --i) {
		if(n >> i & 1) {
			vector<int> tmp;
			for(int j = 0; j < 1 << i; ++j) {
				tmp.emplace_back(id.back());
				id.pop_back();
			}
			cdq(0, (1 << i) - 1, tmp);
			q.emplace_back(tmp);
		}
	}	

	reverse(q.begin(), q.end());

	vector<int> big = q.back();
	q.pop_back();

	reverse(q.begin(), q.end());	
	while(q.size() >= 2) {
		vector<int> x = q.back();
		q.pop_back();
		vector<int> y = q.back();
		q.pop_back();
		while(x.size() != y.size()) {
			vector<int> tmp;
			for(int i = 0; i < x.size(); ++i) {
				tmp.emplace_back(big.back());
				ans.emplace_back(x[i], big.back());
				big.pop_back();
			}
			for(int i : tmp) {
				x.emplace_back(i);
			}
		}
		for(int i = 0; i < x.size(); ++i) {
			ans.emplace_back(x[i], y[i]);
		}
		for(int i : x) {
			y.emplace_back(i);
		}
		q.emplace_back(y);
	}

	cout << ans.size() << '\n';
	for(auto [x, y] : ans) {
		cout << x + 1 << ' ' << y + 1 << '\n';
	}

	return 0;
}
