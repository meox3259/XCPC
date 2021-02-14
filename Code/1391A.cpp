
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

        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " \n"[i == n - 1];
        }
    }

    return 0;
}
