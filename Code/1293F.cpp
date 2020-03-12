#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> cnt;
	cnt.resize(5001);
	for(int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		++cnt[k];
	}
	vector<int> prime;
	for(int i = 2; i <= 5000; ++i) {
		bool f = 1;
		for(int j = 2; j < i; ++j) {
			if(i % j == 0) {
				f = 0;
				break;
			}
		}
		if(f == 1) {
			prime.emplace_back(i);
		}
	}
	int m = prime.size();
	vector<vector<int> > pre;
	pre.resize(5001);
	for(int i = 0; i <= 5000; ++i) {
		pre[i].resize(m);
	}
	for(int i = 1; i <= 5000; ++i) {
		for(int j = 0; j < m; ++j) {
			pre[i][j] = pre[i - 1][j];
		}
		int t = i;
		for(int j = 0; j < m; ++j) {
			while(t % prime[j] == 0) {
				++pre[i][j];
				t /= prime[j];
			}
		}
	}
	long long ans = 0;
	long long cur = 0;
	vector<int> pos;
	pos.assign(5001, -1);
	for(int i = 1; i <= 5000; ++i) {
		for(int j = 0; j < m; ++j) {
			if(pre[i][j] > 0) {
				pos[i] = j;
			}
			ans += 1LL * cnt[i] * pre[i][j];
			cur += 1LL * cnt[i] * pre[i][j];
		}
	} 
	while(*max_element(pos.begin(), pos.end()) >= 0) {
		vector<int> num;
		num.resize(m);
		for(int i = 1; i <= 5000; ++i) {
			if(pos[i] != -1) {
				num[pos[i]] += cnt[i];
			}	
		}
		int p = max_element(num.begin(), num.end()) - num.begin();
		int mx = num[p];
		if(mx * 2 <= n) {
			break;
		}
		cur -= 2 * mx - n;
		ans = min(ans, cur);
		for(int i = 1; i <= 5000; ++i) {
			if(pos[i] != p) {
				pos[i] = -1;
			}
			if(pos[i] < 0) {
				continue;
			}
			cerr << "i = " << i << '\n';
			--pre[i][p];
			while(pos[i] >= 0 && pre[i][pos[i]] == 0) {
				--pos[i];
			}
		}
	} 
	cout << ans << '\n'; 
	return 0;
}
