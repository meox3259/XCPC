#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> m;
	m.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> m[i];
	}
	vector<int> st;
	vector<ll> pre;
	vector<ll> suf;
	pre.resize(n);
	suf.resize(n);
	for(int i = 0; i < n; ++i) {
		while(!st.empty() && m[st.back()] > m[i]) {
			st.pop_back();
		}
		if(!st.empty()) {
			pre[i] = pre[st.back()] + 1LL * (i - st.back()) * m[i];
		} else {
			pre[i] = 1LL * (i + 1) * m[i];
		}
		st.emplace_back(i);
	}
	reverse(m.begin(), m.end());
	st.clear();
	for(int i = 0; i < n; ++i) {
		while(!st.empty() && m[st.back()] > m[i]) {
			st.pop_back();
		}
		if(!st.empty()) {
			suf[i] = suf[st.back()] + 1LL * (i - st.back()) * m[i];
		} else {
			suf[i] = 1LL * (i + 1) * m[i];
		}
		st.emplace_back(i);
	}
	reverse(m.begin(), m.end());
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, pre[i] + suf[n - i - 1] - m[i]);
	}
	for(int i = 0; i < n; ++i) {
		if(pre[i] + suf[n - i - 1] - m[i] == ans) {
			vector<int> seq;
			seq.resize(n);
			seq[i] = m[i];
			for(int j = i - 1; j >= 0; --j) {
				if(m[j] > seq[j + 1]) {
					seq[j] = seq[j + 1];
				} else {
					seq[j] = m[j];
				}
			}
			for(int j = i + 1; j < n; ++j) {
				if(m[j] > seq[j - 1]) {
					seq[j] = seq[j - 1];
				} else {
					seq[j] = m[j];
				}
			}
			for(int j = 0; j < n; ++j) {
				cout << seq[j] << ' ';
			}
			cout << '\n';
			return 0;
		}
	}
	return 0;
}
