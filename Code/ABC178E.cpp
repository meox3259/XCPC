#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;
const int dx[] = {-1, 1};

long long mx[2][2];
long long mn[2][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			mx[i][j] = -inf;
			mn[i][j] = inf;
		}
	}

	vector<long long> x(n);
	vector<long long> y(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; ++i) {
		for(int a = 0; a < 2; ++a) {
			for(int b = 0; b < 2; ++b) {
				mx[a][b] = max(mx[a][b], x[i] * dx[a] + y[i] * dx[b]);
				mn[a][b] = min(mn[a][b], x[i] * dx[a] + y[i] * dx[b]);
			}
		}
	}

	long long ans = 0;
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			ans = max(ans, mx[i][j] - mn[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}
