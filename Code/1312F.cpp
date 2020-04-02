#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;

		vector<vector<int> > f;
		f.resize(N);

		for(int i = 0; i < N; ++i) {
			f[i].resize(3);
		}

		for(int i = 1; i < N; ++i) {
			for(int j = 0; j < 3; ++j) {
				vector<bool> vis;
				vis.resize(N, false);

				vis[f[max(0, i - x)][0]] = 1;
				
				if(j != 1) {
					vis[f[max(0, i - y)][1]] = 1;
				}

				if(j != 2) {
					vis[f[max(0, i - z)][2]] = 1;
				}

				for(int k = 0; ; ++k) {
					if(!vis[k]) {
						f[i][j] = k;
						break;
					}
				}
			}
		}
	
		int period = 1;

		for(; ; ++period) {
			bool ok = true;

			for(int i = 1; i <= period; ++i) {
				for(int j = 0; j < 3; ++j) {
					for(int k = 1; k < 5; ++k) {
						if(f[N - i][j] != f[N - i - k * period][j]) {
							ok = false;
							break;
						}
					}
				}
			}

			if(ok) {
				break;
			}
		}

		auto sg = [&] (long long x, int k) {
			if(x < N - 1) {
				return f[x][k];
			}

			for(int i = N - 1; i >= 0; --i) {
				if(i % period == x % period) {
					return f[i][k];
				}
			}
		};

		vector<long long> a;
		a.resize(n);

		int SG = 0;

		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			SG ^= sg(a[i], 0);
		}

		int ans = 0;

		for(int i = 0; i < n; ++i) {
			SG ^= sg(a[i], 0);

			if((SG ^ sg(max(0LL, a[i] - x), 0)) == 0) {
				++ans;
			}

			if((SG ^ sg(max(0LL, a[i] - y), 1)) == 0) {
				++ans;
			}

			if((SG ^ sg(max(0LL, a[i] - z), 2)) == 0) {
				++ans;
			}

			SG ^= sg(a[i], 0);
		}

		cout << ans << '\n';
	}

	return 0;
}
