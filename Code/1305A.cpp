#include <bits/stdc++.h>
using namespace std;
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> a;
		vector<int> b;
		a.resize(n);
		b.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		for(int i = 0; i < n; ++i) {
			cout << b[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
