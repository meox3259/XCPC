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
        if (n < 31) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n'; 
            int a = n - 30;
            int b = 6;
            int c = 10;
            int d = 14;
            if (a == b || a == c || a == d) {
                a --;
                d ++;
            }
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; 
        }
    }

    return 0;
}
