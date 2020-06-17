#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	for(int i = 0; i < k; ++i) {
		if(*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end())) {
			break;
		}
		string t = s;
		reverse(t.begin(), t.end());
		string x = s + t;
		
		vector<string> tmp;
		for(int i = 0; i < n; ++i) {
			tmp.emplace_back(x.substr(i, n));
		}
		sort(tmp.begin(), tmp.end());
		s = *min_element(tmp.begin(), tmp.end());
		reverse(s.begin(), s.end());
	}

	reverse(s.begin(), s.end());

	cout << s << '\n';

	return 0;
}
