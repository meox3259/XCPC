#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int x, y;
        cin >> y >> x;

        string s;
        cin >> s;

        int lowx = 0;
        int highx = 0;
        int lowy = 0;
        int highy = 0;
        for (char c : s) {
            if (c == 'U') {
                highx ++;
            } 
            if (c == 'D') {
                lowx ++;
            }
            if (c == 'L') {
                lowy ++;
            }
            if (c == 'R') {
                highy ++;
            }
        }

        if (-lowx <= x && x <= highx && -lowy <= y && y <= highy) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
