#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<vector<int> > a;
		a.resize(n);

		for(int i = 0; i < n - 1; ++i) {
			int k;
			cin >> k;

			a[i].resize(k);

			for(int &j : a[i]) {
				cin >> j;
				--j;
			}
		}

		vector<set<int> > s;
		s.resize(n);

		for(int i = 0; i < n - 1; ++i) {
			for(int j : a[i]) {
				s[i].emplace(j);
			}
		}

		for(int f = 0; f < n; ++f) {
			vector<set<int> > t = s;

			int last = f;
			bool ok = true;

			vector<int> tmp;

			for(int i = 0; i < n - 1; ++i) {
				tmp.emplace_back(last);

				for(auto &b : t) {
					if(b.count(last)) {
						b.erase(last);
					}
				}
	
				int one = 0;

				for(auto b : t) {
					if(b.size() == 1) {
						++one;
					}
				}

				if(one != 1) {
					ok = false;
					break;
				}
		
				for(auto b : t) {
					if(b.size() == 1) {
						last = *b.begin();
					}
				}
			}

			tmp.emplace_back(last);

			if(!ok) {
				continue;
			}

			vector<int> pos;
			pos.resize(n);

			for(int i = 0; i < n; ++i) {
				pos[tmp[i]] = i;
			}

			for(auto &b : a) {
				sort(b.begin(), b.end(), [&] (int i, int j) {
					return pos[i] < pos[j];		
				});
			}

			vector<vector<int> > b;
			b.resize(n);

			for(int i = 0; i < n - 1; ++i) {
				b[pos[a[i].back()]] = a[i];
			}

			for(int i = 1; i < n; ++i) {
				auto x = b[i];

				bool equal = true;

				for(int j = 0; j < x.size(); ++j) {
					if(tmp[i - j] != x[(int)x.size() - j - 1]) {
						equal = false;
						break;
					}
				}

				if(!equal) {
					ok = false;
					break;
				}
			}

			if(ok) {
				for(int i : tmp) {
					cout << i + 1 << ' ';
				}

				cout << '\n';
				break;
			}
		}
	}

	return 0;
}
