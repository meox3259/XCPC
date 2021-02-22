#include <bits/stdc++.h>

using namespace std;

int main() {
	int L;
	cin >> L;

	int h = -1;
	for (int i = 19; i >= 0; --i) {
		if (L >> i & 1) {
			h = i;
			break;
		}
	}

	vector<tuple<int, int, int> > ans;
    for (int i = 0; i < h; ++i) {
        ans.emplace_back(i, i + 1, 1 << i);
        ans.emplace_back(i, i + 1, 0);
    }

    for (int i = 0; i < h; ++i) {
        if (L >> i & 1) {
            L -= 1 << i;
            ans.emplace_back(i, h, L);
        }
    }

	cout << h + 1 << ' ' << ans.size() << '\n';
	for (auto [x, y, w] : ans) {
		cout << x + 1 << ' ' << y + 1 << ' ' << w << '\n';
	}

	return 0;
}
