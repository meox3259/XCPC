#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<string> s;

	for(int i = 0; i < n; ++i) {
		string S;
		cin >> S;
		s.emplace(S);
	}

	cout << s.size() << '\n';

	return 0;
}
