#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<vector<int> > b(n, vector<int> (n));

        if (n % 2 == 0) {
            int need = n / 2 - 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= need + need; ++j) {
                    b[i][(i + j + (i % 2 == 0)) % n] = ((j + i) % 2 == 0) ? 1 : -1;
                } 
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= n / 2; ++j) {
                    b[i][(i + j) % n] = 1; 
                }
                for (int j = n / 2 + 1; j < n; ++j) {
                    b[i][(i + j) % n] = -1; 
                }
            } 
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cout << b[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
