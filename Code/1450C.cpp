#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        int k = 0;
        vector<vector<int> > cnt(2, vector<int> (3));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'O') {
                    cnt[0][(i + j) % 3] ++;
                    k ++;
                } 
                if (s[i][j] == 'X') {
                    cnt[1][(i + j) % 3] ++;
                    k ++;
                }
            }
        }

        int p = -1;
        for (int i = 0; i < 3; ++i) {
            if (cnt[0][i] + cnt[1][(i + 1) % 3] <= k / 3) {
                p = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == 'O' && (i + j) % 3 == p) {
                    s[i][j] = 'X';
                } else if (s[i][j] == 'X' && (i + j) % 3 == (p + 1) % 3) {
                    s[i][j] = 'O';
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << s[i] << '\n';
        }
    }

    return 0;
}
