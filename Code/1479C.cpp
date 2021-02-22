#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    vector<tuple<int, int, int> > ans;
    for (int i = 1; i < 22; ++i) {
        for (int j = i + 1; j < 22; ++j) {
            ans.emplace_back(i, j, 1 << i - 1);
        }
    }

    for (int i = 1; i <= 22; ++i) {
        ans.emplace_back(0, i, L);
    }

    R -= L;
    for (int i = 1; i < 22; ++i) {
        if (R & (1 << i - 1)) {
            R ^= 1 << i - 1;
            ans.emplace_back(i, 22, R + 1);
        }
    }

    cout << "YES" << '\n';
    cout << 23 << ' ' << ans.size() << '\n';
    for (auto [x, y, w] : ans) {
        cout << x + 1 << ' ' << y + 1 << ' ' << w << '\n';
    }

    return 0;
}
