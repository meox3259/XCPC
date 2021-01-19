#include <bits/stdc++.h>

using namespace std;

template <class T>
class LinearBase {
	private:
	vector<T> b;	
	int N;

	public:
	LinearBase() {}
	LinearBase(int _N) : N(_N), b(_N + 1) {}

	void insert(T v) {
		for (int i = N; i >= 0; --i) {
			if (v >> i & 1) {
				if (b[i] != 0) {
					v ^= b[i];
				} else {
					b[i] = v;
					return;
				}
			}
		}
	}

	T Max() {
		T ret = 0;
		for (int i = N; i >= 0; --i) {
			if ((ret ^ b[i]) > ret) {
				ret ^= b[i];
			}
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum ^= a[i];
	}

	long long ans = 0;
	for (int i = 0; i < 61; ++i) {
		if (sum >> i & 1) {
			ans += 1LL << i;
		}
	}

	for (int i = 0; i < 61; ++i) {
		if (sum >> i & 1) {
			for (int j = 0; j < n; ++j) {
				if (a[j] >> i & 1) {
					a[j] ^= 1LL << i;
				}
			}
		}
	}

	LinearBase<long long> s(60);
	for (auto i : a) {
		s.insert(i);
	}

	cout << ans + s.Max() * 2 << '\n';

	return 0;
}
