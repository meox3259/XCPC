#include <bits/stdc++.h>
using namespace std;
class fenwick {
	public:
		vector<int> a
		void add(int p, int d) {
			for( ; p < maxn; p += p & -p) {
				t[p] += d;
			}
		}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}
