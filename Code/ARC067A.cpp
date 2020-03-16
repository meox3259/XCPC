#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	int n;
	cin >> n;

	vector<bool> mark;
	mark.assign(n + 1, false);

	vector<int> pri;

	for(int i = 2; i <= n; ++i) {
		if(!mark[i]) {
			pri.emplace_back(i);
		}	

		for(int j = i; j <= n; j += i) {
			mark[j] = true;
		}

	}

	vector<int> cnt;
	cnt.resize(pri.size());

	for(int i = 1; i <= n; ++i) {
		int t = i;
		
		for(int j = 0; j < pri.size(); ++j) {
			while(t % pri[j] == 0) {
				t /= pri[j];
				++cnt[j];
			}
		}

	}

	long long ans = 1;

	for(auto x : cnt) {
		ans = ans * (x + 1) % P; 
	}

	cout << ans << '\n';

	return 0;

}
