#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
	int n;
	cin >> n;

	map<pair<int, int>, bool> mp;
	for(int i = 0; i < n; ++i) {
		mp[{i, i}] = true;
		for(int j = 0; j < 4; ++j) {
			mp[{i + dx[j], i + dy[j]}] = true;
		}
	}

	mp[{-1, -1}] = true;
	mp[{n, n}] = true;

	cout << mp.size() << '\n';
	for(auto o : mp) {
		cout << o.first.first << ' ' << o.first.second << '\n';
	}

	return 0;
}
