#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;

	string ans = "";
	
	while(n) {
		n -= 1;	
		char c = (char)(n % 26 + 'a');
		ans += c;
		n /= 26;
	}

	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}
