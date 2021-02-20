#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        vector<int> bit;
        long long tmp = n;
        if (tmp == 0) {
            bit.emplace_back(0);
        }
        while (tmp) {
            bit.emplace_back(tmp % 10);
            tmp /= 10;
        }
        sort(bit.begin(), bit.end());
        int m = bit.size();
        long long f = 0;
        for (int j = m - 1; j >= 0; --j) {
            f = f * 10 + bit[j];
        }
        long long g = 0;
        for (int j = 0; j < m; ++j) {
            g = g * 10 + bit[j];
        }
        n = f - g;
    }

    cout << n << '\n';

    return 0;
}
