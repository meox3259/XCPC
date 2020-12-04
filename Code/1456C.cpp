#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	sort(c.begin(), c.end(), greater<int> ());
	long long sum = 0;
	long long ans = 0;

	vector<long long> v;
	for (int i = 0; i < n; ++i) {
		ans += sum;
		sum += c[i];
		if (sum < 0) {
			for (int j = i + 1; j < n; ++j) {
				v.emplace_back(c[j]);
			}
			sort(v.begin(), v.end());
			v.emplace_back(sum);
			break;
		}
	}
	
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < k; ++i) {
		q.emplace(0);
	}
	q.emplace(0);

	reverse(c.begin(), c.end());
	for (int i = 0; i < v.size(); ++i) {
		int t = q.top();
		q.pop();
		ans += 1LL * v[i] * t;
		t ++;
		q.emplace(t);
	}

	cout << ans << '\n';

	return 0;
}
