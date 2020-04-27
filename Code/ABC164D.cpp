#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	int sum = 0;

	map<int, int> mp;
	++mp[0];

	long long ans = 0;
	long long pw = 1;

	for(char c : s) {
		sum = (sum + (c - '0') * pw) % 2019;
		pw = pw * 10 % 2019;
		ans += mp[sum];
		++mp[sum];
	}

	cout << ans << '\n';	

	return 0;
}
