#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> f(n);
	for(int &i : f) {
		cin >> i;
		--i;
	}

	vector<int> to(n);
	iota(to.begin(), to.end(), 0);

	for(int i = 0; i < n; ++i) {
		if(f[i] != -1) {
			
		}
	}

	vector<bool> vis(n);

	for(int i : f) {
		if(i != -1) {
			vis[i] = true;
		}
	}

	vector<int> st;

	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			while(f[to[i]] != -1) {
				to[i] = f[to[i]];
			}
			st.emplace_back(i);
		}
	}

	while(st.size() > 1) {
		int i = st.back();
		st.pop_back();
		int j = st.back();
		st.pop_back();
		f[to[i]] = j;
		to[i] = to[j];
		st.emplace_back(i);
	}

	int x = st.back();
	f[to[x]] = x;

	for(int i : f) {
		cout << i + 1 << ' ';
	}

	cout << '\n';

	return 0;
}
