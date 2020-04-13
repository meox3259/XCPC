#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<vector<int> > suf;
	suf.resize(n);

	for(int i = 0; i < n; ++i) {
		suf[i].resize(3);
	}

	suf[n - 1][0] += (s[n - 1] == 'R');
	suf[n - 1][1] += (s[n - 1] == 'G');
	suf[n - 1][2] += (s[n - 1] == 'B');

	for(int i = n - 2; i >= 0; --i) {
		suf[i][0] = suf[i + 1][0] + (s[i] == 'R');
		suf[i][1] = suf[i + 1][1] + (s[i] == 'G');
		suf[i][2] = suf[i + 1][2] + (s[i] == 'B');
	}

	long long ans = 0;

	vector<char> c = {'R', 'G', 'B'};

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int p = -1;

			if(s[i] == s[j]) {
				continue;
			}

			for(int k = 0; k < c.size(); ++k) {
				if(c[k] != s[i] && c[k] != s[j]) {
					p = k;
					break;
				}
			}

			if(j + 1 < n) {
				ans += suf[j + 1][p];
			}

			if(j + j - i < n) {
				ans -= (s[j + j - i] == c[p]);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
