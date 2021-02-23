#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    if (k == 0) {
        cout << "Yes" << '\n';
        for (int i = 0; i < b; ++i) {
            cout << 1;
        }
        for (int i = 0; i < a; ++i) {
            cout << 0;
        }
        cout << '\n';
        for (int i = 0; i < b; ++i) {
            cout << 1;
        }
        for (int i = 0; i < a; ++i) {
            cout << 0;
        }
        cout << '\n';
        exit(0);
    }

    if (k > a + b - 2 || (k > 0 && b < 2) || (k > 0 && a < 1)) {
        cout << "No" << '\n';
        exit(0);
    }

    cout << "Yes" << '\n';

    if (k == 0) {
        for (int i = 0; i < b; ++i) {
            cout << 1;
        }
        for (int i = 0; i < a; ++i) {
            cout << 0;
        }
        cout << '\n';
        for (int i = 0; i < b; ++i) {
            cout << 1;
        }
        for (int i = 0; i < a; ++i) {
            cout << 0;
        }
        cout << '\n';
        exit(0);
    }

    vector<int> x(a + b);
    vector<int> y(a + b);

    int d = a - k; 
    int tot = b;

    x[0] = 1;
    y[0] = 1;
    x[1] = 1;
    y[k + 1] = 1;

    tot --;
    tot --;

    if (a < k) {
        for (int i = 0; i < k - a; ++i) {
            x[a + i + 1] = 1;
            y[a + i + 1] = 1;
            tot --;
        } 
    }

    for (int i = 0; i < tot; ++i) {
        x[a + b - 1 - i] = 1;
        y[a + b - 1 - i] = 1;
    }

    for (int i = 0; i < a + b; ++i) {
        cout << x[i];
    }
    cout << '\n';

    for (int i = 0; i < a + b; ++i) {
        cout << y[i];
    }
    cout << '\n';

    return 0;
}
