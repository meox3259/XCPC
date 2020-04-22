#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	a.resize(n);

	for(int &i : a) {
		cin >> i;
		--i;
	}

	vector<int> pos;
	pos.resize(n);

	for(int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}

	long long ans = 0;

	vector<int> st;
	vector<int> small;

	for(int i = 0; i < n; ++i) {
		while(!st.empty() && a[i] > a[st.back()]) {
			st.pop_back();
		}

		while(!small.empty() && a[i] < a[small.back()]) {
			small.pop_back();
		}

		if(st.empty()) {
			ans += small.size();
		} else {
			int p = upper_bound(small.begin(), small.end(), st.back()) - small.begin();
			ans += (int)small.size() - p;
		}

		if(small.empty()) {
			ans += st.size();
		} else {
			int p = upper_bound(st.begin(), st.end(), small.back()) - st.begin();
			ans += (int)st.size() - p;
		}
		
		small.emplace_back(i);
		st.emplace_back(i);
	}

	cout << ans << '\n';

	return 0;
}
