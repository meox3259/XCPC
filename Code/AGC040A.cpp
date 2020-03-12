#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();

	vector<pair<int, int> > v;

	int cnt = 0;

	for(int i = 0; i < n; ++i) {
		if(i == 0 || s[i] == s[i - 1]) {
			++cnt;
		} else {
			v.emplace_back(cnt, s[i - 1] == '>' ? 1 : -1);
			cnt = 1;
		}
	}
	v.emplace_back(cnt, s[n - 1] == '>' ? 1 : -1);

	long long ans = 0;

	for(int i = 0; i < (int)v.size(); ++i) {
		ans += 1LL * (v[i].first - 1) * v[i].first / 2;
	}

	for(int i = 0; i < (int)v.size() - 1; ++i) {
		if(v[i].second == -1 && v[i + 1].second == 1) {
			ans += max(v[i].first, v[i + 1].first);
		}
	}

	if(*s.begin() == '>') {
		ans += v.begin() -> first;
	}

	if(s.back() == '<') {
		ans += v.back().first;
	}

	cout << ans << '\n';
	return 0;
}
