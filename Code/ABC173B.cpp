#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	map<string, int> mp;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		mp[s] += 1;
	}

	cout << "AC" << ' ' << "x" << ' ' << mp["AC"] << '\n';
	cout << "WA" << ' ' << "x" << ' ' << mp["WA"] << '\n';
	cout << "TLE" << ' ' << "x" << ' ' << mp["TLE"] << '\n';
	cout << "RE" << ' ' << "x" << ' ' << mp["RE"] << '\n';

	return 0;
}
