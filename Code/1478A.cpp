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

        vector<int> cnt(n + 1);
        for (int i : a) {
            cnt[i] ++;
        }

        cout << *max_element(cnt.begin(), cnt.end()) << '\n';
    }

    return 0;
}
