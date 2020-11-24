#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int d, k;
		cin >> d >> k;

		for(int i = 0, j = 0; ;) {
			++i;
			if(1LL * i * k * i * k + 1LL * j * k * j * k > 1LL * d * d) {
				if((i + j) % 2 == 1) {
					cout << "Utkarsh" << '\n';
				} else {
					cout << "Ashish" << '\n';
				}
				break;
			}
			++j;
			if(1LL * i * k * i * k + 1LL * j * k * j * k > 1LL * d * d) {
				if((i + j) % 2 == 1) {
					cout << "Utkarsh" << '\n';
				} else {
					cout << "Ashish" << '\n';
				}
				break;
			}

		}
	}

	return 0;
}
