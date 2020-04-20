#include <bits/stdc++.h>

using namespace std;

class BitwiseAnd {
	public:
	vector<long long> lexSmallest(vector<long long> a, int n) {
		int m = a.size();
		for(long long v : a) {
			if(v >= (1LL << 60)) {
				return {};
			}
		}
		for(int i = 0; i < m; ++i) {
			for(int j = i + 1; j < m; ++j) {
				if(a[i] == a[j]) {
					return {};
				}
			}
		}
		for(int i = 0; i < m; ++i) {
			for(int j = i + 1; j < m; ++j) {
				if((a[i] & a[j]) == 0) {
					return {};
				}
			}
		}
		for(int i = 0; i < m; ++i) {
			for(int j = i + 1; j < m; ++j) {
				for(int k = j + 1; k < m; ++k) {
					if((a[i] & a[j] & a[k]) != 0) {
						return {};
					}
				}
			}
		}
		vector<vector<int> > bit;
		bit.resize(m);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < 60; ++j) {
				if(a[i] >> j & 1) {
					bool ok = true;
					for(int k = 0; k < m; ++k) {
						if(k != i && (a[k] >> j & 1)) {
							ok = false;
						}
					}
					if(ok) {
						bit[i].emplace_back(j);	
					}
				}
			}
		}
		for(int i = 0; i < m; ++i) {
			reverse(bit[i].begin(), bit[i].end());
		}
		vector<int> fbit;
		for(int i = 0; i < 60; ++i) {
			bool ok = true;
			for(long long v : a) {
				if(v & (1LL << i)) {
					ok = false;
				}
			}
			if(ok) {
				fbit.emplace_back(i);
			}
		}
		reverse(fbit.begin(), fbit.end());
		int sum = 0;
		for(int i = 0; i < n - m; ++i) {
			sum += i;
		}
		if(fbit.size() < sum) {
			return {};
		}
		vector<vector<int> > r;
		r.resize(n);
		for(int d = 0; d < n - m; ++d) {
			long long t = 0;
			for(int i = 0; i < m; ++i) {
				if(bit[i].empty()) {
					return {};
				}
				t |= 1LL << bit[i].back();
				bit[i].pop_back();
			}
			for(int i = m; i < m + d; ++i) {
				t |= 1LL << r[i].back();
				r[i].pop_back();
			}
			for(int i = 0; i < n - m - 1 - d; ++i) {
				t |= 1LL << fbit.back();
				if(fbit.empty()) {
					return {};
				}
				r[m + d].emplace_back(fbit.back());
				fbit.pop_back();
			}
			reverse(r[m + d].begin(), r[m + d].end());
			a.emplace_back(t);
		}
		sort(a.begin(), a.end());
		return a;
	}
}; 
