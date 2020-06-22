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
		
		vector<int> odd;
		vector<int> even;

		for(int i = 0; i < n * 2; ++i) {
			int x;
			cin >> x;
			if(x % 2 == 0) {
				even.emplace_back(i);
			} else {
				odd.emplace_back(i);
			}
		}

		if(even.size() % 2 == 0) {
			if(odd.size() > 0) {
				odd.pop_back();
				odd.pop_back();
			} else {
				even.pop_back();
				even.pop_back();
			}
		} else {
			odd.pop_back();
			even.pop_back();
		}

		while(!odd.empty()) {
			cout << odd.back() + 1 << ' ';
			odd.pop_back();
			cout << odd.back() + 1 << '\n';
			odd.pop_back();
		}

		while(!even.empty()) {
			cout << even.back() + 1 << ' ';
			even.pop_back();
			cout << even.back() + 1 << '\n';
			even.pop_back();
		}
	}

	return 0;
}
