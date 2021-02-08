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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int cur = 0;
        int mark = -1;

        vector<int> id(n);
        iota(id.begin(), id.end(), 0);

        while (true) {
            cur ^= 1;
            sort(id.begin(), id.end(), [&] (int i, int j) {
                if (i == mark) {
                    return false;
                }
                if (j == mark) {
                    return true;
                }
                return a[i] > a[j];
            });

            if (mark == id[0] || a[id[0]] <= 0) {
                break;
            }
            a[id[0]] --;
            mark = id[0];
        }

        if (cur == 0) {
            cout << "T" << '\n';
        } else {
            cout << "HL" << '\n';
        }
    }

    return 0;
}
