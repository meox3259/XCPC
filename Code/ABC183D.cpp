#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w;
	cin >> n >> w;

	vector<int> s(n);
	vector<int> t(n);
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i] >> t[i] >> p[i];
	}

	vector<long long> sum(200001);
	for(int i = 0; i < n; ++i) {
		sum[s[i]] += p[i];
		sum[t[i]] -= p[i];
	}

	for(int i = 0; i < 200000; ++i) {
		sum[i + 1] += sum[i];
	}

	if(*max_element(sum.begin(), sum.end()) > w) {
		cout << "No" << '\n';
	} else {
		cout << "Yes" << '\n';
	}

	return 0;
}
