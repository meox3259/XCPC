#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, r;
	cin >> n >> r;
	if(n <= 10) {
		r += (10 - n) * 100; 
	}
	cout << r << '\n';
	return 0;
}
