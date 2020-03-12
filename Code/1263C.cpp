#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<int> ans;
		ans.clear();
		for(int i = 1, j = 0; i <= n; i = j + 1) {
			ans.push_back(n / i);
			j = n / (n / i);
		}
		ans.push_back(0);
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}
