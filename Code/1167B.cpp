#include <bits/stdc++.h>

using namespace std;

int main() {
	auto ask = [&] (int i, int j) {
		cout << '?' << ' ';
		cout << i + 1 << ' ' << j + 1 << endl;	
		int ret;
		cin >> ret;
		return ret;
	};

	auto End = [&] (vector<int> ans) {
		cout << '!' << ' ';
		for (int i : ans) {
			cout << i << ' ';
		}
		cout << endl;
		exit(0);
	};


	vector<int> ans(6);
	for (int i = 1; i < 5; ++i) {
		ans[i] = ask(0, i);
	}

	int cnt23 = 0;
	int cnt15 = 0;
	for (int i = 1; i < 5; ++i) {
		if (ans[i] % 23 == 0) {
			cnt23 ++;
		}
		if (ans[i] % 15 == 0) {
			cnt15 ++;
		}
	}

	int sum = 4 + 8 + 15 + 16 + 23 + 42;

	if (cnt23 > 1) {
		ans[5] = sum;	
		ans[0] = 23;
		for (int i = 1; i < 5; ++i) {
			ans[i] = ans[i] / 23;
		}
		for (int i = 0; i < 5; ++i) {
			ans[5] -= ans[i];
		}

		End(ans);
	}

	if (cnt15 > 1) {
		ans[5] = sum;
		ans[0] = 15;
		for (int i = 1; i < 5; ++i) {
			ans[i] = ans[i] / 15;
		}
		for (int i = 0; i < 5; ++i) {
			ans[5] -= ans[i];
		}
		End(ans);
	}

	if (cnt23 == 1) {
		ans[5] = sum;
		for (int i = 1; i < 5; ++i) {
			if (ans[i] % 23 == 0) {
				ans[0] = ans[i] / 23;
				break;
			}
		}
		for (int i = 1; i < 5; ++i) {
			ans[i] = ans[i] / ans[0];
		}
		for (int i = 0; i < 5; ++i) {
			ans[5] -= ans[i];
		}
		End(ans);
	}

	if (cnt15 == 1) {
		ans[5] = sum;
		for (int i = 1; i < 5; ++i) {
			if (ans[i] % 15 == 0) {
				ans[0] = ans[i] / 15;
				break;
			}
		}
		for (int i = 1; i < 5; ++i) {
			ans[i] = ans[i] / ans[0];
		}
		for (int i = 0; i < 5; ++i) {
			ans[5] -= ans[i];
		}
		End(ans);
	}

	return 0;
}
