#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int> > a;
	vector<pair<int, int> > b;

	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int pre = 0;
		int mn = 0;
		for(char c : s) {
			if(c == '(') {
				++pre;
			} else {
				--pre;
			}
			mn = min(mn, pre);
		}
		a.emplace_back(mn, pre);
	}
	
	sort(a.begin(), a.end(), [&] (auto x, auto y) {
		return min(x.first, x.second + y.first) > min(y.first, y.second + x.first);
	});

	int cur = 0;
	for(auto o : a) {
		if(cur + o.first < 0) {
			cout << "No" << '\n';
			exit(0);
		}
		cur += o.second;
	}

	if(cur == 0) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
