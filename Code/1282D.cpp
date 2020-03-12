#include <bits/stdc++.h>
using namespace std;
int ask(string s) {
	cout << s << endl;
	int ret; scanf("%d", &ret);
	if(!ret) {
		exit(0);
	}
	return ret;
}
int main() {
	int N = 300;
	int tmp = ask(string(N, 'b'));
	int n = 2 * N - tmp - ask(string(N, 'a'));
	string ans = string(n, 'a');
	int tot = N - tmp;
	for(int i = 0; i < n - 1; ++i) {
		ans[i] = 'b';
		int tmp = ask(ans);
		if(tmp < tot) {
			tot = tmp;
		} else {
			ans[i] = 'a';
		}
	}
	if(tot) {
		ans[n - 1] = 'b';
	}
	ask(ans);
	return 0;
}
