#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool odd = true;
    bool even = true;
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (s[i] < 'a' || s[i] > 'z') {
                odd = false;
            }
        } else {
            if (s[i] < 'A' || s[i] > 'Z') {
                even = false;
            }
        }
    }

    if (odd && even) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
