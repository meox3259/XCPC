#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while (a > 0 || b > 0) {
        if (c == 0) {
            a --;
        } else {
            b --;
        }
        c ^= 1;
    }

    if (c == 1) {
        cout << "Takahashi" << '\n';
    } else {
        cout << "Aoki" << '\n';
    }

    return 0;
}
