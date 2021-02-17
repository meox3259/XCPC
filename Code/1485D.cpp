#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int lcm = 1;
    for (int i = 1; i <= 16; ++i) {
        lcm = lcm * i / __gcd(lcm, i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (((i + j) & 1) ? lcm : lcm + a[i][j] * a[i][j] * a[i][j] * a[i][j]) << " \n"[j == m - 1];
        }
    }

    return 0;
}
