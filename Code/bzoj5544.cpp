#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans, top;
ll dp[105], st[105];
int main() { 
	scanf("%lld", &n);
	while(n) {
		st[++top] = n % 10;
		n /= 10;
	}
	dp[0] = 1;
	for(int i = 1; i <= top; ++i) {
		if(st[i] == 1) {
			int t = 10 + st[i - 1];
			ll mul = 0;
			for(int j = 0; j < 10; ++j) {
				if(t - j >= 0 && t - j < 10) {
					++mul;
				}
			}
			dp[i] += dp[i - 2] * mul;
		} 
		dp[i] += dp[i - 1] * (st[i] + 1);
	}
	printf("%lld\n", dp[top]);
	return 0;
}
