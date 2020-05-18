#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	if(n * 2 > s) {
		cout << "NO" << '\n';
		exit(0);
	}
	cout << "YES" << '\n';
	for(int i = 0; i < n - 1; ++i) {
		cout << 2 << ' ';	
		s -= 2;
	}
	cout << s << '\n';
	cout << 1 << '\n';
	
	return 0;
}
