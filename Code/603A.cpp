#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }

    int sum = 1;
    int tot = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            sum += 1;
        } else {
            tot += 1;
        }
    }

    cout << sum + min(tot, 2) << '\n';

    return 0;
}
