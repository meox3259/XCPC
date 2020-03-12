#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	vector<int> bit;
	bit.resize(100);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		for(int j = 0; j < 31; ++j) {
			if(v[i] >> j & 1) {
				++bit[j];
			}
		}
	}
	int ans = 0, p = 0;
	for(int i = 0; i < n; ++i) {
		int tmp = 0;
		for(int j = 0; j < 31; ++j) {
			if(v[i] >> j & 1) {
				if(bit[j] == 1) {
					tmp += (1 << j);
				}
			}
		}
		if(tmp > ans) {
			ans = tmp;
			p = i;
		}
	}
	cout << (1 << 30) << '\n';
	cout << v[p] << ' ';
	for(int i = 0; i < n; ++i) {
		if(i != p) {
			cout << v[i] << ' ';
		}
	}
	return 0;
}
