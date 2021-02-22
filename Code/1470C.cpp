#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
    long long k;
	scanf("%d%lld", &n, &k);

	auto query = [&] (int x) {
		printf("? %d\n", x + 1);
		fflush(stdout);
		long long ret;
		scanf("%lld", &ret);
		return ret;
	};	

	int b = 371;
	int cur = 0;
	while (true) {
		long long v = query(cur);
		if (v != k) {
			if (v < k) {
				long long u = query(cur);
				while (true) {
					u = query(cur);
					if (u == k) {
						printf("! %d\n", cur + 1);
						fflush(stdout);
						exit(0);
					}
					cur = (cur + 1) % n;
				}
			} else {
				long long u = query(cur);
				while (true) {
					u = query(cur);
					if (u == k) {
						printf("! %d\n", cur + 1);
						fflush(stdout);
						exit(0);
					}
					cur = (cur - 1 + n) % n;
				}
			}
		}
		cur = (cur + b) % n;
	}

	return 0;
}
