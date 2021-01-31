#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s, d;
    cin >> n >> s >> d;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (x[i] < s && y[i] > d) {
            ok = true;
        }
    }

    if (ok) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
